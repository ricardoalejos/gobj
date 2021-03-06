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
    while(id_list[table_size] != NULL)
    {
        attr_size += *(id_list[table_size++]);
    }

    // Allocate pointers to the table (array of pointers to records)
    struct tr ** table = (struct tr **)malloc((table_size + 1) * sizeof(struct tr *));
    if (!table) return NULL;

    // Allocate records
    struct tr * records = (struct tr *)malloc(table_size * sizeof(struct tr));
    if (!records)
    {
        free(table);
        return NULL;
    }

    // Allocate memory for all attributes
    uint8_t * attr = (uint8_t *)malloc(attr_size);
    if (!attr)
    {
        free(table);
        free(records);
        return NULL;
    }

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
    struct tr ** table = gobj;

    // Delete block with attributes from the base
    free(table[0]->val);

    // Delete block with records from the base
    free(table[0]);

    // Delete table
    free(table);
}
