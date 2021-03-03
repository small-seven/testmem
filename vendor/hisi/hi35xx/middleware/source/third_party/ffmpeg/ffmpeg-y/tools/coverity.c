* - Modeling doesn't need full structs and typedefs. Rudimentary structs
* and similar types are sufficient.
* - An uninitialized local variable signifies that the variable could be
* any value.
*
* The model file must be uploaded by an admin in the analysis settings of
* https://scan.coverity.com/projects/54
*
* above text is based on https://github.com/qemu/qemu/blob/master/scripts/coverity-model.c
*/

#define NULL (void *)0

// Based on https://scan.coverity.com/models
void *av_malloc(size_t size) {
    int has_memory;
    __coverity_negative_sink__(size);
    if (has_memory) {
        void *ptr = __coverity_alloc__(size);
        __coverity_mark_as_uninitialized_buffer__(ptr);
        __coverity_mark_as_afm_allocated__(ptr, "av_free");
         return ptr;
    } else {
