#include <stdio.h>

#define MAX_STRING_LENGTH 1000
#define MAX_LINES 200
#define NEW_LINE '\n'
#define TAB '\t'
#define STRING_TERMINATOR '\0'

int get_line(char line[], int max_string_length);
int has_line_trailing_blank(char line[], int line_length);
int remove_trailing_blank(char line[], int line_length);

int main(void) {
    char lines[MAX_LINES][MAX_STRING_LENGTH];
    int current_line_length;

    int current_line_index, total_lines = 0;

    while((current_line_length = get_line(lines[current_line_index], MAX_STRING_LENGTH)) > 0) {
        //filter traling lines
        while(has_line_trailing_blank(lines[current_line_index], current_line_length-1))
            current_line_length = remove_trailing_blank(lines[current_line_index], current_line_length-1);

        //Ignore blank line
        if (current_line_length == 1 && lines[current_line_index][0] == NEW_LINE)
            continue;

        if (++current_line_index >= MAX_LINES) break; // Increment index & check max line limit.
    }
    total_lines = current_line_index+1;
 

    // Print Input Lines
    for(int i=0; i < total_lines; i++)
        printf("%s", lines[i]);
}

int get_line(char line[], int max_string_length) {
    char character;
    int index = 0;

    while(index-1 < max_string_length && (character=getchar()) != EOF) {
        line[index++] = character;
        if (character == NEW_LINE) break;
    }

    line[index] = STRING_TERMINATOR;
    return index;
}

int has_line_trailing_blank(char line[], int line_length) {
    if (line[line_length] == NEW_LINE)
        line_length--;
    if (line[line_length] == ' ' || line[line_length] == TAB)
        return 1;
    return 0;
}

int remove_trailing_blank(char line[], int line_length) {
    int has_trailing_new_line = (line[line_length] == NEW_LINE) ? 1 : 0;
    if (has_trailing_new_line) line_length--;

    // cancel operation  if no blank is encountered.
    if (line[line_length] != ' ' && line[line_length] != TAB) return line_length + has_trailing_new_line;
    
    if (has_trailing_new_line) {
        line[line_length] = NEW_LINE;
        line_length++;
    }
    line[line_length] = STRING_TERMINATOR;
    return line_length - 1 + has_trailing_new_line;
}
