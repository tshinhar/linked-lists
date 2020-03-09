#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next
}Node;

Node* create_new_node(int value) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;
}

Node* add_to_list_start(Node* head, Node* new_node) {
	new_node->next = head;
	return new_node;
}

Node* add_to_list_end(Node* head, Node* new_node) {
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

Node* add_after_specific_node(Node* head, int value_target, Node* new_node) {
	Node* current_node = head;
	while (current_node->data != value_target) {
		if (current_node == NULL) {
			printf("Error - the taarget node is not in the list");
			/// exit the program
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
	while (current_node->data != value_target) {
		if (current_node == NULL) {
			printf("%d", -1);
			break;
		}
		current_node = current_node->next;
		index++;
	}
	printf("%d", index);
}

Node* delete_by_index(Node* head, int index) {
	if (index == 0)
		return head->next;
	Node *current_node = head, * previous_node=current_node;
	for (int i = 0; i < index; i++)
	{
		if (current_node == NULL) {
			printf("the given index is too large");
			/// exit the program
		}
		previous_node = current_node;
		current_node = current_node->next;
	}
	previous_node->next = current_node->next;
	free(current_node);
	return head;
}
