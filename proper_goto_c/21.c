/*     __    _    _____  ____  ___   _       __   _____  _   _      ____      ___
 *    / /\  | |    | |  | |_  | |_) | |\ |  / /\   | |  | | \ \  / | |_      | |
 *   /_/--\ |_|__  |_|  |_|__ |_| \ |_| \| /_/--\  |_|  |_|  \_\/  |_|__     _)_)
 *
 *   Problem: abuse of the `do {} while` (+ nesting)
 */


int* foo(int bar)
{
    int* return_value = NULL;

    do {
        if (!do_something(bar)) break;
        do {
            if (!init_stuff(bar)) break;
            do {
                if (!prepare_stuff(bar)) break;
                return_value = do_the_thing(bar);
            } while (0);
            cleanup_3();
        } while (0);
        cleanup_2();
    } while (0);
    cleanup_1();

    return return_value;
}
