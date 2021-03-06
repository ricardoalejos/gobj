#ifndef _GOBJ_H_
#define _GOBJ_H_

#include <stddef.h>

typedef struct tr
{
    void * id;
    void * val;
} gobj_tr_t;

// Attribute type declaration and access macros
#define GOBJ_DECLARE(type, structure) struct type structure; size_t type##_id = sizeof(struct type);
#define GOBJ_GET_ATTR(obj, attr_type) ((struct attr_type *)gobj_get_attr(obj, &attr_type##_id))

// Static object creation macros
#define GOBJ_ST(...) (struct tr * []){__VA_ARGS__, NULL}
#define GOBJ_ETR(type, ...) {.id=&type##_id, .val=(struct type []){{__VA_ARGS__}}}
#define GOBJ_ITR(type, ...) (struct tr *)&(struct tr []){{.id=&type##_id, .val=(struct type []){{__VA_ARGS__}}}}

/* Dynamic object creation and deletion macros
```c
// Creation
void * object = GOBJ_CREATE(GOBJ_GET_ID(type_0), GOBJ_GET_ID(type_1), ...);
// Deletion
gobj_delete(object);
```
*/
#define GOBJ_GET_ID(type) &type##_id
#define GOBJ_CREATE(...) gobj_create((size_t **)(size_t * []){__VA_ARGS__, NULL})

void * gobj_get_attr(void * obj, void * attr_id);
void * gobj_create(size_t ** id_list);
void gobj_delete(void * gobj);

#endif
