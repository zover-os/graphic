#include <fb.h>

tuple<int, int, int, int, int, int*> open_fb(const char* fbdev){
    int fb_fd = open(fbdev, O_RDWR);
    if (fb_fd<=0){
        cout << "Error: can't open framebuffer";
        exit(1);
    }
    struct fb_var_screeninfo vinfo;
    ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);

    int fb_width = vinfo.xres;
    int fb_height = vinfo.yres;
    int fb_bpp = vinfo.bits_per_pixel;
    int fb_bytes = fb_bpp / 8;
    int fb_size = fb_width * fb_height * fb_bytes;
    void* fbdata = mmap(0, fb_size,
        PROT_READ | PROT_WRITE,
        MAP_SHARED, fb_fd,
        0
    );
    return {fb_width, fb_height, fb_bpp, fb_size, fb_fd,(int*)fbdata};
}

void clearscreen_fb(void* fbdata, int fb_size){
    memset(fbdata, 0, (size_t)fb_size);
}

void unload_fb(int* fbdata, int fb_size, int fb_fd){
    munmap(fbdata, fb_size);
    close(fb_fd);
}