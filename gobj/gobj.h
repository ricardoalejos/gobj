#ifndef _GOBJ_H_
#define _GOBJ_H_

typedef struct tr
{
    void * id;
    void * val;
} gobj_tr_t;

#define GOBJ_ST(...) (struct tr * []){__VA_ARGS__, NULL}
#define GOBJ_ETR(type, ...) {.id=&type##_id, .val=(struct type []){{__VA_ARGS__}}}
#define GOBJ_ITR(type, ...) (struct tr *)&(struct tr []){{.id=&type##_id, .val=(struct type []){{__VA_ARGS__}}}}
#define GOBJ_DECLARE(type, structure) struct type structure; void * type##_id;
#define GOBJ_GET_ATTR(obj, attr_type) ((struct attr_type *)get_attr(obj, &attr_type##_id))

void * get_attr(void * obj, void * attr_id);

#endif
