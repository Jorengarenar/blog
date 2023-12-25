#include <stdio.h>
#include <...>

int main()
{
    int* buf = NULL;
    size_t pos = 0;
    size_t sz = 8; // or whatever initial size

    _Bool firstIter = true;

    do {
        if (pos > sz || firstIter) { // resize array
            if (!firstIter) {
                sz <<= 1;
            }
            firstIter = false;

            buf = reallocarray(sz, pos, ...);
            // check for errors
        }

        // do something with buf
    } while (checkQuit());

    return 0;
}
