#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {
    char* original;
    char* disemvoweled;
    char* vowels;
    size_t sentence_length;
    int num_vowels, num_consonants;
    int i;
    char c;

    /* Initialize variables */
    original = NULL;
    sentence_length = 0;

    /* Request and receive input */
    printf("Enter sentence to disemvowel!\n");
    getline(&original, &sentence_length, stdin);

    /* Allocate memory for vowels and disemvoweled */
    disemvoweled = calloc(sentence_length, sizeof(char));
    vowels = calloc(sentence_length, sizeof(char));

    /* Initialize variables and loop through input */
    num_vowels = 0;
    num_consonants = 0;
    for (i = 0; i < sentence_length; ++i) {
        c = original[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels[num_vowels] = c;
            num_vowels++;
        }
        else if(c != ' ') {
            disemvoweled[num_consonants] = c;
            num_consonants++;
        }
    }

    /* Set null bytes */
    vowels[num_vowels] = 0;
    disemvoweled[num_consonants] = 0;

    /* Print results */
    printf("%s", disemvoweled);
    printf("%s\n", vowels);

    free(original);
    free(disemvoweled);
    free(vowels);

    return 0;
}
