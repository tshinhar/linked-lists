#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"

int main() {
	Node* head = NULL;
	for (int i = 1; i < 4; i++)
	{
		Node* new_node = create_new_node(i);
		head = add_to_list_end(head,new_node);
	}
	print_list(head);
	Node* help_node = create_new_node(0);
	head = add_to_list_start(head, help_node);
	print_list(head);
	print_node_index(head, 3);
	head = delete_by_index(head, 3);
	print_list(head);
	help_node = create_new_node(3);
	head = add_after_specific_node(head, 2, help_node);
	print_list(head);
	return 0;
}