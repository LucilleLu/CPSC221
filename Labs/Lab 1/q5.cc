/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

int main ()
{
  int num, guessNum;

  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 100: */
  num = rand() % 100 + 1;

  do {
    printf ("Guess the number (1 to 100): ");
    scanf ("%d",&guessNum);
    if (guessNum == 0) {
      puts ("Game over.");
      return 0;
    }
    if (guessNum < 1 || 100 < guessNum) {
      puts ("Your guess number is out of range. Press 0 to end the game.");
    } else {
        if (num<guessNum) {
          puts ("The guess number is lower. Press 0 to end the game.");
        }
        if (num>guessNum) {puts ("The secret number is higher. Press 0 to end the game.");
        }
      }
  } while (num!=guessNum);

  puts ("Congratulations!");
  return 0;
}
