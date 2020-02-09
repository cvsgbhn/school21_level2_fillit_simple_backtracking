#include "../includes/fillit.h"

t_element	*create_t_element(char letter)
{
    t_element	*newlist;
    int     counter;

    counter = -1;
    newlist = (t_element*)malloc(sizeof(struct s2_list));
    if (!newlist)
    {
        free(newlist);
        return (NULL);
    }
    newlist->next = NULL;
    while(counter++ < 4)
    {
        newlist->x_coords[counter] = 0;
        newlist->y_coords[counter] = 0;
    }
    newlist->x_shift = 0;
    newlist->y_shift = 0;
    newlist->letter = letter;
    return (&newlist);
}

void	add_last_t_element(t_element** head, t_element *new_node)
{
    t_element* last;

    last = *head;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
