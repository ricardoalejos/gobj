#include <stdio.h>
#include "gobj.h"

GOBJ_DECLARE_TYPE(person_attr, {char * name;})
GOBJ_DECLARE_TYPE(person_ifc, {void (*greet)(void * person);})

void spanish_greeting(void * person);
void finnish_greeting(void * person);
void english_greeting(void * person);

struct gobj person0 = {
    .attrs = GOBJ_SINIT_TABLE(GOBJ_SINIT_RECORD(person_attr, {.name="Ricardo"})),
    .ifcs = GOBJ_SINIT_TABLE(GOBJ_SINIT_RECORD(person_ifc, {.greet=spanish_greeting}))
};

struct gobj person1 = {
    .attrs = GOBJ_SINIT_TABLE(GOBJ_SINIT_RECORD(person_attr, {.name="Petri"})),
    .ifcs = GOBJ_SINIT_TABLE(GOBJ_SINIT_RECORD(person_ifc, {.greet=finnish_greeting}))
};

struct gobj person2 = {
    .attrs = GOBJ_SINIT_TABLE(GOBJ_SINIT_RECORD(person_attr, {.name="Fred"})),
    .ifcs = GOBJ_SINIT_TABLE(GOBJ_SINIT_RECORD(person_ifc, {.greet=finnish_greeting}))
};

void greet(void * person)
{
    printf("%s says: ", GOBJ_INTERPRET_ATTR(person, person_attr)->name);
    GOBJ_INTERPRET_IFC(person, person_ifc)->greet(person);
}

void spanish_greeting(void * person)
{
    printf("hola!\n");
}

void finnish_greeting(void * person)
{
    printf("moi!\n");
}

void english_greeting(void * person)
{
    printf("hello!\n");
}

int main() {
    greet(&person0);
    greet(&person1);
    greet(&person2);
    return 0;
}
