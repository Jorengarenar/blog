#include <stdio.h>

int main()
{
foo:
    puts("Hello World!");
    goto foo;

    return 0;
}
