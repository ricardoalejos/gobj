#include <stdio.h>
#include "gobj.h"

GOBJ_DECLARE_TYPE(person_attr, {char * name;})
GOBJ_DECLARE_TYPE(person_ifc, {void (*farewell)(void * person);})

void spanish_farewell(void * person);
void finnish_farewell(void * person);
void english_farewell(void * person);

void * person0 = GOBJ_SINIT_TABLE(
    GOBJ_SINIT_RECORD(person_attr, .name="Ricardo"),
    GOBJ_SINIT_RECORD(person_ifc, .farewell=spanish_farewell)
);

void * person1 = GOBJ_SINIT_TABLE(
    GOBJ_SINIT_RECORD(person_attr, .name="Petri"),
    GOBJ_SINIT_RECORD(person_ifc, .farewell=finnish_farewell)
);

void * person2 = GOBJ_SINIT_TABLE(
    GOBJ_SINIT_RECORD(person_attr, .name="Fred"),
    GOBJ_SINIT_RECORD(person_ifc, .farewell=finnish_farewell)
);

void farewell(void * person)
{
    printf("%s says: ", GOBJ_INTERPRET_ATTR(person, person_attr)->name);
    GOBJ_INTERPRET_ATTR(person, person_ifc)->farewell(person);
}

void spanish_farewell(void * person)
{
    printf("adios!\n");
}

void finnish_farewell(void * person)
{
    printf("heippa!\n");
}

void english_farewell(void * person)
{
    printf("bye!\n");
}

int main() {
    farewell(person0);
    farewell(person1);
    farewell(person2);
    return 0;
}
