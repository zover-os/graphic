#ifndef ZOVER__GRAPHIC__PROTO__FB__
#define ZOVER__GRAPHIC__PROTO__FB__

#include <linux/fb.h>

#include <std.hpp>

class fb{
    public:
        int width;
        int height;
        int bpp;
        int size;
        int fd;
        int* data;
        fb(int width, int height, int bpp, int size, int fd, int* data){
            this->width=width;
            this->height=height;
            this->bpp=bpp;
            this->size=size;
            this->fd=fd;
            this->data=data;
        }
};

fb open_fb(const char* fbdev);
void clearscreen_fb(fb);
void unload_fb(fb);

#endif