#include "modulo_base.h"

// Type IDs must only be initialized once in one C file
GOBJ_INIT_ID(modulo_ifc);

unsigned int modulo_adder_sum(
    void * adder,
    unsigned int a,
    unsigned int b
){
    return (a + b) % GOBJ_GET_ATTR(adder, modulo_ifc)->number;
}