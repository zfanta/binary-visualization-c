#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printUintLE(unsigned int value, unsigned int bit);
void printHeader();
int grayScale();

int main(int argc, char **argv)
{
    if(1 < argc)
    {
        if(strcmp(argv[1], "-g") == 0)
            return grayScale();
    }

    printHeader();

    FILE *fp = freopen(NULL, "rb", stdin);
    unsigned int pixel;
    while(fscanf(fp, "%d", &pixel) != EOF)
    {
        printUintLE(pixel, 24);
    }
}

int grayScale()
{
    FILE *fp = freopen(NULL, "rb", stdin);
    unsigned int pixel[256*256];
    unsigned int max = 0;
    unsigned int index = 0;
    while(fscanf(fp, "%d", &pixel[index]) != EOF)
    {
        if(max < pixel[index])
            max = pixel[index];
        index++;
    }

    printHeader();
    for(index = 0; index < 256*256; index++)
    {
        pixel[index] = pixel[index] | ((pixel[index] & 0xFF) << 8);
        pixel[index] = pixel[index] | ((pixel[index] & 0xFF) << 16);
        printUintLE(pixel[index], 24);
    }

    return 0;
}

void printHeader()
{
    printf("BM");               //CHAR bfType[2]
    printUintLE(196662, 32);    //DWORD bfSize
    printUintLE(0, 16);         //WORD bfReserved1
    printUintLE(0, 16);         //WORD bfReserved2
    printUintLE(54, 32);        //DWORD bfOffBits

    printUintLE(40, 32);        //DWORD biSize
    printUintLE(256, 32);       //LONG biWidth
    printUintLE(256, 32);       //LONG biHeight
    printUintLE(1, 16);         //WORD biPlanes
    printUintLE(24, 16);        //WORD biBitCount
    printUintLE(0, 32);         //DWORD biCompression
    printUintLE(196608, 32);    //DWORD biSizeImage
    printUintLE(0, 32);         //LONG biXPelsPerMeter
    printUintLE(0, 32);         //LONG biYPelsPerMeter
    printUintLE(0, 32);         //DWORD biClrUsed
    printUintLE(0, 32);         //DWORD biClrImportant
}

void printUintLE(unsigned int value, unsigned int bit)
{
    for(int i = 0; i < bit; i += 8)
    {
        printf("%c", value >> i);
    }
}
