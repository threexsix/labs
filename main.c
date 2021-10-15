#include <stdio.h>
#include <string.h>

int lines(char *text_name){

    int counter = 0;

    FILE *f;
    f = fopen(text_name, "r");

    char c;

    while ((c = fgetc(f)) != EOF){

        if (c == '\n'){
            counter++;
        }
    }

    return counter;
}

int bytes(char *text_name){

    int counter = 0;

    FILE *f;
    f = fopen(text_name, "r");

    while (fgetc(f) != EOF)
        counter++;

    return counter;
}

int words(char *text_name){

    int counter = 0;
    FILE *f;
    f = fopen(text_name, "r");
    char c;
    char current = 0;
    char prev = 0;
    while ((c = fgetc(f)) != EOF){

        if ((c != ' ') && (c != '\n') && (c != '\t')){
            current = 1;
        }

        if ((prev == 1) && (current == 0)){
            counter++;
        }

        prev = current;
        current = 0;
    }

    if ((prev == 1) && (current == 1) && (fgetc(f) == EOF)){
        counter++;
    }

    return counter;
}

int main(int argc, char *argv[]) {

    char *text_name = argv[argc - 1];

    for (int i = 0; i < argc - 1; i++) {

        if ((strncmp(argv[i], "-l", 2) == 0) || (strncmp(argv[i], "--lines", 7) == 0)) {
            printf("lines - %d \n", lines(text_name));
        }

        if ((strncmp(argv[i], "-c", 2) == 0) || (strncmp(argv[i], "--bytes", 7) == 0)) {
            printf("bytes - %d \n", bytes(text_name));
        }

        if ((strncmp(argv[i], "-w", 2) == 0) || (strncmp(argv[i], "--words", 7) == 0)) {
            printf("words - %d \n", words(text_name));
        }
    }
}
