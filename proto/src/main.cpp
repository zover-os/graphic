#include <std.hpp>
#include <fb.hpp>
#include <draw.hpp>

int main(){
    const char* fbdev = "/dev/fb0";
    fb framebuffer = open_fb(fbdev);
    clearscreen_fb(framebuffer);
    for (int y=0;y<framebuffer.width;y++){
        for (int x=0;x<framebuffer.height;x++){
            struct pos position;
            position.x=x;
            position.y=y;
            struct pixel pix;
            pix.b=x/(y+1)*x*y%256;
            pix.r=y/(x+1)*x*y%256;
            pix.g=(x+y)%256;
            draw(position, pix, framebuffer);
        }
    }
    
    unload_fb(framebuffer);
    return 0;
}
