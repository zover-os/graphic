#ifndef ZOVER__GRAPHIC__PROTO__FB__
#define ZOVER__GRAPHIC__PROTO__FB__

#include <linux/fb.h>

#include <std.hpp>

class fb{
    public:
        struct fb_fix_screeninfo finfo;
        struct fb_var_screeninfo vinfo;
        int size;
        int fd;
        int* data;
        fb(fb_fix_screeninfo finfo, fb_var_screeninfo vinfo, int fb_size, int fd, int* data){
            this->finfo=finfo;
            this->vinfo=vinfo;
            this->size=fb_size;
            this->fd=fd;
            this->data=data;
        }
};

fb open_fb(const char* fbdev);
void clearscreen_fb(fb);
void unload_fb(fb);

#endif