#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts;
    char playAgain;

    do {
        srand(time(0)); // Seed random number generator
        number = rand() % 100 + 1; // Random number between 1 and 100
        attempts = 0;

        printf("I'm thinking of a number between 1 and 100.\n");

        do {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess < number) {
                printf("Too low!\n");
            } else if (guess > number) {
                printf("Too high!\n");
            } else {
                printf("You got it in %d tries!\n", attempts);
            }
        } while (guess != number);

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain); // Space before %c to catch newline

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
