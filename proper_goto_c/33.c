#include <stdio.h>

int main()
{
    for (int i = 1; i <= 5; ++i) {
        printf("outer iteration (i): %d\n", i);

        for (int j = 1; j <= 200; ++j) {
            printf("    inner iteration (j): %d\n", j);
            if (j >= 3) {
                break; // breaks from inner loop, outer loop continues
            }
            if (i >= 2) {
                /* ¿How to break from outer loop? */
            }
        }
    }

    puts("Done!");

    return 0;
}
