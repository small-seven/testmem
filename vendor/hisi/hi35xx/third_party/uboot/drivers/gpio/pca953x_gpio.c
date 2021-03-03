#include <common.h>
#include <errno.h>
#include <dm.h>
#include <fdtdec.h>
#include <i2c.h>
#include <malloc.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <dt-bindings/gpio/gpio.h>
#define PCA953X_INPUT           0
#define PCA953X_OUTPUT          1
#define PCA953X_INVERT          2
#define PCA953X_DIRECTION       3
#define PCA_GPIO_MASK           0x00FF
#define PCA_INT                 0x0100
#define PCA953X_TYPE            0x1000
#define PCA957X_TYPE            0x2000
#define PCA_TYPE_MASK           0xF000
#define PCA_CHIP_TYPE(x)        ((x) & PCA_TYPE_MASK)
#define MAX_BANK 5
#define BANK_SZ 8
#define OF_953X(__nrgpio, __int) (ulong)(__nrgpio | PCA953X_TYPE | __int)
#define OF_957X(__nrgpio, __int) (ulong)(__nrgpio | PCA957X_TYPE | __int)
