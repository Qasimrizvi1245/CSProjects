#include <stdio.h>
#include <stdlib.h>
// This program is a cipher that takes a letter in the alphabet switches it with another
// letter 13 places before or after it.


int main(int argc, char**argv) {

    for (int i = 1; i < argc; i++) {

        char *x = argv[i];

        for (; *x != '\0'; ++x) {

            unsigned char letter = *x;

            if (letter >= 'a' && letter <= 'm') {
                letter += 13;
            } else if (letter >= 'A' && letter <= 'M') {
                letter += 13;
            } else if (letter >= 'n' && letter <= 'z') {
                letter -= 13;
            } else if (letter >= 'N' && letter <= 'Z') {
                letter -= 13;
            }

            printf("%c", letter);
        }

        printf("\n");

        return EXIT_SUCCESS;

    }

}



