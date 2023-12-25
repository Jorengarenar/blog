#include <errno.h>

int main()
{
restart:
    if (some_system_call() == -1) {
        if (errno == EINTR) {
            goto restart;
        }

        // handle real errors
    }

    return 0;
}
