typedef struct my_custom_pbuf
{
   struct pbuf_custom p;
   void* dma_descriptor;
} my_custom_pbuf_t;
