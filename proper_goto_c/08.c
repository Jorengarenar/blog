int* foo(int bar)
{
    int* return_value = NULL;

    if (!do_something(bar)) {
        goto error_1;
    }
    if (!init_stuff(bar)) {
        goto error_2;
    }
    if (!prepare_stuff(bar)) {
        goto error_3;
    }
    return_value = do_the_thing(bar);

error_3:
    cleanup_3();
error_2:
    cleanup_2();
error_1:
    cleanup_1();

    return return_value;
}
