#include "localmodule/localmodule.h"
#include "embeddedlib/embeddedlib.h"
#include <stdint.h>

int32_t main() 
{
    int32_t a = 5;
    int32_t b = 3;

    while (1)
    {
        // Call the local module function
        a = localmod_subinteger(a, b);
        // Call the embedded library function
        a = elib_addinteger(a, b);
    }

    return 0;
}