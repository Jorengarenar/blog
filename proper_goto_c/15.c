/*     __    _    _____  ____  ___   _       __   _____  _   _      ____     ___
 *    / /\  | |    | |  | |_  | |_) | |\ |  / /\   | |  | | \ \  / | |_       ) )
 *   /_/--\ |_|__  |_|  |_|__ |_| \ |_| \| /_/--\  |_|  |_|  \_\/  |_|__     _)_)
 *
 *   Problem: additional variables; "cascading" booleans; 
 *            potential nesting and complicated boolean expressions
 */

int* foo(int bar)
{
    int* return_value = NULL;

    bool flag_1 = false;
    bool flag_2 = false;
    bool flag_3 = false;

    flag_1 = do_something(bar);
    if (flag_1) {
        flag_2 = init_stuff(bar);
    }
    if (flag_2) {
        flag_3 = prepare_stuff(bar);
    }
    if (flag_3) {
        return_value = do_the_thing(bar);
    }

    if (flag_3) {
        cleanup_3();
    }
    if (flag_2) {
        cleanup_2();
    }
    if (flag_1) {
        cleanup_1();
    }

    return return_value;
}
