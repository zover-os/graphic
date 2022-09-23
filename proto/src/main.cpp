#include <std.hpp>
#include <fb.hpp>
#include <draw.hpp>

int main(){
    const char* fbdev = "/dev/fb0";
    fb framebuffer = open_fb(fbdev);
    //clearscreen_fb(framebuffer);
    //cout << framebuffer.vinfo.bits_per_pixel;
    for (int y=1;y<framebuffer.vinfo.yres_virtual;y++){
        for (int x=0;x<framebuffer.vinfo.xres_virtual;x++){
            pos position=pos(x,y);
            pixel pix=pixel(240, 128, 1);
            draw(position, pix, framebuffer);
        }
    }

    unload_fb(framebuffer);
    return 0;
}
