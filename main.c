#include <stdio.h>
#include "bmp.c"

int main(void) {
    Image img = load_bmp("/Users/akabynda/CLionProjects/cut&rotate/airplane.bmp");
    img = crop(img, 100, 100, 100, 100);
    img = rotate(img);
    save_bmp("/Users/akabynda/CLionProjects/cut&rotate/crop.bmp", img);
    clean_matrix(img.data, img.info.biHeight);
    return 0;
}