#ifndef LIST_H
#define LIST_H

typedef struct node {
	int data;
	struct node* next;
}Node;

void free_list_memory(Node* head);

Node* add_to_list_start(Node* head, int value);

Node* add_to_list_end(Node* head, int value);

Node* add_after_specific_node(Node* head, int after_value, int new_value);

void print_node_at_index(Node* head, int value_target);

Node* delete_by_index(Node* head, int index);

void print_list(Node* head);

#endif
