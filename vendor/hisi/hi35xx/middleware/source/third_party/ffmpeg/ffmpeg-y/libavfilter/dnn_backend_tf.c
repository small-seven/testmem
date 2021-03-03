#include "dnn_backend_tf.h"
#include "dnn_backend_native.h"
#include "libavformat/avio.h"
#include "libavutil/avassert.h"
#include <tensorflow/c/c_api.h>
typedef struct TFModel{
    TF_Graph *graph;
    TF_Session *session;
    TF_Status *status;
    TF_Output input;
    TF_Tensor *input_tensor;
    TF_Output *outputs;
    TF_Tensor **output_tensors;
    uint32_t nb_output;
} TFModel;
#define NAME_BUFFER_SIZE 256
#define CLEANUP_ON_ERROR(tf_model) \
