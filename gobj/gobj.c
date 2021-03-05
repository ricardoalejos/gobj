#include <stddef.h>
#include "gobj.h"

void * get_attr(void * obj, void * attr_id)
{
    struct gobj * gobj0 = obj;
    int i = 0;
    while(gobj0->attrs[i].id != NULL)
    {
        if(gobj0->attrs[i].id == attr_id)
        {
            return gobj0->attrs[i].val;
        }
        i++;
    }
    return NULL;
}
