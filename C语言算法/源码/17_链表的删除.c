#include <stdio.h>
#include <stdlib.h>

//构建链表
//要前向声明，因为在结构体中用到了ListNode 
//typedef xxx类型 别名 
typedef struct ListNode ListNode;
 
struct ListNode{
	int value;      //值 
	ListNode* next; //指向下一个节点的指针，如果不前向声明要使用struct ListNode *next; 
};

//链表创建新的节点
ListNode* CreateNode(int val){
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->value = val;
	newNode->next = NULL;
	return newNode;  
}

//打印链表 
void printNode(ListNode *head){
	ListNode* current = head;
	while(current){
		printf("%d->",current->value);
		current = current->next;
	}
	printf("NULL\n");
}

ListNode* DeleteNode(int val, ListNode* head) {
    ListNode* temp;

    // 删除头节点值为 val 的情况
    while (head && (head->value == val)) {
        temp = head;
        head = head->next;
        free(temp);
    }

    // 如果链表为空，直接返回
    if (!head) {
        return NULL;
    }

    ListNode* cur = head;

    // 遍历链表，删除非头节点值为 val 的情况
    while (cur->next) {
        if (cur->next->value == val) {
            temp = cur->next;
            cur->next = temp->next;
            free(temp);
        } else {
            cur = cur->next;  // 只有未删除节点时才移动 cur
        }
    }

    return head;
}  

int main(){
    // 创建链表节点
    ListNode* node1 = CreateNode(1);
    ListNode* node2 = CreateNode(2);
    ListNode* node3 = CreateNode(2);
    ListNode* node4 = CreateNode(1);

    // 连接链表节点
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    printNode(node1);
    
    printNode(DeleteNode(1,node1));
    
    ListNode* current = node1;
    ListNode* next; 
	while(current){
		next = current->next;
		free(current);
		current = next;
	} 
	
	return 0;
} 
