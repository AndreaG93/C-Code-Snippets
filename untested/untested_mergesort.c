//
// Created by andrea on 04/08/21.
//

#include "untested_mergesort.h"

#include <stdio.h>
#include <stdlib.h>
#include "errno.h"

List *allocate_new_list() {

    List *output = malloc(sizeof(List));
    if (output != NULL) {

        output->size = 0;
        output->head = NULL;
        output->tail = NULL;
    }

    return output;
}

ListNode *allocate_new_list_node(void *data) {

    ListNode *output = malloc(sizeof(ListNode));
    if (output != NULL) {
        output->data = data;
        output->next = NULL;
    }

    return output;
}

void insert(List *list, void *data) {

    ListNode *new_node = allocate_new_list_node(data);

    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void insert_node(List *list, ListNode *new_node) {

    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void print(List *list) {

    ListNode *current_node = list->head;

    fprintf(stdout, "List's size : %lu\nList's items:\n", list->size);
    while (current_node != NULL) {

        fprintf(stdout, "\t%d\n", (int) *((int *) current_node->data));

        current_node = current_node->next;
    }
}


List **divide(List *list) {

    List **output = malloc(sizeof(List *) * 2);
    if (output == NULL)
        exit(EXIT_FAILURE);

    output[0] = allocate_new_list();
    output[1] = allocate_new_list();

    ListNode* current_node = list->head;

    while (current_node != NULL) {

        if (output[0]->size < list->size / 2)
            insert_node(output[0], current_node);
        else
            insert_node(output[1], current_node);

        current_node = current_node->next;
    }

    output[0]->tail->next = NULL;
    output[1]->tail->next = NULL;

    return output;
}

List *mergesort(List *list) {

    if (list->size <= 1)
        return list;

    List** separated_list = divide(list);

    List *left_list = separated_list[0];
    List *right_list = separated_list[1];

    left_list = mergesort(left_list);
    right_list = mergesort(right_list);

    list = merge(left_list, right_list);
    free(separated_list);

    return list;
}

List *merge(List *list1, List *list2) {

    ListNode *current_node_1 = list1->head;
    ListNode *current_node_2 = list2->head;

    List *output = list1;

    output->size = 0;
    output->head = NULL;
    output->tail = NULL;

    while (current_node_1 != NULL && current_node_2 != NULL) {

        int value_1 = (int) *((int *) current_node_1->data);
        int value_2 = (int) *((int *) current_node_2->data);

        if (value_1 <= value_2) {

            insert_node(output, current_node_1);
            current_node_1 = current_node_1->next;

        } else {

            insert_node(output, current_node_2);
            current_node_2 = current_node_2->next;
        }
    }

    while (current_node_1 != NULL) {
        insert_node(output, current_node_1);
        current_node_1 = current_node_1->next;
    }

    while (current_node_2 != NULL) {
        insert_node(output, current_node_2);
        current_node_2 = current_node_2->next;
    }

    free(list2);

    return output;
}