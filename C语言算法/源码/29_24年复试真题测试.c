#include<stdio.h >
#include<string.h>
#define MAX 100

int mycopy(char* buf,char len){//char的范围只要-128到127范围太小了，可以使用int 
  char mybuf[MAX];
  int a = 100;
  if(len > MAX){
    return -1;
  }
  //判断长度是否越界，少了len<0的情况 
  /*改正： 
  if(len < 0 || len > MAX){
    return -1;
  }
  */ 
  memcpy(mybuf,buf,len);
  //由于len=-2，则memcpy()函数实际传入,memcpy(mybuf,buf,-2);
  //而memcpy的第三个参数是表示复制的字符串长度,为无符号的，-2传入，会变成一个超大的正数，
  //会导致溢出，覆盖掉mybuf之外的内存，会导致段错误，可能会使得a对应的内存被覆盖,a即便可以
  //输出也可能是一个不确定的值，如果未被覆盖修改可能是100 
  printf("%d", a);//如果输出 
  return len;
}
int main(void){
  printf("the copy len is %d\n", mycopy("hello", -2));
//  unsigned char a = -1;
//  printf("%d",((size_t)a));
  return 0;
}
