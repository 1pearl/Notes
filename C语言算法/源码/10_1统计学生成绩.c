//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Players{
//	int num;
//	double time;
//}Players; 
//
//void BubbleSort(Players* players,int n){
//	int i,j;
//	Players temp;
//	for(i=0;i<n-1;i++){
//		for(j=0;j<n-i-1;j++){
//			if(players[j].time>players[j+1].time){
//				temp = players[j];
//				players[j] = players[j+1];
//				players[j+1] = temp;
//			}
//		}
//	}
//}
//
//int main(){
//    Players players1;
//    players1.num = 207;
//    players1.time = 14.5;
//    
//    Players players2;
//    players2.num = 231;
//    players2.time = 14.7;
//    
//    Players players3;
//    players3.num = 153;
//    players3.time = 15.1;
//
//    Players players4;
//    players4.num = 278;
//    players4.time = 15.5;
//    
//    Players players5;
//    players5.num = 88;
//    players5.time = 15.3;
//
//    Players player_s[5] = {players1,players2,players3,players4,players5};
//    BubbleSort(player_s,5);
//    int i;
//    for(i=0;i<5;i++) {
//    	printf("player %d 为第 %d 名,成绩为 %.2f\n",player_s[i].num,i+1,player_s[i].time);
//	}
//	return 0;
//} 
#include<stdio.h >
#include<string.h>
#define MAX 100
int mycopy(char* buf,char len){
  char mybuf[MAX];
  int a = 100;
  if(len > MAX){
    return -1;
  }
  memcpy(mybuf,buf,len);
  printf("%d", a);
  return len;
}
int main(void){
  printf("the copy len is %d\n", mycopy("hello", -2));
  return 0;
}

