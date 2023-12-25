/*     __    _    _____  ____  ___   _       __   _____  _   _      ____        _ 
 *    / /\  | |    | |  | |_  | |_) | |\ |  / /\   | |  | | \ \  / | |_      /_| |
 *   /_/--\ |_|__  |_|  |_|__ |_| \ |_| \| /_/--\  |_|  |_|  \_\/  |_|__       |_|
 *
 *   Problem: "Entia non sunt multiplicanda praeter necessitatem";
 *            reading bottom-up instead of top-bottom
 */

static inline int foo_2(int bar)
{
    int return_value = 0;
    if (prepare_stuff(bar)) {
        return_value = do_the_thing(bar);
    }
    cleanup_3();
    return return_value;
}

static inline int foo_1(int bar)
{
    int return_value = 0;
    if (init_stuff(bar)) {
        return_value = foo_2(bar);
    }
    cleanup_2();
    return return_value;
}

int foo(int bar)
{
    int return_value = 0;
    if (do_something(bar)) {
        return_value = foo_1(bar);
    }
    cleanup_1();
    return return_value;
}
