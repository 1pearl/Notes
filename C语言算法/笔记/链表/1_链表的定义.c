#include <stdio.h> 
#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode{
	int value;
	ListNode* next; 
};

ListNode* CreateListNode(int value) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->value = value;
	node->next = NULL;
	return node;
}

int main() {
	ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
	ListNode* node3 = CreateListNode(3);
    ListNode* node4 = CreateListNode(4);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	
	int i;
	ListNode* temp = node1;
	for(i=0;i<3;i++){
		printf("%d->",temp->value);
		temp = temp->next;
	}
	printf("%d->NULL\n",node4->value); 
	
	temp = node1;
	while(temp) { 
		printf("%d->",temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
	
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	  
	return 0;
}
