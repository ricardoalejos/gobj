#ifndef _GOBJ_H_
#define _GOBJ_H_

struct tr
{
    void * id;
    void * val;
};

#define GOBJ_SINIT_TABLE(...) (struct tr []){__VA_ARGS__, {.id=NULL, .val=NULL}}
#define GOBJ_SINIT_RECORD(type, ...) {.id=&type##_id, .val=(struct type []){{__VA_ARGS__}}}
#define GOBJ_DECLARE_TYPE(type, structure) struct type structure; void * type##_id;
#define GOBJ_INTERPRET_ATTR(obj, attr_type) ((struct attr_type *)get_attr(obj, &attr_type##_id))

void * get_attr(void * obj, void * attr_id);

#endif
