/*     __    _    _____  ____  ___   _       __   _____  _   _      ____      _
 *    / /\  | |    | |  | |_  | |_) | |\ |  / /\   | |  | | \ \  / | |_      / |
 *   /_/--\ |_|__  |_|  |_|__ |_| \ |_| \| /_/--\  |_|  |_|  \_\/  |_|__     |_|
 *
 *   Problem: nesting (arrow anti-pattern), potentially duplicated code
 */

int* foo(int bar)
{
    int* return_value = NULL;

    if (do_something(bar)) {
        if (init_stuff(bar)) {
            if (prepare_stuff(bar)) {
                return_value = do_the_thing(bar);
            }
            cleanup_3();
        }
        cleanup_2();
    }
    cleanup_1();

    return return_value;
}
