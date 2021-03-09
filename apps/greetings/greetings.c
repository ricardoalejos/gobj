#include <stdio.h>
#include "gobj.h"

GOBJ_DECLARE(person_attr, {char * name;});
GOBJ_INIT_ID(person_attr);
GOBJ_DECLARE(person_ifc, {void (*greet)(void * person);});
GOBJ_INIT_ID(person_ifc);

void spanish_greeting(void * person);
void finnish_greeting(void * person);
void english_greeting(void * person);

void * person0 = GOBJ_ST(
    GOBJ_ITR(person_attr, .name="Ricardo"),
    GOBJ_ITR(person_ifc, .greet=spanish_greeting)
);

void * person1 = GOBJ_ST(
    GOBJ_ITR(person_attr, .name="Petri"),
    GOBJ_ITR(person_ifc, .greet=finnish_greeting)
);

void * person2 = GOBJ_ST(
    GOBJ_ITR(person_attr, .name="Fred"),
    GOBJ_ITR(person_ifc, .greet=english_greeting)
);

void greet(void * person)
{
    printf("%s says: ", GOBJ_GET_ATTR(person, person_attr)->name);
    GOBJ_GET_ATTR(person, person_ifc)->greet(person);
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
