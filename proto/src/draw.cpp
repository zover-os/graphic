#include <draw.hpp>

void draw(struct pos position, struct pixel pix, struct fb framebuffer){
    int offset = ((int)(position.x*framebuffer.width+position.y));
    framebuffer.data[offset+0] = pix.b;
    framebuffer.data[offset+1] = pix.g;
    framebuffer.data[offset+2] = pix.r;
}