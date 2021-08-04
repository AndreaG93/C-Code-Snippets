//
// Created by andrea on 04/08/21.
//

#ifndef C_CODE_SNIPPETS_UNTESTED_MERGESORT_H
#define C_CODE_SNIPPETS_UNTESTED_MERGESORT_H

typedef struct {
    void *data;
    void *next;
} ListNode;

typedef struct {
    unsigned long size;
    ListNode *head;
    ListNode *tail;
} List;

List *mergesort(List *list);
List *allocate_new_list();
void insert(List *list, void *data);
void print(List *list);
List* merge(List* list1, List* list2);

#endif //C_CODE_SNIPPETS_UNTESTED_MERGESORT_H
