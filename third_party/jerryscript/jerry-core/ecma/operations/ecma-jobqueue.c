#include "ecma-function-object.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-jobqueue.h"
#include "ecma-objects.h"
#include "ecma-promise-object.h"
#include "jcontext.h"
#if ENABLED (JERRY_ES2015_BUILTIN_PROMISE)
typedef struct
{
  ecma_value_t reaction; /**< the PromiseReaction */
  ecma_value_t argument; /**< argument for the reaction */
} ecma_job_promise_reaction_t;
typedef struct
{
  ecma_value_t promise; /**< promise to be resolved */
  ecma_value_t thenable; /**< thenbale object */
  ecma_value_t then; /**< 'then' function */
} ecma_job_promise_resolve_thenable_t;
#endif /* ENABLED (JERRY_ES2015_BUILTIN_PROMISE) */
