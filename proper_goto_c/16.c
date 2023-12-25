/*     __    _    _____  ____  ___   _       __   _____  _   _      ____     ___      ___ 
 *    / /\  | |    | |  | |_  | |_) | |\ |  / /\   | |  | | \ \  / | |_       ) )    | |  
 *   /_/--\ |_|__  |_|  |_|__ |_| \ |_| \| /_/--\  |_|  |_|  \_\/  |_|__     _)_) () _)_)
 */

int foo(int bar)
{
    int return_value = 0;
    bool something_done = false;
    bool stuff_inited = false;
    bool stuff_prepared = false;
    bool oksofar = true;

    if (oksofar) {  // this `if` is optional (always executes) but included for consistency 
        if (do_something(bar)) {
            something_done = true;
        } else {
            oksofar = false;
        }
    }

    if (oksofar) {
        if (init_stuff(bar)) {
            stuff_inited = true;
        } else {
            oksofar = false;
        }
    }

    if (oksofar) {
        if (prepare_stuff(bar)) {
            stuff_prepared = true;
        } else {
            oksofar = false;
        }
    }

    // Do the thing
    if (oksofar) {
        return_value = do_the_thing(bar);
    }

    // Clean up
    if (stuff_prepared) {
        cleanup_3();
    }
    if (stuff_inited) {
        cleanup_2();
    }
    if (something_done) {
        cleanup_1();
    }

    return return_value;
}
