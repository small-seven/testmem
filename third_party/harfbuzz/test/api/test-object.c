#include "hb-test.h"
typedef void     *(*create_func_t)         (void);
typedef void     *(*reference_func_t)      (void *obj);
typedef void      (*destroy_func_t)        (void *obj);
typedef hb_bool_t (*set_user_data_func_t)  (void *obj, hb_user_data_key_t *key, void *data, hb_destroy_func_t destroy, hb_bool_t replace);
typedef void *    (*get_user_data_func_t)  (void *obj, hb_user_data_key_t *key);
typedef void      (*make_immutable_func_t) (void *obj);
typedef hb_bool_t (*is_immutable_func_t)   (void *obj);

typedef struct {
  create_func_t          create;
  create_func_t          create_from_inert;
  create_func_t          get_empty;
  reference_func_t       reference;
  destroy_func_t         destroy;
  set_user_data_func_t   set_user_data;
  get_user_data_func_t   get_user_data;
  make_immutable_func_t  make_immutable;
  is_immutable_func_t    is_immutable;
  const char            *name;
} object_t;
#define OBJECT_WITHOUT_IMMUTABILITY(name) \
#define OBJECT_WITH_IMMUTABILITY(name) \
#undef OBJECT
#define MAGIC0 0x12345678
#define MAGIC1 0x76543210
typedef struct {
  int value;
  gboolean freed;
} data_t;
typedef struct {
  const object_t *klass;
  void *object;
  hb_user_data_key_t key;
} deadlock_test_t;
