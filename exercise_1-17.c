/**
 * Prints all input lines that are longer than 80 characters.
 */


#include <stdio.h>
#define MAX_CHARS_PER_LINE 1000
#define MAX_NUMBER_OF_LINES 100
#define MINIMUM_STRING_LENGTH_FOR_STORAGE 80

int get_line(char line[], int limit);
void copy_line(char from[], char to[]);

int main() {
    char current_line[MAX_CHARS_PER_LINE];
    char lines[MAX_NUMBER_OF_LINES][MAX_CHARS_PER_LINE];
    int current_line_length;

    int index = 0;
    while( (index < MAX_NUMBER_OF_LINES) && (current_line_length = get_line(current_line, MAX_CHARS_PER_LINE)) > 0) { 
        if (current_line_length > MINIMUM_STRING_LENGTH_FOR_STORAGE)
            copy_line(current_line, lines[index++]);
    }

    for(int i=0; i < index; i++)
        printf("-> %s\n", lines[i]);

    return 0;
}


int get_line(char line[], int limit) {
    int character;
    int index=0;

    while(index < limit-1 && (character = getchar()) != EOF && character != '\n')
        line[index++] = character;
    if (character == '\n')
        line[index++] = character;
    line[index] = '\0';
    return index;
}

void copy_line(char from[], char to[]) {
    for(int i=0; i<MAX_CHARS_PER_LINE; i++)
        to[i] = from[i];
}
