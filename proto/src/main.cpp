#include <std.h>
#include <fb.h>

int width, height, bpp, fb_size, fb_fd;
int* fbdata;

int main(){
    const char* fbdev = "/dev/fb0";
    tie(width, height, bpp, fb_size, fb_fd, fbdata) = open_fb(fbdev);
    clearscreen_fb(fbdata, fb_size);
    for (int y=1; y<width; y++){
        for (int x=1; x<height; x++){
            int offset = ((int)(x*width+y));
            fbdata[offset+0]=255;
            fbdata[offset+1]=0;
            fbdata[offset+2]=150;
        }
    }
    unload_fb(fbdata, fb_size, fb_fd);
    return 0;
}
