#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "config.h"
#if HAVE_WINDOWS_H
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#if HAVE_OPENGL_GL3_H
#include <OpenGL/gl3.h>
#elif HAVE_ES2_GL_H
#include <ES2/gl.h>
#else
#include <GL/gl.h>
#include <GL/glext.h>
#endif
#if HAVE_GLXGETPROCADDRESS
#include <GL/glx.h>
#endif
#if CONFIG_SDL2
#include <SDL.h>
#endif
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavformat/avformat.h"
#include "libavformat/internal.h"
#include "libavdevice/avdevice.h"
#include "opengl_enc_shaders.h"
#ifndef APIENTRY
#define APIENTRY
#endif
#if defined(GL_RED)
#define FF_GL_RED_COMPONENT GL_RED
#elif defined(GL_LUMINANCE)
#define FF_GL_RED_COMPONENT GL_LUMINANCE
#else
#define FF_GL_RED_COMPONENT 0x1903; //GL_RED
#endif
#define FF_GL_UNSIGNED_BYTE_3_3_2 0x8032
#define FF_GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define FF_GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define FF_GL_UNPACK_ROW_LENGTH          0x0CF2
#define FF_GL_ARRAY_BUFFER                0x8892
#define FF_GL_ELEMENT_ARRAY_BUFFER        0x8893
#define FF_GL_STATIC_DRAW                 0x88E4
#define FF_GL_FRAGMENT_SHADER             0x8B30
#define FF_GL_VERTEX_SHADER               0x8B31
#define FF_GL_COMPILE_STATUS              0x8B81
#define FF_GL_LINK_STATUS                 0x8B82
#define FF_GL_INFO_LOG_LENGTH             0x8B84
typedef void   (APIENTRY *FF_PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void   (APIENTRY *FF_PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef void   (APIENTRY *FF_PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
typedef void   (APIENTRY *FF_PFNGLBUFFERDATAPROC) (GLenum target, ptrdiff_t size, const GLvoid *data, GLenum usage);
typedef void   (APIENTRY *FF_PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef GLint  (APIENTRY *FF_PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const char *name);
typedef void   (APIENTRY *FF_PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void   (APIENTRY *FF_PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, uintptr_t pointer);
typedef GLint  (APIENTRY *FF_PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const char *name);
typedef void   (APIENTRY *FF_PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void   (APIENTRY *FF_PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void   (APIENTRY *FF_PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef GLuint (APIENTRY *FF_PFNGLCREATEPROGRAMPROC) (void);
typedef void   (APIENTRY *FF_PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void   (APIENTRY *FF_PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void   (APIENTRY *FF_PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void   (APIENTRY *FF_PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
typedef void   (APIENTRY *FF_PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, char *infoLog);
typedef void   (APIENTRY *FF_PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef GLuint (APIENTRY *FF_PFNGLCREATESHADERPROC) (GLenum type);
typedef void   (APIENTRY *FF_PFNGLDELETESHADERPROC) (GLuint shader);
typedef void   (APIENTRY *FF_PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef void   (APIENTRY *FF_PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const char* *string, const GLint *length);
typedef void   (APIENTRY *FF_PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
typedef void   (APIENTRY *FF_PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, char *infoLog);

typedef struct FFOpenGLFunctions {
    FF_PFNGLACTIVETEXTUREPROC glActiveTexture;                     //Require GL ARB multitexture
    FF_PFNGLGENBUFFERSPROC glGenBuffers;                           //Require GL_ARB_vertex_buffer_object
    FF_PFNGLDELETEBUFFERSPROC glDeleteBuffers;                     //Require GL_ARB_vertex_buffer_object
    FF_PFNGLBUFFERDATAPROC glBufferData;                           //Require GL_ARB_vertex_buffer_object
    FF_PFNGLBINDBUFFERPROC glBindBuffer;                           //Require GL_ARB_vertex_buffer_object
    FF_PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;             //Require GL_ARB_vertex_shader
    FF_PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray; //Require GL_ARB_vertex_shader
    FF_PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;         //Require GL_ARB_vertex_shader
    FF_PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;           //Require GL_ARB_shader_objects
    FF_PFNGLUNIFORM1FPROC glUniform1f;                             //Require GL_ARB_shader_objects
    FF_PFNGLUNIFORM1IPROC glUniform1i;                             //Require GL_ARB_shader_objects
    FF_PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;               //Require GL_ARB_shader_objects
    FF_PFNGLCREATEPROGRAMPROC glCreateProgram;                     //Require GL_ARB_shader_objects
    FF_PFNGLDELETEPROGRAMPROC glDeleteProgram;                     //Require GL_ARB_shader_objects
    FF_PFNGLUSEPROGRAMPROC glUseProgram;                           //Require GL_ARB_shader_objects
    FF_PFNGLLINKPROGRAMPROC glLinkProgram;                         //Require GL_ARB_shader_objects
    FF_PFNGLGETPROGRAMIVPROC glGetProgramiv;                       //Require GL_ARB_shader_objects
    FF_PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;             //Require GL_ARB_shader_objects
    FF_PFNGLATTACHSHADERPROC glAttachShader;                       //Require GL_ARB_shader_objects
    FF_PFNGLCREATESHADERPROC glCreateShader;                       //Require GL_ARB_shader_objects
    FF_PFNGLDELETESHADERPROC glDeleteShader;                       //Require GL_ARB_shader_objects
    FF_PFNGLCOMPILESHADERPROC glCompileShader;                     //Require GL_ARB_shader_objects
    FF_PFNGLSHADERSOURCEPROC glShaderSource;                       //Require GL_ARB_shader_objects
    FF_PFNGLGETSHADERIVPROC glGetShaderiv;                         //Require GL_ARB_shader_objects
    FF_PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;               //Require GL_ARB_shader_objects
} FFOpenGLFunctions;
#define OPENGL_ERROR_CHECK(ctx) \
typedef struct OpenGLVertexInfo
{
    float x, y, z;    ///<Position
    float s0, t0;     ///<Texture coords
} OpenGLVertexInfo;
typedef struct OpenGLContext {
    AVClass *class;                    ///< class for private options

#if CONFIG_SDL2
    SDL_Window *window;
    SDL_GLContext glcontext;
#endif
    FFOpenGLFunctions glprocs;

    int inited;                        ///< Set to 1 when write_header was successfully called.
    uint8_t background[4];             ///< Background color
    int no_window;                     ///< 0 for create default window
    char *window_title;                ///< Title of the window

    /* OpenGL implementation limits */
    GLint max_texture_size;            ///< Maximum texture size
    GLint max_viewport_width;          ///< Maximum viewport size
    GLint max_viewport_height;         ///< Maximum viewport size
    int non_pow_2_textures;            ///< 1 when non power of 2 textures are supported
    int unpack_subimage;               ///< 1 when GL_EXT_unpack_subimage is available

    /* Current OpenGL configuration */
    GLuint program;                    ///< Shader program
    GLuint vertex_shader;              ///< Vertex shader
    GLuint fragment_shader;            ///< Fragment shader for current pix_pmt
    GLuint texture_name[4];            ///< Textures' IDs
    GLuint index_buffer;               ///< Index buffer
    GLuint vertex_buffer;              ///< Vertex buffer
    OpenGLVertexInfo vertex[4];        ///< VBO
    GLint projection_matrix_location;  ///< Uniforms' locations
    GLint model_view_matrix_location;
    GLint color_map_location;
    GLint chroma_div_w_location;
    GLint chroma_div_h_location;
    GLint texture_location[4];
    GLint position_attrib;             ///< Attibutes' locations
    GLint texture_coords_attrib;

    GLfloat projection_matrix[16];     ///< Projection matrix
    GLfloat model_view_matrix[16];     ///< Modev view matrix
    GLfloat color_map[16];             ///< RGBA color map matrix
    GLfloat chroma_div_w;              ///< Chroma subsampling w ratio
    GLfloat chroma_div_h;              ///< Chroma subsampling h ratio

    /* Stream information */
    GLenum format;
    GLenum type;
    int width;                         ///< Stream width
    int height;                        ///< Stream height
    enum AVPixelFormat pix_fmt;        ///< Stream pixel format
    int picture_width;                 ///< Rendered width
    int picture_height;                ///< Rendered height
    int window_width;
    int window_height;
} OpenGLContext;
#if CONFIG_SDL2
#define LOAD_OPENGL_FUN(name, type) \
#undef LOAD_OPENGL_FUN
#endif /* CONFIG_SDL2 */
#if defined(__APPLE__)
#if CONFIG_SDL2
#endif
#else
#if HAVE_GLXGETPROCADDRESS
#define SelectedGetProcAddress glXGetProcAddress
#elif HAVE_WGLGETPROCADDRESS
#define SelectedGetProcAddress wglGetProcAddress
#endif
#define LOAD_OPENGL_FUN(name, type) \
#if CONFIG_SDL2
#endif
#undef SelectedGetProcAddress
#undef LOAD_OPENGL_FUN
#endif
#if defined(GL_ES_VERSION_2_0)
#else
#endif
#define FILL_COMPONENT(i) { \
#undef FILL_COMPONENT
#if CONFIG_SDL2
#else
#endif
#if CONFIG_SDL2
#endif
#if CONFIG_SDL2
#endif
#define LOAD_TEXTURE_DATA(comp_index, sub)                                                  \
#if CONFIG_SDL2
#endif
#if CONFIG_SDL2
#endif
#define OFFSET(x) offsetof(OpenGLContext, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
