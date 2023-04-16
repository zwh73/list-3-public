#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"


struct singly_linked_list *init_list( struct singly_linked_list *t )
{
	t->head = NULL;
	t->count = 0;

	return t;
}

struct singly_linked_list *create_list()
{
    struct singly_linked_list *t = (struct singly_linked_list *)malloc( sizeof(struct singly_linked_list) );

	return init_list( t );
}

struct node *create_node( T e )
{
	struct node *p = (struct node *)malloc( sizeof(struct node) );

	p->data = e;
	p->next = NULL;

	return p;
}
struct singly_linked_list *insert(struct singly_linked_list *t, int i, T e)
{
	assert( i >= 0 && i <= t->count );
	struct node *p = create_node(e);
	if ( i == 0 ) 
	{
		p->next = t->head;
		t->head = p;
	} 
	else
	{
		struct node *q = t->head;
		for ( int j = 0; j < i-1; j++ ) {
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
	}
	t->count++;
	return t;
}

struct singly_linked_list *delete_at(struct singly_linked_list *t, int i)
{
	assert( i >= 0 && i < t->count );

	struct node *p, *q;

	if ( i == 0 )
	{
		p = t->head;
		t->head = p->next;
	} 
	else 
	{
		q = t->head;
		for ( int j = 0; j < i-1; j++ )
		{
			q = q->next;
		}
		p = q->next;
		q->next = p->next;
	}
	free(p);
	t->count--;
	return t;
}

int size( struct singly_linked_list *t )
{
	return t->count;
}

T get( struct singly_linked_list *t, int i )
{
	assert( i >= 0 && i < t->count );
	struct node *p = t->head;
	for ( int j = 0; j < i; j++ ) 
	{
		p = p->next;
	}
	return p->data;
}

void replace( struct singly_linked_list *t, int i, T e )
{
	assert( i >= 0 && i < t->count );
	struct node *p = t->head;
	for ( int j = 0; j < i; j++ ) 
	{
		p = p->next;
	}
	p->data = e;
}

int index( struct singly_linked_list *t, T e )
{
	struct node *p = t->head;
	int i = 0;
	while ( p != NULL && p->data != e )
	{
		p = p->next;
		i++;
	}

	if ( p == NULL ) 
	{
		return -1;
	}
	else 
	{
		return i;
	}
}
