#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H

typedef struct ListNode {
	int data;
	struct ListNode *next;
}ListNode;

ListNode *addNode(ListNode *head, int data, int type); /* Type: 0; adding from the beginning, 1; adding from the end, 2; adding with respectively*/

ListNode *deleteNode(ListNode *head, int data);

ListNode *deleteNodeNth(ListNode *head, int n);

ListNode *mergeLists(ListNode *head, ListNode *head2, int list1_size, int list2_size);

ListNode *maxNode(ListNode *const head);

ListNode *minNode(ListNode *const head);

int maxVal(ListNode *const head);

int minVal(ListNode *const head);

int isEmpty(ListNode *const head);

int isExist(ListNode *const head, int data);

int count(ListNode *const head);

void printList(ListNode *const head);

#endif