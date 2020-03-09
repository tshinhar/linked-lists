#ifndef LIST_H
#define LIST_H

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* create_new_node(int value);

void free_list_memory(Node* head);

Node* add_to_list_start(Node* head, Node* new_node);

Node* add_to_list_end(Node* head, Node* new_node);

Node* add_after_specific_node(Node* head, int value_target, Node* new_node);

void print_node_index(Node* head, int value_target);

Node* delete_by_index(Node* head, int index);

void print_list(Node* head);

#endif