#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Lowercases all letters in str */
void toLower(char* str){
   int i, length;

   length = strlen(str);
   for (i = 0; i < length; ++i)
      if (str[i] >= 'A' && str[i] <= 'Z')
         str[i] += 'a' - 'A';
}

/* Returns allocated string */
char* removeAll(char* original, char* toRemove){
   int original_length, remove_length, new_length;
   int i, j;
   char* result;

   original_length = strlen(original);
   remove_length = strlen(toRemove);
   result = calloc(original_length, 1);

   new_length = 0;
   for (i = 0; i < original_length; ++i){
      for (j = 0; j < remove_length; ++j){
         if (original[i] == toRemove[j])
            break;
      }
      if (j == remove_length){
         result[new_length] = original[i];
         ++new_length;
      }
   }

   result[new_length] = 0;
   return result;
}

int main(void) {
    char *original, *disemvoweled, *vowels;
    size_t sentence_length;

    /* Initialize variables */
    original = NULL;
    sentence_length = 0;

    /* Request and receive input */
    printf("Enter sentence to disemvowel!\n");
    getline(&original, &sentence_length, stdin);
    toLower(original);

    /* Make new strings with removed letters */
    disemvoweled = removeAll(original, "aeiou !\n");
    vowels = removeAll(original, "bcdfghjklmnpqrstvwxyz \n");

    /* Print results */
    printf("%s\n", disemvoweled);
    printf("%s\n", vowels);

    free(original);
    free(disemvoweled);
    free(vowels);

    return 0;
}
