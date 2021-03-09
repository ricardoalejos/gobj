
#ifndef _MODULO_BASE_H_
#define _MODULO_BASE_H_

#include "gobj.h"

GOBJ_DECLARE(
    modulo_ifc,
    {
        unsigned int number;
    }
);

unsigned int modulo_adder_sum(
    void * adder,
    unsigned int a,
    unsigned int b
);

#endif
