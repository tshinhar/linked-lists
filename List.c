#include <stdlib.h>
#include <stdio.h>
#include "List.h"

Node* create_new_node(int value) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}

void free_list_memory(Node* head) {
	while (head != NULL) {
		Node* next_node = head->next;
		free(head);
		head = next_node;
	}
}

Node* add_to_list_start(Node* head, int value) {
	Node* new_node = create_new_node(value);
	new_node->next = head;
	return new_node;
}

Node* add_to_list_end(Node* head, int value) {
	Node* new_node = create_new_node(value);
	if (head == NULL)
		return new_node;
	Node* current_node = head;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	current_node->next = new_node;
	return head;
}

Node* add_after_specific_node(Node* head, int after_value, int new_value) {
	Node* new_node = create_new_node(new_value);
	Node* current_node = head;
	while (current_node->data != after_value) {
		if (current_node->next == NULL) {
			printf("Error - the target node is not in the list");
			free_list_memory(head);
			return NULL;
		}
		current_node = current_node->next;
	}
	Node* helper_node = current_node->next;
	current_node->next = new_node;
	new_node->next = helper_node;
	return head;
}

void print_node_index(Node* head, int value_target) {
	Node* current_node = head;
	int index = 0;
	while (current_node != NULL) {
		if (current_node->data == value_target) {
			printf("%d\n", index);
			return;
		}
		current_node = current_node->next;
		index++;
	}
	printf("%d\n", -1);
}

Node* delete_by_index(Node* head, int index) {
	if (index == 0) {
		Node* new_head = head->next;
		free(head);
		return new_head;
	}
	Node* current_node = head, * previous_node = current_node;
	for (int i = 0; i < index; i++)
	{
		if (current_node == NULL) {
			printf("the given index is too large");
			free_list_memory(head);
			return NULL;
		}
		previous_node = current_node;
		current_node = current_node->next;
	}
	previous_node->next = current_node->next;
	free(current_node);
	return head;
}

void print_list(Node* head) {
	if (head == NULL) {
		printf("[]\n");
		return;
	}
	Node* current_node = head;
	printf("[");
	while (current_node->next != NULL) {
		printf("%d, ", current_node->data);
		current_node = current_node->next;
	}
	printf("%d]\n", current_node->data);
}