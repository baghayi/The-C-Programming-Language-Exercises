#include <stdio.h>

#define BUFFER_SIZE 1000

int main(void) {
    char buff[BUFFER_SIZE];
    short int buff_counter = 0;
    char input;

    while(buff_counter < BUFFER_SIZE) {
        input = getchar();
        if (input == '\n') break;
        if (input == EOF) break;
        buff[buff_counter] = input;
        buff_counter++;
    }
    buff[buff_counter] = '\0';

    printf("-> %s\n", buff);
    return 0;
}
