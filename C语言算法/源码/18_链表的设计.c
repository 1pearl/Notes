#include <stdio.h>
#include <stdlib.h>
 
//���������� 
typedef struct ListNode{
	int val;
	struct ListNode* next;
}ListNode; 

//���������� 
typedef struct {
    ListNode* head;
    int size;
} MyLinkedList;

//��ʼ������ 
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

//���������±�Ϊindex��ֵ 
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

//��һ��ֵΪval�Ľڵ���뵽�����е�һ��Ԫ��֮ǰ���ڲ�����ɺ��½ڵ���Ϊ����ĵ�һ���ڵ� 
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
     ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
     newhead->val = val;
     newhead->next = obj->head;
     obj->head = newhead;
	 obj->size++; 
}

//��һ��ֵΪval�Ľڵ�׷�ӵ���������Ϊ��������һ��Ԫ�ء� 
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
     ListNode* newtail = (ListNode*)malloc(sizeof(ListNode));
     newtail->val = val;
     newtail->next = NULL;
     ListNode* cur = obj->head;
     if(!cur){//�������Ϊ�� 
     	  obj->head = newtail;
	 } else {
	    while(cur->next){//����Ϊ�� 
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
