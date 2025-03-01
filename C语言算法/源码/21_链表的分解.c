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
//    // ��ʼ�����������βָ��
//    struct node *oddTail = NULL, *evenTail = NULL;
//    struct node *cur = head;  // ��ǰ�����ڵ�
//    int index = 1;  // ��ǰ�ڵ���������1��ʼ
//
//    // ����ԭ����
//    while (cur != NULL) {
//        struct node* nextNode = cur->next;  // ��¼��һ���ڵ㣬��ֹ��ʧ
//
//        // ���������λ�õĽڵ�
//        if (index % 2 == 1) {
//            // ���head1Ϊ�գ�˵���ǵ�һ���ڵ�
//            if (*head1 == NULL) {
//                *head1 = oddTail = cur;  // ����head1��oddTailָ��ǰ�ڵ�
//            } else {
//                oddTail->next = cur;  // ����ǰ�ڵ���ӵ�head1
//                oddTail = cur;  // ����oddTailΪ��ǰ�ڵ�
//            }
//        } else {  // �����ż��λ�õĽڵ�
//            // ���head2Ϊ�գ�˵���ǵ�һ���ڵ�
//            if (*head2 == NULL) {
//                *head2 = evenTail = cur;  // ����head2��evenTailָ��ǰ�ڵ�
//            } else {
//                evenTail->next = cur;  // ����ǰ�ڵ���ӵ�head2
//                evenTail = cur;  // ����evenTailΪ��ǰ�ڵ�
//            }
//        }
//
//        // �ƶ�����һ���ڵ�
//        cur = nextNode;
//        index++;  // ���½ڵ�����
//    }
//
//    // �Ͽ����������β�ڵ㣬��ֹ�γɻ�
//    if (oddTail) oddTail->next = NULL;
//    if (evenTail) evenTail->next = NULL;
//}

void resolve(struct node* head,struct node** head1,struct node** head2){
	if(head == NULL){//�������Ϊ�� 
		*head1=NULL;
		*head2=NULL;
		return;
	}
	struct node* cur = head;
	struct node *oddTail=NULL,*evenTail=NULL;
	int index = 1;//�ӵ�һ����㿪ʼ
	while(cur != NULL){
		if(index%2==1){//Ϊ������� 
		   if(*head1==NULL){//�׽ڵ�
		      *head1=oddTail=cur; 
		   } else {//�������׽ڵ� 
		   	  oddTail->next=cur;//ָ����һ��������� 
		   	  oddTail = cur;//����������β�ڵ���� 
		   }
		} else {//Ϊż����� 
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
	if(oddTail) oddTail->next = NULL;//��β�ڵ���ΪNULL����ֹ���ֻ� 
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

