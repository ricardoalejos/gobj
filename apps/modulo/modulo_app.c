#include "modulo_base.h"
#include <stdio.h>

void * modulo5 = GOBJ_ST(
    GOBJ_ITR(modulo_ifc, .number = 5)
);

int main()
{
    printf("modulo5sum(3,3)=%d.\n", modulo_adder_sum(modulo5, 3, 3));
    return 0;
}
