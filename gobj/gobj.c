#include <stdlib.h>
#include <stdint.h>
#include "gobj.h"

void * gobj_get_attr(void * obj, void * attr_id)
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

void * gobj_create(size_t ** id_list)
{
    // Compute table size, and the size required to store attributes
    size_t table_size = 0;
    size_t attr_size = 0;
    size_t object_size = 0;
    uint8_t * object_base_address;
    while(id_list[table_size] != NULL)
    {
        attr_size += *(id_list[table_size++]);
    }

    // Allocate space for the entire object
    object_size = (
        (table_size + 1) * sizeof(struct tr *) +
        table_size * sizeof(struct tr) +
        attr_size
    );
    object_base_address = (uint8_t *)malloc(object_size);
    if (!object_base_address) return NULL;

    // Place the table, records, and attribute pointers within the object
    struct tr ** table = (struct tr **)object_base_address;
    struct tr * records = (struct tr *)(
        object_base_address +
        (table_size + 1) * sizeof(struct tr *)
    );
    uint8_t * attr = (
        object_base_address +
        (table_size + 1) * sizeof(struct tr *) +
        table_size * sizeof(struct tr)
    );

    // Fill table with records, and fill records with the attribute data
    table[table_size] = NULL;
    for(int i = 0; i < table_size; i++)
    {
        table[i] = &(records[i]);
        table[i]->id = id_list[i];
        table[i]->val = attr;
        attr += *id_list[i];
    }

    return table;
}

void gobj_delete(void * gobj)
{
    // Delete the object from its base address
    free(gobj);
}


char * gobj_get_version()
{
    return GOBJ_VERSION;
}
