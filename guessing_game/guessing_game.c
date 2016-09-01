#include <stdio.h>
#include <time.h> //gives us the time() function
#include <stdlib.h> //gives us the srand() and rand() functions

int main() {
	srand(time(NULL));

	int done_playing = 0;// the program just started, so we obviously want to play;

	while (!done_playing) {
		int secret_number = rand() % 100; //gives us a random number in the range [0,99] inclusive
		int guess;
		printf("I've picked a number between 0 and 99 inclusive, try to guess it!\n");
		do {
			printf("Enter a guess!\n");
			scanf("%d", &guess);
			if (guess < secret_number) {
				printf("%d is too low!\n", guess);
			} else if (guess > secret_number) {
				printf("%d is too high!\n", guess);
			} else {
				printf("Congrats! %d was the correct number!\n", secret_number);
			}
		} while (guess != secret_number);
		printf("Would you like to play again? y/n\n");
		char play_again_choice;
		scanf(" %c", &play_again_choice);
		if (play_again_choice == 'n' || play_again_choice == 'N') {
			done_playing = 1;
		}
	}

	printf("Goodbye!\n");

	return 0;
}

