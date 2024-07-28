#include "string.h"
#include "stdio.h"
#include "stdlib.h"

char * reverse(char *);
int string_size(char *);

int test_reverse_character_string_one_character();
int test_reverse_character_string_two_characters();
int test_reverse_character_string_three_characters();
int test_reverse_character_string_with_enormous_characters();

int main(void) {
    int test_result = 0;
    if ((test_result = test_reverse_character_string_one_character()) != 0) return test_result;
    if ((test_result = test_reverse_character_string_two_characters()) != 0) return test_result;
    if ((test_result = test_reverse_character_string_three_characters()) != 0) return test_result;
    if ((test_result = test_reverse_character_string_with_enormous_characters()) != 0) return test_result;

    char * line = NULL;
    size_t line_size = 0;
    while(getline(&line, &line_size, stdin) != EOF){
        if (strcmp(line, "\n") == 0) continue;
        printf("%s\n", reverse(line));
    }
    free(line);

    return 0;
}

char * reverse(char * string) {
    int total_characters = string_size(string);
    
    char * reverse_string = (char *) malloc(sizeof(char) * (total_characters+1));

    int back_counter = total_characters;
    for (int i = 0; i < total_characters; i++)
        reverse_string[i] = string[--back_counter];
    reverse_string[total_characters] = '\0';
    return reverse_string;
}

int string_size(char * string) {
    int total_characters = 0;
    while(string[total_characters] != '\0') total_characters++;
    return total_characters;
}

int test_reverse_character_string_one_character() {
    char * input = "H";
    char * expected = "H";
    char * reversed_string = reverse(input);
    int result = strcmp(reversed_string, expected);
    free(reversed_string);
    return result;
}

int test_reverse_character_string_two_characters() {
    char * input = "Hi";
    char * expected = "iH";
    char * reversed_string = reverse(input);
    int result = strcmp(reversed_string, expected);
    free(reversed_string);
    return result;
}

int test_reverse_character_string_three_characters() {
    char * input = "Boy";
    char * expected = "yoB";
    char * reversed_string = reverse(input);
    int result = strcmp(reversed_string, expected);
    free(reversed_string);
    return result;
}

int test_reverse_character_string_with_enormous_characters() {
    char * input = "This is a text!";
    char * expected = "!txet a si sihT";
    char * reversed_string = reverse(input);
    int result = strcmp(reversed_string, expected);
    free(reversed_string);
    return result;
}
