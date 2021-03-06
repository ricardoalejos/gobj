#include <stdio.h>
#include "gobj.h"

GOBJ_DECLARE(person_attr, {char * name;})
GOBJ_DECLARE(person_ifc, {void (*farewell)(void * person);})
GOBJ_DECLARE(useless_attr, {char * useless;})

void spanish_farewell(void * person);

// Creation of an external table record (ETR) for later reference in
// one or multiple tables.
gobj_tr_t spanish_farewell_ifc = GOBJ_ETR(person_ifc, .farewell=spanish_farewell);

// Static creation of a table
void * person0 = GOBJ_ST(
    // Addition of an ETR using their addresses
    &spanish_farewell_ifc,
    // Addition of an internal table record (ITR)
    GOBJ_ITR(person_attr, .name="Ricardo")
);

// Static creation of a table
void * person1 = GOBJ_ST(
    // Addition of an ETR using their addresses
    &spanish_farewell_ifc,
    // Addition of an internal table record (ITR)
    GOBJ_ITR(person_attr, .name="Cecilia")
);

void farewell(void * person)
{
    printf("%s says: ", GOBJ_GET_ATTR(person, person_attr)->name);
    GOBJ_GET_ATTR(person, person_ifc)->farewell(person);
}

void spanish_farewell(void * person)
{
    printf("adios!\n");
}

int main() {
    farewell(person0);
    farewell(person1);
    // Try to get an attribute that is not in the object
    void * result = GOBJ_GET_ATTR(person0, useless_attr);
    printf("Pointer to useless attribute is %p.\n", result);
    return 0;
}
