#include <string.h>

enum { // {{{
    PKT_THIS_OPERATION,
    PKT_THAT_OPERATION,
    PKT_PROCESS_CONDITIONALLY,
    PKT_CONDITION_SKIPPED,
    PKT_ERROR,
    READY_TO_SEND,
    NOT_READY_TO_SEND
}; // }}}

int parse_packet()
{
    static int packet_error_count = 0;

    int packet[16] = { 0 };
    int packet_length = 123;
    _Bool packet_condition = 1;
    int packet_status = 4;

    // get packet etc. ...

    _Bool REPARSE_PACKET = true;
    _Bool PACKET_ERROR = false;

    while (REPARSE_PACKET) {
        REPARSE_PACKET = false;
        PACKET_ERROR = false;

        switch (packet[0]) {
            case PKT_THIS_OPERATION:
                if (/* problem condition */) {
                    PACKET_ERROR = true;
                    break;
                }
                // ... handle THIS_OPERATION
                break;

            case PKT_THAT_OPERATION:
                if (/* problem condition */) {
                    PACKET_ERROR = true;
                    break;
                }
                // ... handle THAT_OPERATION
                break;

                // ...

            case PKT_PROCESS_CONDITIONALLY:
                if (packet_length < 9) {
                    PACKET_ERROR = true;
                    break;
                }
                if (packet_condition && packet[4]) {
                    packet_length -= 5;
                    memmove(packet, packet+5, packet_length);
                    REPARSE_PACKET = true;
                    break;
                } else {
                    packet[0] = PKT_CONDITION_SKIPPED;
                    packet[4] = packet_length;
                    packet_length = 5;
                    packet_status = READY_TO_SEND;
                }
                break;

                // ...

            default:
                PACKET_ERROR = true;
                break;
        }

        if (PACKET_ERROR) {
            packet_error_count++;
            packet_length = 4;
            packet[0] = PKT_ERROR;
            packet_status = NOT_READY_TO_SEND;
            break;
        }
    }

    // ...

    return 0;
}
