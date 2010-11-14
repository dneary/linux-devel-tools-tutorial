#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct person {
    int id;
    char *name;
};

struct node {
    struct node *next;
    struct node *prev;

    struct person *p;
};

struct node *create_person (int id, char *name)
{
    struct node *n = malloc (sizeof (struct node));
    struct person *p = malloc (sizeof (struct person));

    p->id = id;
    p->name = strdup(name); /* Possible leak, if we don't free name */

    n->prev = NULL;
    n->next = NULL;
    n->p = p;

    return n;
}

void add_person(struct node *node, struct node *person)
{
    struct node *tmp;

    if (node == NULL) {
	fprintf(stderr, "add_person\n");
        exit(1);
    }
    tmp = node->next;

    node->next = person;
    person->prev = node;

    person->next = tmp;
    if (tmp != NULL)
        tmp->prev = person;
    

}

void delete_person (struct node *n)
{
    struct node *prev = n->prev;
    struct node *next = n->next;

    if (prev == NULL && next == NULL ) {
        ;
    } else if (prev == NULL) {
        next->prev = NULL;
    } else if (next == NULL) {
        prev->next = NULL;
    } else {
        next->prev = n->prev;
        prev->next = n->next;
    }

    free(n->p->name);
    free(n->p);
    free(n);
    n = NULL;

    return;
}

void write_list (struct node *list)
{

    for(;list;list = list->next) {
        printf("id = %d\nName = %s\n\n", list->p->id, list->p->name);
    }

    return;
}

int main (void)
{
    struct node *list = NULL, *last_node, *n;
    char name [30];
    int i;

    list = create_person (1, "Joe Bloggs 1");
    last_node = list;

    for (i = 0; i < 10000; i++) {
        sprintf(name, "Joe Bloggs %d", i);
        n = create_person (i, name);
        add_person (last_node, n);
        last_node = n;
    }
    
    for (n=list; n; ) {
        struct node *next = n->next;
        if (n->p->id % 2 == 0) {
            delete_person(n);
        }
        n = next;
    }
    
    write_list (list);

    return EXIT_SUCCESS;
}

