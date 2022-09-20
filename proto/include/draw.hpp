#ifndef ZOVER__GRAPHIC__PROTO__DRAW
#define ZOVER__GRAPHIC__PROTO__DRAW

#include <fb.hpp>

class pos
{
    public:
        int x;
        int y;
        pos(int x, int y){
            this->x=x;
            this->y=y;
        };
};
class pixel
{
    public:
        int r;
        int g;
        int b;
        pixel(int r, int g, int b){
            this->r=r;
            this->g=g;
            this->b=b;
        }
};

void draw(pos, pixel, fb);

#endif