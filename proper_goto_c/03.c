#include <stdio.h>

int main()
{
    int i = 0;
foo:
    puts("Hello World!");
    ++i;
    if (i <= 10) {
        goto foo;
    }

    return 0;
}
