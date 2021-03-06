#include <stddef.h>
#include "gobj.h"

void * get_attr(void * obj, void * attr_id)
{
    struct tr ** attr_table= obj;
    int i = 0;
    while(attr_table[i] != NULL)
    {
        if(attr_table[i]->id == attr_id)
        {
            return attr_table[i]->val;
        }
        i++;
    }
    return NULL;
}
