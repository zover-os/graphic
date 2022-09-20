#include <draw.hpp>

void draw(pos position, pixel pix, fb framebuffer){
    int offset = ((int)(position.x*framebuffer.width+position.y));
    framebuffer.data[offset+0] = pix.b;
    framebuffer.data[offset+1] = pix.g;
    framebuffer.data[offset+2] = pix.r;
}