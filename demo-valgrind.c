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

void delete_person (struct node *p)
{
    struct node *prev = p->prev;
    struct node *next = p->next;

    if (prev == NULL && next == NULL ) {
        ;
    } else if (prev == NULL) {
        next->prev = NULL;
    } else if (next == NULL) {
        prev->next = NULL;
    } else {
        next->prev = p->prev;
        prev->next = p->next;
    }

    free(p);
    p = NULL;
    /* Leak - we need to free the person & name too */
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
    struct node *head = NULL, *tail = NULL, *n;

    head = create_person (1, "Dave Neary");
    tail = head;

    n = create_person (2, "Thomas Perl");
    tail->next = n;
    n->prev = tail;
    tail = n;
    
    n = create_person (3, "Alison Chaiken");
    tail->next = n;
    n->prev = tail;
    tail = n;
    
    n = create_person (4, "Andrea Grandi");
    tail->next = n;
    n->prev = tail;
    tail = n;
    
    n = create_person (5, "Kevin Ottens");
    tail->next = n;
    n->prev = tail;
    tail = n;
    
    for (n=head; n; ) {
        struct node *next = n->next;
        if (n->p->id % 2 == 0) {
            delete_person(n);
        }
        n = next;
    }
    n = create_person (6, "Bob Spencer");
    tail->next = n;
    n->prev = tail;
    tail = n;
    
    write_list (head);

    return EXIT_SUCCESS;
}

