#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char** argv)
{
    printf("Binary Extractor for OscServer.\n"
           "Author: Vladimir Tatarinov\n");
    if (argc != 3) {
        int i;
        i = 0;
        char* str = argv[0];
        while (*(argv[0]+i) != 0) {
            if (*(argv[0]+i) == '\\')
                str = argv[0] + i + 1;
            ++i;
        }
        printf("Usage: %s [input file] [output file]\n", str);
        system("pause");
        return 0;
    }
    FILE* in = fopen(argv[1], "rb");
    if (in == NULL) {
        printf("Can't open input file!");
        system("pause");
        return 0;
    }
    FILE* out = fopen(argv[2], "w");

    fseek(in, 0L, SEEK_END);
    int size = ftell(in);
    fseek(in, 0x1EL, SEEK_SET);
    for (int i = 0x1EL; i < size; i++) {
        int8_t c;
        fread(&c, 1, 1, in);
        int d = c;
        fprintf(out, "%d\n", d);
    }
    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}
