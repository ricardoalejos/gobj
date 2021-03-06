# GOBJ - Generic Object Library

The purpose of this library is to abstract the essential characteristics of objects used for Object-Oriented Programming:

- attributes, and
- behaviors.

Let us assume that we can define any class C[i] as a set S[i] of J structures {S[i][1], S[i][2], ... S[i][J]}. These structures may define a set of attributes (variables), interfaces (functions), or both. Also, let us expand our notation such that O[i][j] refers to the j-th object of the class C[i].

With our definitions:

- A class C[child] **inherits** from the class C[parent] if S[parent] is a subset of S[child].
- An interface S[parent][interface] can run for the classes C[parent] and C[child] in a **polymorphic** fashion.
- We can hide all our implementations under generic pointers (`void *`) to achieve **encapsulation**.

To achieve the definition of classes, we have to identify all possible members of the sets S[n]. For this purpose, we have defined a set of macros that create one auxiliary variable V[n][j] for each structure S[n][j], whose address becomes its identifier. Finally, we can describe any object as a table whose records have the form (V[n][j], S[n][j]) - in the code, such table is a NULL-terminated array of records-.

Check out the use examples in the "app" directory. We have added the code and the output of the "farewells" application in Listings 1 and 2 for quick reference.

```c
#include <stdio.h>
#include "gobj.h"

GOBJ_DECLARE(person_attr, {char * name;})
GOBJ_DECLARE(person_ifc, {void (*farewell)(void * person);})
GOBJ_DECLARE(useless_attr, {char * useless;})

void spanish_farewell(void * person);
void finnish_farewell(void * person);

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

// Static creation of a table
void * person2 = GOBJ_ST(
    // We add a different implementation of the farewell interface
    GOBJ_ITR(person_ifc, .farewell=finnish_farewell),
    GOBJ_ITR(person_attr, .name="Mikko")
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

void finnish_farewell(void * person)
{
    printf("heippa!\n");
}

int main() {
    // Let us execute the farewell function for each person
    farewell(person0);
    farewell(person1);
    farewell(person2);
    // Try to get an attribute that is not in the object
    void * result = GOBJ_GET_ATTR(person0, useless_attr);
    printf("Pointer to useless attribute is %p.\n", result);
    return 0;
}
```

**Listing 1** - The "farewells" application body.

```shell
$ ./bin/app_farewells 
Ricardo says: adios!
Cecilia says: adios!
Mikko says: heippa!
Pointer to useless attribute is (nil).
```

**Listing 2** - The console output of the app/greetings application.
