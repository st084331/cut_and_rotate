#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int getBmpWidth(FILE *fpbmp) {
    int width = 0;

    fseek(fpbmp, 18L, SEEK_SET);
    fread(&width, sizeof(char), 4, fpbmp);

    return width;
}

int getBmpHeight(FILE *fpbmp) {
    int height = 0;

    fseek(fpbmp, 22L, SEEK_SET);
    fread(&height, sizeof(char), 4, fpbmp);

    return height;
}

int readBmpData( FILE* fpbmp, int offset , int width, int height )
{
    int i = 0, j = 0;
    unsigned char * pix = NULL;
    pix = malloc( 3 * sizeof( unsigned char ) );
    fseek(fpbmp, offset, SEEK_SET); // Jump to data part
    for( i = 0; i < height; i++ )
    {
        for( j = 0; j < width; j++ )
        {
            fread(pix, 3, 1, fpbmp);
        }
    }
    return 0;
}

int main(void) {
    char *original_image;
    char *rotate_image;
    original_image = "/Users/akabynda/CLionProjects/cut&rotate/airplane.bmp";
    rotate_image = "/Users/akabynda/CLionProjects/cut&rotate/crop2.bmp";
    FILE* fp = fopen(original_image, "rb");
    int w = getBmpWidth(fp);
    int h = getBmpHeight(fp);
    readBmpData(fp, 0, w, h);
    return 0;
}