#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear screen (works on Windows)
void clearScreen() {
    system("cls");  // For Linux/Mac use "clear"
}

// Function to print a line separator
void printLine() {
    printf("--------------------------------------------------\n");
}

int main() {
    int number, guess, attempts = 0;
    char playAgain;

    // Seed the random number generator
    srand(time(0));

    do {
        clearScreen();
        number = rand() % 100 + 1;  // Generate number between 1 and 100
        attempts = 0;

        printLine();
        printf("\t🎯 NUMBER GUESSING GAME 🎯\n");
        printLine();
        printf("Guess the number between 1 and 100\n");

        // Game loop
        do {
            printf("\nEnter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess > number) {
                printf("🔻 Too high! Try a smaller number.\n");
            } else if (guess < number) {
                printf("🔺 Too low! Try a bigger number.\n");
            } else {
                printf("🎉 Congratulations! You guessed it in %d attempts.\n", attempts);
            }

        } while (guess != number);

        // Play again option
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'Y' || playAgain == 'y');

    printLine();
    printf("Thanks for playing! See you again. 👋\n");
    printLine();

    return 0;
}
