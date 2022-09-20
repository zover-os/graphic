#ifndef ZOVER__GRAPHIC__PROTO__FB__
#define ZOVER__GRAPHIC__PROTO__FB__

#include <linux/fb.h>

#include <std.hpp>

struct fb{
    int width;
    int height;
    int bpp;
    int size;
    int fd;
    int* data;
};

fb open_fb(const char* fbdev);
void clearscreen_fb(struct fb);
void unload_fb(struct fb);

#endif