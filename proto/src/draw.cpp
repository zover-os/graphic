#include <draw.hpp>

void draw(pos position, pixel pix, fb framebuffer){  
    int offset =
        //position.x * framebuffer.vinfo.bits_per_pixel/8 +
        //    position.y*framebuffer.finfo.line_length;
        (position.y*framebuffer.vinfo.xres_virtual+position.x) ;
   // cout << offset << endl;
    //framebuffer.data[ offset    ] = pix.b;
    //framebuffer.data[ offset + 1] = pix.g;
    //framebuffer.data[ offset + 128] = pix.r; 
    //framebuffer.data[ offset + 3] = 0;
    int r,g,b,a;
    r=pix.r;
    g=pix.g;
    b=pix.b;
    a=0;
    uint32_t pixel =(r<< framebuffer.vinfo.red.offset)   |
                    (g<< framebuffer.vinfo.green.offset) |
                    (b<< framebuffer.vinfo.blue.offset)  |
                    (a<< framebuffer.vinfo.transp.offset);
    *((uint32_t*) (framebuffer.data + offset)) = pixel;
}
