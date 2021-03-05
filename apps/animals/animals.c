#include <stdio.h>
#include "gobj.h"

GOBJ_DECLARE_TYPE(animal_attr, {char * name; char * sound;})
GOBJ_DECLARE_TYPE(animal_ifc, {void (*attack)(void * animal);})

void bite(void * dog);
void scratch(void * cat);

struct gobj rufus = {
    .attrs = GOBJ_SINIT_TABLE(
        GOBJ_SINIT_RECORD(animal_attr, .name="Rufus", .sound="woof!"),
        GOBJ_SINIT_RECORD(animal_ifc, .attack=bite)
    )
};

struct gobj misifus = {
    .attrs = GOBJ_SINIT_TABLE(
        GOBJ_SINIT_RECORD(animal_attr, .name="Misifus", .sound="meow!"),
        GOBJ_SINIT_RECORD(animal_ifc, .attack=scratch)
    )
};

void make_sound(void * animal)
{
    printf(
        "%s says %s\n",
        GOBJ_INTERPRET_ATTR(animal, animal_attr)->name,
        GOBJ_INTERPRET_ATTR(animal, animal_attr)->sound
    );
}

void bite(void * dog)
{
    printf(
        "%s has biten someone!\n",
        GOBJ_INTERPRET_ATTR(dog, animal_attr)->name
    );
}

void scratch(void * cat)
{
    printf(
        "%s has scratched someone!\n",
        GOBJ_INTERPRET_ATTR(cat, animal_attr)->name
    );
}

void attack(void * animal)
{
    GOBJ_INTERPRET_ATTR(animal, animal_ifc)->attack(animal);
}

int main() {
    make_sound(&rufus);
    attack(&rufus);
    make_sound(&misifus);
    attack(&misifus);
    return 0;
}
