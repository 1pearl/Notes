#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* creatNode(int val){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = NULL;
	return  newnode;	
}

void printList(struct node* head,int n){
	struct node* cur = head;
    while(cur){
    	printf("%d->",cur->data);
    	cur = cur->next;
	}

	printf("NULL\n");
}

void freeList(struct node* head){
	struct node* temp;
	while(head){
		temp = head;
		head = head->next;
		free(temp);
	}
}

//void resolve(struct node* head, struct node** head1, struct node** head2) {
//    if (head == NULL) {
//        *head1 = NULL;
//        *head2 = NULL;
//        return;
//    }
//
//    // 初始化两个链表的尾指针
//    struct node *oddTail = NULL, *evenTail = NULL;
//    struct node *cur = head;  // 当前遍历节点
//    int index = 1;  // 当前节点索引，从1开始
//
//    // 遍历原链表
//    while (cur != NULL) {
//        struct node* nextNode = cur->next;  // 记录下一个节点，防止丢失
//
//        // 如果是奇数位置的节点
//        if (index % 2 == 1) {
//            // 如果head1为空，说明是第一个节点
//            if (*head1 == NULL) {
//                *head1 = oddTail = cur;  // 设置head1和oddTail指向当前节点
//            } else {
//                oddTail->next = cur;  // 将当前节点添加到head1
//                oddTail = cur;  // 更新oddTail为当前节点
//            }
//        } else {  // 如果是偶数位置的节点
//            // 如果head2为空，说明是第一个节点
//            if (*head2 == NULL) {
//                *head2 = evenTail = cur;  // 设置head2和evenTail指向当前节点
//            } else {
//                evenTail->next = cur;  // 将当前节点添加到head2
//                evenTail = cur;  // 更新evenTail为当前节点
//            }
//        }
//
//        // 移动到下一个节点
//        cur = nextNode;
//        index++;  // 更新节点索引
//    }
//
//    // 断开两个链表的尾节点，防止形成环
//    if (oddTail) oddTail->next = NULL;
//    if (evenTail) evenTail->next = NULL;
//}

void resolve(struct node* head,struct node** head1,struct node** head2){
	if(head == NULL){//如果链表为空 
		*head1=NULL;
		*head2=NULL;
		return;
	}
	struct node* cur = head;
	struct node *oddTail=NULL,*evenTail=NULL;
	int index = 1;//从第一个结点开始
	while(cur != NULL){
		if(index%2==1){//为奇数结点 
		   if(*head1==NULL){//首节点
		      *head1=oddTail=cur; 
		   } else {//非奇数首节点 
		   	  oddTail->next=cur;//指向下一个奇数结点 
		   	  oddTail = cur;//将奇数结点的尾节点更新 
		   }
		} else {//为偶数结点 
			if(*head2==NULL){
				*head2=evenTail=cur;
			} else {
				evenTail->next=cur;
				evenTail=cur;
			}
		}
		cur = cur->next;
		index++; 
	}
	if(oddTail) oddTail->next = NULL;//将尾节点置为NULL，防止出现环 
	if(evenTail) evenTail->next = NULL; 
} 


int main(){
	struct node *head1=NULL,*head2=NULL;
	struct node* node1 = creatNode(1);
	struct node* node2 = creatNode(2);
	struct node* node3 = creatNode(3);
	struct node* node4 = creatNode(4);
	struct node* node5 = creatNode(5);
	struct node* node6 = creatNode(6);
	struct node* node7 = creatNode(7);
	struct node* node8 = creatNode(8);
	struct node* node9 = creatNode(9);
	struct node* node10 = creatNode(10);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = node10;
	
	printList(node1,10);
	
	resolve(node1,&head1,&head2);
	
	printList(head1,5);
	printList(head2,5); 
	
	freeList(node1);
				
	return 0;
} 

