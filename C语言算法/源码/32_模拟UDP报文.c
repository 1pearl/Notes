#include <stdio.h> 

struct udp{
short source_port;//Դ�˿ڣ�shortΪ2�ֽڣ�16λ��(���λ)2^15 = 32768��0~65535(�޷���)��-32768-32767(�з���) 
short desport_port;//Ŀ�Ķ˿� 
short len;//���� 
short check;//У��� 
} udph = {//    ���(��λ��ǰ)        С��(��λ��ǰ) 
  0xC0A8,  //   C0 A8                 A8 C0
  0xABC0,  //   AB C0                 C0 AB
  0x4000,  //   40 00                 00 40
  0x0      //   00 00                 00 00
};

int main(void)
{
  printf("len is %d\n",udph.len);
  //0x4000 = 4*16^3 = 16384δԽ�� 
  char *pt = (char *) &udph;//ʹ��ָ��ptָ��udph���׵�ַ   
  int i;
  for(i = 0;i<sizeof(udph);i++)
  {
    printf("%.02X ", 0xff & *pt++);//"%.2x"��ʾ���������Ϊ2λ���㲹�� 
    //����0xff��һ���ֽ�,*pt++��Ӧ��Ԫ��ΪshortΪ�����ֽ� 
	//С�˴洢:A8 C0 C0 AB 00 40 00 00
	//ff & A8 = A8 
	//ff & C0 = C0
	//ff & C0 = C0 
	//ff & AB = AB
	//ff & 00 = 00
	//ff & 40 = 40
	//ff & 00 = 00
	//ff & 00 = 00 
	//��˴洢:C0 A8 AB C0 40 00 00 00
	//ff & C0 = C0
	//ff & A8 = A8 
	//ff & AB = AB
	//ff & C0 = C0
	//ff & 40 = 40
	//ff & 00 = 00
	//ff & 00 = 00
	//ff & 00 = 00 
  }
  return 0;
}



