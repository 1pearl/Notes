#include <stdio.h>
#include <stdlib.h> 

typedef struct LinkNode{
	int value;
    struct LinkNode* next;	
}LinkNode;

typedef struct {
    int size;
    LinkNode* head;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
	if(index < 0 || index >= obj->size) return -1;
	LinkNode* cur = obj->head;
	int i;
	for(i=0;i<index;i++){
		cur = cur->next;
	}
	return cur->value;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    node->value = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    node->value = val;
    node->next = NULL;
    LinkNode* cur = obj->head;
    if(obj->head == NULL){
    	obj->head = node;
	} else {
		LinkNode* cur = obj->head;
		while(cur->next){
			cur = cur->next;
		}
		cur->next = node; 
	}
	obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->size) return;
    if(index == 0) {
    	myLinkedListAddAtHead(obj, val);
    	return;
	}
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	node->value = val;
	LinkNode* cur = obj->head;
	int i;
	for(i=0;i<index - 1;i++) {
		cur = cur->next;
	}
    node->next = cur->next;
    cur->next = node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 ||index >= obj->size) return;
    LinkNode* toDelete;
    if(index==0){
    	toDelete = obj->head;
    	obj->head = obj->head->next;
	} else {
		LinkNode* cur = obj->head;
		int i;
		for(i=0;i<index-1;i++){
			cur = cur->next;
		}
		toDelete = cur->next;
		cur->next = cur->next->next;
	}
	free(toDelete);
	obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    LinkNode* cur = obj->head;
    while(cur){
    	LinkNode* temp = cur;
    	cur = cur->next;
    	free(temp);
	}
	free(obj);
}

int main() {
	
	return 0;
}
/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
