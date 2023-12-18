#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define KEYS_SIZE 5
#define MAX_VALUE_SIZE 6

char* get_user_string_input(char prompt[]);
void to_lowercase(char* string);
char* uwuify(char* input);

int main() {
    char* input = get_user_string_input("Enter the text to be uwuified: ");
    
    to_lowercase(input);
    char* output = uwuify(input);

    printf("%s\n", output);

    free(input);
    free(output);
    return 0;
}

char* get_user_string_input(char prompt[]) {
    printf("%s", prompt);

    char* input = NULL;
    size_t input_size = 0;

    if(getline(&input, &input_size, stdin) != -1) {
        return input;
    } else {
        printf("Error: An error occurred while attempting to read input.\n");
        exit(EXIT_FAILURE);
    }
}

void to_lowercase(char* string) {
    int string_len = strlen(string);
    for(int i = 0; i < string_len; i++) {string[i] = tolower(string[i]);}
}

char* uwuify(char* input) {
    char* output = (char*)malloc(sizeof(input) * MAX_VALUE_SIZE);

    if(output != NULL) {
        char keys[KEYS_SIZE] = {'l', 'r', 'u', '.', '!'}, values[KEYS_SIZE][MAX_VALUE_SIZE] = {"w", "w", "uw", ". :3", "!! x3"};
        
        int input_len = strlen(input);
        
        for(int a = 0; a < input_len; a++) {
            bool match = false;
            
            for(int b = 0; b < KEYS_SIZE; b++) {
                if(input[a] == keys[b]) {
                    strcat(output, values[b]);
                    match = true;
                }
            }

            if(!match) {
                char tmp[2] = {input[a], '\0'};
                strcat(output, tmp);
            }
        }

        return output;
    } else {
        printf("Error: Failed to allocate memory for output.\n");
        exit(EXIT_FAILURE);
    }
}
