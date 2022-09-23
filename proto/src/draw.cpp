#include <draw.hpp>

void draw(pos position, pixel pix, fb framebuffer){  
    int offset = 
        (position.x+framebuffer.vinfo.xoffset) *
        (framebuffer.vinfo.bits_per_pixel/8) +
        (position.y+framebuffer.vinfo.yoffset) *
        framebuffer.finfo.line_length;
   // cout << offset << endl;
    framebuffer.data[ offset    ] = pix.b;
    framebuffer.data[ offset + 1] = pix.g;
    framebuffer.data[ offset + 2] = pix.r; 
    framebuffer.data[ offset + 3] = 0;
}
