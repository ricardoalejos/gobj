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

![GOBJ object structure in C language](doc/../docs/gobj_object.svg)

**Figure 1** - GOBJ object structure in C language.

Check out the use examples in the "app" directory. We have added the code and the output of the "farewells" application in Listings 1 and 2 for quick reference.

```c
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
```

**Listing 1** - The "farewells" application body.

```shell
$ ./bin/app_farewells 
Ricardo says: adios!
Ricardo waves the hand.
Cecilia says: adios!
Cecilia waves the hand.
Mikko says: heippa!
Mikko waves the hand.
Pointer to useless attribute is (nil).
```

**Listing 2** - The console output of the app/greetings application.

The "farewells" application uses static object allocation, which is nice for embedded systems. Check out the "animals" application to see a demonstration of dynamic object creation.

## Build, install, and usage

For building this project, you will need `cmake`. 

```shell
./build.sh
```

**Listing 3** - Build command.

```shell
sudo ./install.sh
```

**Listing 4** - Install command.

```shell
gcc your_program.c -o your_program -lgobj
```

**Listing 5** - How to link your programs to the GOBJ library.
