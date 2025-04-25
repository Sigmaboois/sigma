#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void writescoretofile(int user_score) //function to write score to file
{
    FILE *filew;
    filew = fopen("score.txt","a");
    printf("Your score is %d\n",user_score);
    fprintf(filew,"%d\n",user_score);
    fclose(filew);
    printf("done\n");
}

int main() {
    int number, guess, attempts;
    char playAgain,user_acceptance_for_file;

    do {
        srand(time(0)); // Seed random number generator
        number = rand() % 100 + 1; // Random number between 1 and 100
        attempts = 0;

        printf("I'm thinking of a number between 1 and 100.\n");

        do {
            printf("Enter your guess: ");
            int result = scanf("%d", &guess);

            // Check if input was not a valid integer
            if (result != 1) {
                printf("Not a viable answer.\n");
                while (getchar() != '\n'); // Clear invalid input
                continue;
            }

            attempts++;
            int score = attempts * number;

            if (guess < number) {
                printf("Too low!\n");
            } else if (guess > number) {
                printf("Too high!\n");
            } else {
                printf("You got it in %d tries!\n", attempts);
                printf("Your score is: %d\n",score);
                printf("Do you want your score to be written to a text file?(\Y/N\)");
                scanf(" %c",&user_acceptance_for_file);
                if (user_acceptance_for_file == 'Y' || user_acceptance_for_file == 'y'){
                    writescoretofile(score);
                } else {
                    break;
                }
            }

        } while (guess != number);

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain); // Space before %c to catch newline

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
