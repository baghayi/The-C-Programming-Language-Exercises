#include <stdio.h>
#define MAX_LINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int current_line_length;
    int max_line_length_seen = 0;
    char current_line[MAX_LINE];
    char max_line_seen[MAX_LINE];

    while((current_line_length = get_line(current_line, MAX_LINE)) > 0) {
        if(current_line_length > max_line_length_seen) {
            max_line_length_seen = current_line_length;
            copy(max_line_seen, current_line);
        }
    }

    if (max_line_length_seen > 0) {
        printf("(%d)-> %s", max_line_length_seen, max_line_seen);
    }

    return 0;
}

int get_line(char line[], int maxline) {
    int charachter, index;

    for (index=0; index < maxline-1 && (charachter=getchar()) != EOF && charachter != '\n'; ++index)
        line[index] = charachter;
    
    if (charachter == '\n') {
        line[index] = charachter;
        ++index;
    }

    line[index] = '\0';
    return index;
}

void copy(char to[], char from[]) {
    int index = 0;

    while((to[index] = from[index]) != '\0')
        ++index;
}
