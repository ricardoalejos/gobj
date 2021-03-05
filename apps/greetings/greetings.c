#include <stdio.h>
#include "gobj.h"

GOBJ_DECLARE_TYPE(person_attr, {char * name;})
GOBJ_DECLARE_TYPE(person_ifc, {void (*greet)(void * person);})

void spanish_greeting(void * person);
void finnish_greeting(void * person);
void english_greeting(void * person);

void * person0 = GOBJ_SINIT_TABLE(
    GOBJ_SINIT_RECORD(person_attr, .name="Ricardo"),
    GOBJ_SINIT_RECORD(person_ifc, .greet=spanish_greeting)
);

void * person1 = GOBJ_SINIT_TABLE(
    GOBJ_SINIT_RECORD(person_attr, .name="Petri"),
    GOBJ_SINIT_RECORD(person_ifc, .greet=finnish_greeting)
);

void * person2 = GOBJ_SINIT_TABLE(
    GOBJ_SINIT_RECORD(person_attr, .name="Fred"),
    GOBJ_SINIT_RECORD(person_ifc, .greet=english_greeting)
);

void greet(void * person)
{
    printf("%s says: ", GOBJ_INTERPRET_ATTR(person, person_attr)->name);
    GOBJ_INTERPRET_ATTR(person, person_ifc)->greet(person);
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
    greet(person0);
    greet(person1);
    greet(person2);
    return 0;
}
