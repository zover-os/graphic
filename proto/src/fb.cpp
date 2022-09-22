#include <fb.hpp>

fb open_fb(const char* fbdev){
    int fb_fd = open(fbdev, O_RDWR);
    if (fb_fd<=0){
        cout << "Error: can't open framebuffer";
        exit(1);
    }
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);
    ioctl(fb_fd, FBIOGET_FSCREENINFO, &finfo);
    int fb_size = vinfo.yres_virtual * finfo.line_length;
    void* fbdata = mmap(0, fb_size,
        PROT_READ | PROT_WRITE,
        MAP_SHARED, fb_fd,
        0
    );
    return fb(finfo, vinfo, fb_size, fb_fd, (int*)fbdata);
}

void clearscreen_fb(fb framebuffer){
    memset(framebuffer.data, 0, (size_t)framebuffer.size);
}

void unload_fb(fb framebuffer){
    munmap(framebuffer.data, framebuffer.size);
    close(framebuffer.fd);
}