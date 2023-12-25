#include <errno.h>

int main()
{
    int res;
    do {
        res = some_system_call();
    } while (res == -1 && errno == EINTR);

    if (res == -1) {
        // handle real errors
    }

    return 0;
}
