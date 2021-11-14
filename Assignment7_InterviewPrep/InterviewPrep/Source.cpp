#include <stdio.h>
#include<assert.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

//reverse the linked list 
static void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next = NULL;
	while (current != NULL) {
		// Store next
		next = current->next;

		// Reverse current node's pointer
		current->next = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

//add new node
void push_front(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
	assert(new_node);
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

//print linked list
void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


int main()
{
	int arr[] = { 50,40,30,20,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	struct Node* head = NULL;

	for (size_t i = 0; i < len; i++)
	{
		push_front(&head, arr[i]);
	}

	printf("Original linked list: ");
	printList(head);
	reverse(&head);
	printf("\nReversed Linked list: ");
	printList(head);

	return 0;
}
