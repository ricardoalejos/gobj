#include <stdio.h>
#include "gobj.h"

GOBJ_DECLARE(person_attr, {char * name;})
GOBJ_DECLARE(farewell_ifc, {void (*farewell)(void * person);})
GOBJ_DECLARE(useless_attr, {char * useless;})

void spanish_farewell(void * person);
void finnish_farewell(void * person);

// Creation of an external table record (ETR) for later reference in
// one or multiple tables.
gobj_tr_t spanish_farewell_ifc = GOBJ_ETR(farewell_ifc, .farewell=spanish_farewell);

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

// Static creation of a table
void * person2 = GOBJ_ST(
    // We add a different implementation of the farewell interface
    GOBJ_ITR(farewell_ifc, .farewell=finnish_farewell),
    GOBJ_ITR(person_attr, .name="Mikko")
);

void farewell(void * person)
{
    printf("%s says: ", GOBJ_GET_ATTR(person, person_attr)->name);
    GOBJ_GET_ATTR(person, farewell_ifc)->farewell(person);
}

// Common interface for all persons
void wave_hand(void * person)
{
    printf("%s waves the hand.\n", GOBJ_GET_ATTR(person, person_attr)->name);
}

void spanish_farewell(void * person)
{
    printf("adios!\n");
}

void finnish_farewell(void * person)
{
    printf("heippa!\n");
}

int main() {
    // Let us execute the farewell function for each person
    farewell(person0);
    wave_hand(person0);
    farewell(person1);
    wave_hand(person1);
    farewell(person2);
    wave_hand(person2);
    // Try to get an attribute that is not in the object
    void * result = GOBJ_GET_ATTR(person0, useless_attr);
    printf("Pointer to useless attribute is %p.\n", result);
    return 0;
}
