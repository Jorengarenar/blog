/* {{{
 *                      ___  ___  __   ___  __  ___         __           __        __   ___  
 *   /\  |\ |    | |\ |  |  |__  |__) |__  /__`  |  | |\ | / _`    |  | /__`  /\  / _` |__  .
 *  /--\ | \|    | | \|  |  |___ |  \ |___ .__/  |  | | \| \__>    \__/ .__/ /--\ \__> |___ .
 *               __   __               __           __   __   __   ___                       
 *              /  ` /  \  |\/|  |\/| /  \ |\ |    /  ` /  \ |  \ |__     | |\ |             
 *              \__, \__/  |  |  |  | \__/ | \|    \__, \__/ |__/ |___    | | \|             
 *            __         ___  __           __  ___      ___  ___        ___      ___         
 *           /__` |  | |  |  /  ` |__|    /__`  |   /\   |  |__   |\/| |__  |\ |  |          
 *           .__/ |/\| |  |  \__, |  |    .__/  |  /--\  |  |___  |  | |___ | \|  |
 *
 * }}} */  

int foo(int v)
{
    int something = 0;
    switch (v) {
        case FIRST_CASE:
            something = 2;
            goto common1;
        case SECOND_CASE:
            something = 7;
            goto common1;
        case THIRD_CASE:
            something = 9;
            goto common1;
common1:
            /* code common to FIRST, SECOND and THIRD cases */
            break;

        case FOURTH_CASE:
            something = 10;
            goto common2;
        case FIFTH_CASE:
            something = 42;
            goto common2;
common2:
            /* code common to FOURTH and FIFTH cases */
            break;
    }
}

// vim: nofen
