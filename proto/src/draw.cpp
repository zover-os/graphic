#include <draw.hpp>

void draw(pos position, pixel pix, fb framebuffer){
    int offset =  position.x * framebuffer.vinfo.bits_per_pixel/8 +
        position.y * framebuffer.finfo.line_length;
    framebuffer.data[offset+2] = pix.r;
    framebuffer.data[offset+1] = pix.g;
    framebuffer.data[offset+0] = pix.b;
}
