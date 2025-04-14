#include <stdio.h> 
#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode {
	int value;
	ListNode* next; 
};

ListNode* CreateListNode(int value) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->value = value;
	node->next = NULL;
	return node;
}

//直接删除结点 
struct ListNode* removeElements_1(struct ListNode* head, int val) {
       //特殊情况，头节点为目标结点
	   while(head != NULL && head->value == val){
	   	     ListNode* temp = head;
			 head = head->next;
			 free(temp);
	   } 
	   //一般情况，中间结点为目标结点
	   ListNode* cur = head;
	   while(cur != NULL && cur->next != NULL){
	   	     if(cur->next->value == val){
	   	         ListNode* temp = cur->next;
				 cur->next = cur->next->next;
				 free(temp);		
			} else {
				 cur = cur->next;
			}
	   }
	   return head; 
}

//虚拟头节点删除结点 
struct ListNode* removeElements_2(struct ListNode* head, int val) {
       ListNode* dummyNode = CreateListNode(0);
       dummyNode->next = head;
       ListNode* cur = dummyNode;
       while(cur->next != NULL){
            if(cur->next->value == val){
            	ListNode* temp = cur->next;
            	cur->next = cur->next->next;
				free(temp); 
			}else{
				cur = cur->next;
			}   	
	   }
	   head = dummyNode->next;
	   return head;
}

void printList(ListNode* head) {
	ListNode* temp = head;
	while(temp){
		printf("%d->",temp->value);
		temp = temp->next;
	}
    printf("NULL\n");
} 

int main() {
	ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
	ListNode* node3 = CreateListNode(3);
    ListNode* node4 = CreateListNode(4);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	
    printList(node1);
    removeElements_2(node1, 2);
    printList(node1);
	
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	  
	return 0;
}
