/*     __    _    _____  ____  ___   _       __   _____  _   _      ____     ___
 *    / /\  | |    | |  | |_  | |_) | |\ |  / /\   | |  | | \ \  / | |_       ) )
 *   /_/--\ |_|__  |_|  |_|__ |_| \ |_| \| /_/--\  |_|  |_|  \_\/  |_|__     /_/_
 *
 *   Problem: duplicated code, multiple exit points
 */

int* foo(int bar)
{
    int* return_value = NULL;

    if (!do_something(bar)) {
        cleanup_1();
        return return_value;
    }
    if (!init_stuff(bar)) {
        cleanup_2();
        cleanup_1();
        return return_value;
    }
    if (!prepare_stuff(bar)) {
        cleanup_3();
        cleanup_2();
        cleanup_1();
        return return_value;
    }

    cleanup_3();
    cleanup_2();
    cleanup_1();

    return do_the_thing(bar);
}
