#include <std.hpp>
#include <fb.hpp>
#include <draw.hpp>

int main(){
    const char* fbdev = "/dev/fb0";
    fb framebuffer = open_fb(fbdev);
    //clearscreen_fb(framebuffer);
    for (int y=1;y<framebuffer.vinfo.yres;y++){
        for (int x=1;x<framebuffer.finfo.line_length;x++){
            pos position=pos(x,y);
            pixel pix=pixel(240, 240, 125);
            draw(position, pix, framebuffer);
        }
    }
    
    unload_fb(framebuffer);
    return 0;
}
