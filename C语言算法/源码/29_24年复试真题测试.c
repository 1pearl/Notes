#include<stdio.h >
#include<string.h>
#define MAX 100

int mycopy(char* buf,char len){//char�ķ�ΧֻҪ-128��127��Χ̫С�ˣ�����ʹ��int 
  char mybuf[MAX];
  int a = 100;
  if(len > MAX){
    return -1;
  }
  //�жϳ����Ƿ�Խ�磬����len<0����� 
  /*������ 
  if(len < 0 || len > MAX){
    return -1;
  }
  */ 
  memcpy(mybuf,buf,len);
  //����len=-2����memcpy()����ʵ�ʴ���,memcpy(mybuf,buf,-2);
  //��memcpy�ĵ����������Ǳ�ʾ���Ƶ��ַ�������,Ϊ�޷��ŵģ�-2���룬����һ�������������
  //�ᵼ����������ǵ�mybuf֮����ڴ棬�ᵼ�¶δ��󣬿��ܻ�ʹ��a��Ӧ���ڴ汻����,a�������
  //���Ҳ������һ����ȷ����ֵ�����δ�������޸Ŀ�����100 
  printf("%d", a);//������ 
  return len;
}
int main(void){
  printf("the copy len is %d\n", mycopy("hello", -2));
//  unsigned char a = -1;
//  printf("%d",((size_t)a));
  return 0;
}
