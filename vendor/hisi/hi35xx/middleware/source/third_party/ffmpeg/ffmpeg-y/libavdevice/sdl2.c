#include <SDL.h>
#include <SDL_thread.h>
#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/time.h"
#include "avdevice.h"
typedef struct {
    AVClass *class;
    SDL_Window *window;
    SDL_Renderer *renderer;
    char *window_title;
    int window_width, window_height;  /**< size of the window */
    int window_x, window_y;           /**< position of the window */
    int window_fullscreen;
    int window_borderless;
    int enable_quit_action;

    SDL_Texture *texture;
    int texture_fmt;
    SDL_Rect texture_rect;

    int inited;
} SDLContext;
#if HAVE_BIGENDIAN
#else
#endif
#define OFFSET(x) offsetof(SDLContext,x)
