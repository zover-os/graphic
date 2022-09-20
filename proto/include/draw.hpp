#ifndef ZOVER__GRAPHIC__PROTO__DRAW
#define ZOVER__GRAPHIC__PROTO__DRAW

#include <fb.hpp>

struct pos
{
    int x;
    int y;
};
struct pixel
{
    int b;
    int g;
    int r;
};

void draw(struct pos, struct pixel, struct fb);

#endif