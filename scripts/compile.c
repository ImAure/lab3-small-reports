#include <stdio.h>
#include <stdlib.h>

#define STRLEN2 1024

int main (int argc, char *argv[]) {
    char s[STRLEN2];
    unsigned i;
    
    printf("argc: %d\n", argc);
    if (argc <= 2) goto err;

    printf("List of argv:\n");
    for (i=0; i<argc; i++) {
        if (*argv[i] == '\0') goto err;
        printf("\t%s\n", argv[i]);
    }

    sprintf(s, "pdflatex -jobname=%s --output-directory=out %s", argv[1], argv[2]);
    printf("executing: %s\n------------------------------\n", s);
    system(s);

    sprintf(s, "mv ./out/%s.pdf ./%s.pdf", argv[1], argv[1]);
    printf("------------------------------\nexecuting: %s\n------------------------------\n", s);
    system(s);

    return EXIT_SUCCESS;

    err:
        printf("EXCEPTION: Not enough arguments: Format must be:\n./compile jobname filename[.tex]\n");
        return EXIT_FAILURE;
}
