#include <stdio.h>
#include <stdlib.h>

struct item {
    char number[2];
    char x[3];
    char y[4];
};

FILE* skip_n_bytes(FILE* fp, int n);
char* read_n_bytes(FILE* fp, int n);
struct item parse_item(char path_to_file[]);

int main() {
    FILE* fp;
    char path[] = "/Users/maxfactor/CLionProjects/parser_typical/foo";
    fp = fopen(path, "rb");

    skip_n_bytes(fp, 10);

    read_n_bytes(fp, 10);

    printf("main() have worked");
    return 0;
}

FILE* skip_n_bytes(FILE *fp, int n) {
    char skipping_bytes[n];
    fread(skipping_bytes, sizeof(char), n, fp);
    printf("%s\n", skipping_bytes);
    return fp;
}

char* read_n_bytes(FILE* fp, int n) {
    char* reading_bytes = (char *) malloc(n);
    fread(reading_bytes, sizeof(char), n, fp);
    printf("%s\n", reading_bytes);
    return reading_bytes;
}
