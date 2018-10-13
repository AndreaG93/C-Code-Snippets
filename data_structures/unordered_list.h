 /*
  ============================================================================
  Name        : UnorderedList.c
  Author      : Andrea Graziani
  Version     : 1.0
  Description : ANSI C implemetation of an anordered list. (HEADER)
  ============================================================================
  */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct list_node {

	void *data;
	struct list_node* next;

} UnorderedListNode;

typedef struct list {

	unsigned long length;
	UnorderedListNode *head;
	UnorderedListNode *tail;

} UnorderedList;


UnorderedList* get_unordered_list();
void insert(UnorderedList*, void *);
void perform_action(UnorderedList* , void(*)(void *));
void *get(UnorderedList *, unsigned int );