#include "proc_fs.h"
#include <stdio.h>
#include <linux/errno.h>
#include <linux/module.h>
#include "internal.h"
#include "user_copy.h"
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PROC_ROOTDIR_NAMELEN   5
#define PROC_INUSE             2
static struct ProcDirEntry *ProcAllocNode(struct ProcDirEntry **parent, const char *name, mode_t mode)
{
    struct ProcDirEntry *pn = NULL;
    const char *lastName = NULL;
    int ret;

    if ((name == NULL) || (strlen(name) == 0) || (procfsInit == false)) {
        return pn;
    }

    if (CheckProcName(name, parent, &lastName) != 0) {
        return pn;
    }

    if (strlen(lastName) > MAX_NAMELEN) {
        return pn;
    }

    if ((S_ISDIR((*parent)->mode) == 0) || (strchr(lastName, '/'))) {
        return pn;
    }

    pn = (struct ProcDirEntry *)malloc(sizeof(struct ProcDirEntry));
    if (pn == NULL) {
        return NULL;
    }

    if ((mode & S_IALLUGO) == 0) {
        mode |= S_IRUSR | S_IRGRP | S_IROTH;
    }

    (void)memset_s(pn, sizeof(struct ProcDirEntry), 0, sizeof(struct ProcDirEntry));
    pn->nameLen = strlen(lastName);
    pn->mode = mode;
    ret = memcpy_s(pn->name, sizeof(pn->name), lastName, strlen(lastName) + 1);
    if (ret != EOK) {
        free(pn);
        return NULL;
    }

    pn->pf = (struct ProcFile *)malloc(sizeof(struct ProcFile));
    if (pn->pf == NULL) {
        free(pn);
        return NULL;
    }
    (void)memset_s(pn->pf, sizeof(struct ProcFile), 0, sizeof(struct ProcFile));
    pn->pf->pPDE = pn;
    ret = memcpy_s(pn->pf->name, sizeof(pn->pf->name), pn->name, pn->nameLen + 1);
    if (ret != EOK) {
        free(pn->pf);
        free(pn);
        return NULL;
    }

    atomic_set(&pn->count, 1);
    spin_lock_init(&pn->pdeUnloadLock);
    return pn;
}
static void ProcDetachNode(struct ProcDirEntry *pn)
{
    struct ProcDirEntry *parent = pn->parent;
    struct ProcDirEntry **iter = NULL;

    if (parent == NULL) {
        PRINT_ERR("%s(): node has no parent", __FUNCTION__);
        return;
    }

    iter = &parent->subdir;
    while (*iter != NULL) {
        if (*iter == pn) {
            *iter = pn->next;
            break;
        }
        iter = &(*iter)->next;
    }
    pn->parent = NULL;
}
static struct ProcDirEntry *ProcCreateDir(struct ProcDirEntry *parent, const char *name,
                                          const struct ProcFileOperations *procFileOps, mode_t mode)
{
    struct ProcDirEntry *pn = NULL;
    int ret;

    pn = ProcAllocNode(&parent, name, S_IFDIR | mode);
    if (pn == NULL) {
        return pn;
    }
    pn->procFileOps = procFileOps;
    ret = ProcAddNode(parent, pn);
    if (ret != 0) {
        free(pn->pf);
        free(pn);
        return NULL;
    }

    return pn;
}
static struct ProcDirEntry *ProcCreateFile(struct ProcDirEntry *parent, const char *name,
                                           const struct ProcFileOperations *procFileOps, mode_t mode)
{
    struct ProcDirEntry *pn = NULL;
    int ret;

    pn = ProcAllocNode(&parent, name, S_IFREG | mode);
    if (pn == NULL) {
        return pn;
    }

    pn->procFileOps = procFileOps;
    ret = ProcAddNode(parent, pn);
    if (ret != 0) {
        free(pn->pf);
        free(pn);
        return NULL;
    }

    return pn;
}
struct ProcDirEntry *CreateProcEntry(const char *name, mode_t mode, struct ProcDirEntry *parent)
{
    struct ProcDirEntry *pde = NULL;

    if (S_ISDIR(mode)) {
        pde = ProcCreateDir(parent, name, NULL, mode);
    } else {
        pde = ProcCreateFile(parent, name, NULL, mode);
    }
    return pde;
}
static void FreeProcEntry(struct ProcDirEntry *entry)
{
    if (entry == NULL) {
        return;
    }
    if (entry->pf != NULL) {
        free(entry->pf);
        entry->pf = NULL;
    }
    free(entry);
}
void ProcFreeEntry(struct ProcDirEntry *pn)
{
    if (atomic_dec_and_test(&pn->count))
        FreeProcEntry(pn);
}
static void RemoveProcEntryTravalsal(struct ProcDirEntry *pn)
{
    if (pn == NULL) {
        return;
    }
    RemoveProcEntryTravalsal(pn->next);
    RemoveProcEntryTravalsal(pn->subdir);

    ProcFreeEntry(pn);
}
void RemoveProcEntry(const char *name, struct ProcDirEntry *parent)
{
    struct ProcDirEntry *pn = NULL;
    const char *lastName = name;

    if ((name == NULL) || (strlen(name) == 0) || (procfsInit == false)) {
        return;
    }

    if (CheckProcName(name, &parent, &lastName) != 0) {
        return;
    }

    spin_lock(&procfsLock);

    pn = ProcFindNode(parent, lastName);
    if (pn == NULL) {
        PRINT_ERR("Error:name '%s' not found!\n", name);
        spin_unlock(&procfsLock);
        return;
    }
    ProcDetachNode(pn);

    spin_unlock(&procfsLock);

    RemoveProcEntryTravalsal(pn->subdir);
    ProcFreeEntry(pn);
}
struct ProcDirEntry *ProcCreateData(const char *name, mode_t mode, struct ProcDirEntry *parent,
                                    const struct ProcFileOperations *procFileOps, void *data)
{
    struct ProcDirEntry *pde = CreateProcEntry(name, mode, parent);
    if (pde != NULL) {
        if (procFileOps != NULL) {
            pde->procFileOps = procFileOps;
        }
        pde->data = data;
    }
    return pde;
}
struct ProcDirEntry *ProcCreate(const char *name, mode_t mode, struct ProcDirEntry *parent,
                                const struct ProcFileOperations *procFileOps)
{
    return ProcCreateData(name, mode, parent, procFileOps, NULL);
}
