#include <fb.hpp>

fb open_fb(const char* fbdev){
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
    fb _fb;
    _fb.width=fb_width;
    _fb.height=fb_height;
    _fb.bpp=fb_bpp;
    _fb.size=fb_size;
    _fb.fd=fb_fd;
    _fb.data=(int*)fbdata;
    return _fb;
}

void clearscreen_fb(struct fb framebuffer){
    memset(framebuffer.data, 0, (size_t)framebuffer.size);
}

void unload_fb(struct fb framebuffer){
    munmap(framebuffer.data, framebuffer.size);
    close(framebuffer.fd);
}