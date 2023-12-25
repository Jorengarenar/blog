/*
 *                       x
 *                      ┌─┐
 *                      │ ▼
 *                     ┌┴──┐
 *                ┌───►│ C ├────┐
 *                │    └───┘    │
 *               y│             │z
 *                │             │
 *                │      x      ▼
 *              ┌─┴─┬────────►┌───┐   nul
 *    start ──► │ A │         │ B │ ──────► finish
 *              └──┬┘◄────────┴──┬┘
 *               ▲ │     y     ▲ │
 *               └─┘z          └─┘x
 */

_Bool machine(const char* c)
{
qA:
    switch (*(c++)) {
        case 'x': goto qB;
        case 'y': goto qC;
        case 'z': goto qA;
        default: goto err;
    }

qB:
    switch (*(c++)) {
        case 'x': goto qC;
        case 'z': goto qB;
        case '\0': goto finish;
        default: goto err;
    }

qC:
    switch (*(c++)) {
        case 'x': goto qB;
        case 'y': goto qA;
        default: goto err;
    }

finish:
    return true;

err:
    return false;
}

