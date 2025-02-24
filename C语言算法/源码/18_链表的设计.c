#include <stdio.h>
#include <stdlib.h>
 
//创建链表结点 
typedef struct ListNode{
	int val;
	struct ListNode* next;
}ListNode; 

//创建链表类 
typedef struct {
    ListNode* head;
    int size;
} MyLinkedList;

//初始化链表 
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

//返回链表下标为index的值 
int myLinkedListGet(MyLinkedList* obj, int index) {
	if(index < 0 || index >= obj->size){
		return -1;
	}
	ListNode* cur = obj->head;
	int i;
	for(i = 0;i < index; i++){
		cur = cur->next;
	}
	return cur->val;
    
}

//将一个值为val的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点 
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
     ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
     newhead->val = val;
     newhead->next = obj->head;
     obj->head = newhead;
	 obj->size++; 
}

//将一个值为val的节点追加到链表中作为链表的最后一个元素。 
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
     ListNode* newtail = (ListNode*)malloc(sizeof(ListNode));
     newtail->val = val;
     newtail->next = NULL;
     ListNode* cur = obj->head;
     if(!cur){//如果链表为空 
     	  obj->head = newtail;
	 } else {
	    while(cur->next){//链表不为空 
     	  cur = cur->next;
	  }
	      cur->next = newtail;	
	 }
	 obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
     
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    
}

void myLinkedListFree(MyLinkedList* obj) {
    
}

int main() {
	
	return 0;
}
