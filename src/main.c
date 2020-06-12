#include "uls.h"

/*
    * This is implementation of UNIX ls utility.
    * Flags Implemented: -a -A -R -m -p -1 -C -o -g -d (-h)
*/

int main(int argc, char **argv) {
    int return_value = mx_return_value(argc, argv);
    char *flags  = mx_flags_parser(argc, argv);

    mx_directories(argc, argv, flags);
    return return_value;
}
