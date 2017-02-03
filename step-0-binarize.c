#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned int address;
    char hex[3];
    char byte;

    FILE *fp = freopen(NULL, "rb", stdin);

    while(fscanf(fp, "%x", &address) != EOF)
    {
        for(int i = 0; i < 16; i++)
        {
            if(fscanf(fp, "%s", hex) == EOF)
                break;
            if (hex[0] == '?')
                hex[0] = hex[1] = '0';
            sscanf(hex, "%02x", &byte);
            printf("%c", byte);
        }
    }
}
