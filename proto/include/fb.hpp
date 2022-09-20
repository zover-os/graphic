#ifndef ZOVER__GRAPHIC__PROTO__
#define ZOVER__GRAPHIC__PROTO__

#include <linux/fb.h>

#include <std.h>

tuple<int, int, int, int, int, int*> open_fb(const char* fbdev);
void clearscreen_fb(void* fbdata, int fb_size);
void unload_fb(int* fbdata, int fbsize, int fb_fd);

#endif