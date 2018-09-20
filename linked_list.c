// singly-linked list
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int maxVal(ListNode *const head) {
	ListNode *ptr = head;
	int max = ptr != NULL ? ptr->data : 0;
	while(ptr != NULL) {
		max = ptr->data > max ? ptr->data : max;
		ptr = ptr->next;
	}
	return max;
}

int minVal(ListNode *const head) {
	ListNode *ptr = head;
	int min = ptr != NULL ? ptr->data : 0;
	while(ptr != NULL) {
		min = ptr->data < min ? ptr->data : min;
		ptr = ptr->next;
	}
	return min;
}

void printList(ListNode *const head) {
	ListNode *ptr = head;
	while(ptr != NULL) {
		printf("Data: %d\n", ptr->data);
		ptr = ptr->next;
	}
}

int isEmpty(ListNode *const head) {
	return head == NULL ? 1 : 0;
}

int isExist(ListNode *const head, int data) {
	ListNode *ptr = head;
	int flag = 0;
	while(ptr != NULL) {
		if(ptr->data == data) {
			flag = 1;
			break;
		}
		ptr = ptr->next;
	}
	return flag;
}

int count(ListNode *const head) {
	ListNode *ptr = head;
	int count = 0;
	while(ptr != NULL) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

ListNode *maxNode(ListNode *const head) {
	ListNode *ptr = head;
	ListNode *max = ptr;
	while(ptr != NULL) {
		max = ptr->data > max->data ? ptr : max;
		ptr = ptr->next;
	}
	return max;
}

ListNode *minNode(ListNode *const head) {
	ListNode *ptr = head;
	ListNode *min = ptr;
	while(ptr != NULL) {
		min = ptr->data < min->data ? ptr : min;
		ptr = ptr->next;
	}
	return min;
}

ListNode *addNode(ListNode *head, int data, int type) {
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
	ListNode *tail = head, *ptr = head, *prior = head;
	temp->data = data;
	temp->next = NULL;
	if(head == NULL) {
		head = temp;
	} else {
		if(type == 0) {
			temp->next = head;
			head = temp;
		}

		else if (type == 1) {
			while(tail->next != NULL) tail = tail->next;
			tail->next = temp;
		}

		else if(type == 2) {
			while(ptr->next != NULL && ptr->data < data) {
				prior = ptr;
				ptr = ptr->next;
			}
			if(ptr->data < data) {
				ptr->next = temp;
			}
			else {
				if(ptr == head) {
					temp->next = prior;
					head = temp;
				} else if(prior->next == NULL) {
					prior->next = temp;
				} else {
					prior->next = temp;
					temp->next = ptr;
				}
			}
		}

		else {
			printf("Please, enter 0-2");
			exit(1);
		}
	}
	return head;
}

ListNode *deleteNode(ListNode *head, int data) {
	ListNode *ptr = head, *prior = NULL;
	while(ptr != NULL) {
		if(ptr->data == data) {
			if(ptr == head) {
				head = ptr->next;
				free(ptr);
			} else {
				prior->next = ptr->next;
				free(ptr);
			}
			return head;
		} else {
			prior = ptr;
			ptr = ptr->next;
		}
	}
	printf("The node to be deleted (Data: %d) is not found\n", data);
	exit(1);
}

ListNode *mergeLists(ListNode *head, ListNode *head2, int list1_size, int list2_size) {
	ListNode *head3 = NULL, *ptr = NULL;
	int i = 1;
	while(i <= list1_size + list2_size) {
		if(head == NULL && head2 != NULL)
			ptr = head2;
		else if(head2 == NULL && head != NULL)
			ptr = head;
		else if(head == NULL && head2 == NULL)
			break;
		else {
			if(head->data < head2->data)
				ptr = head;
			else if(head->data > head2->data)
				ptr = head2;
		}
		head3 = addNode(head3, ptr->data, 1);
		if(ptr == head)
			head = head->next;
		else
			head2 = head2->next;
		i++;
	}
	return head3;
}

ListNode *deleteNodeNth(ListNode *head, int n) {
	ListNode *ptr = head, *prior = NULL;
	int num = 1;
	while(ptr != NULL) {
		if(n == num) {
			if(ptr == head) {
				head = ptr->next;
				free(ptr);
			} else {
				prior->next = ptr->next;
				free(ptr);
			}
			return head;
		} else {
			prior = ptr;
			ptr = ptr->next;
			num++;
		}
	}
	printf("The node to be deleted is not found\n");
	exit(1);
}

int main(void) {
	/* test */
	ListNode *head = NULL, *head2 = NULL, *head3 = NULL;
	head = addNode(head, 3, 1);
	head = addNode(head, 5, 1);
	head = addNode(head, 6, 1);
	head = addNode(head, 9, 1);
	head = addNode(head, 10, 1);

	head2 = addNode(head2, 7, 1);
	head2 = addNode(head2, 8, 1);
	head2 = addNode(head2, 1, 1);

	head3 = mergeLists(head, head2, count(head), count(head2));
	printList(head3);
	return 0;
}