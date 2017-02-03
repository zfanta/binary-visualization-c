#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned char byte[2];
    unsigned int matrix[256][256];
    unsigned int x, y;

    // initialize matrix;
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 256; j++)
        {
            matrix[i][j] = 0;
        }
    }

    FILE *fp = freopen(NULL, "rb", stdin);

    if(fread(&byte[0], 1, 1, fp) == 0)
        return -1;
    while(fread(&byte[1], 1, 1, fp) != 0)
    {
        x = byte[0];
        y = byte[1];
        matrix[x][y]++;
        byte[0] = byte[1];
    }

    for(int i = 0; i < 256; i++)
    {
        if(i)
            printf("\n");
        for(int j = 0; j < 256; j++)
        {
            if(j)
                printf(" ");
            printf("%d", matrix[i][j]);
        }
    }
}
