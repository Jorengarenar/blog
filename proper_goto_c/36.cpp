/*     __                                      
 *    /  ' _|_ _|_      _|_ ._ .    .  _, 
 *    \__,  |   |        |_ |  | \/ | (_|
 *
 *    proposal P2635R0 (https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2635r0.html)
 */

void foo()
{
    // ...

    for (auto i: outer_range) {
        for (auto j: inner_range) {
            if (condition) {
                inner_normal_action;
            }
            else {
                break continue;
            }
        }
        outer_normal_action;
    }

    // ▲ equivalent ▼

    for (auto i: outer_range) {
        for (auto j: inner_range) {
            if (condition) {
                inner_normal_action;
            }
            else {
                goto broke;
            }
        }
        outer_normal_action;
broke:
    }

    // ...
}
