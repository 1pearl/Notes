#include <stdio.h> 

struct udp{
short source_port;//源端口，short为2字节，16位，(最高位)2^15 = 32768，0~65535(无符号)或-32768-32767(有符号) 
short desport_port;//目的端口 
short len;//长度 
short check;//校验和 
} udph = {//    大端(高位在前)        小端(低位在前) 
  0xC0A8,  //   C0 A8                 A8 C0
  0xABC0,  //   AB C0                 C0 AB
  0x4000,  //   40 00                 00 40
  0x0      //   00 00                 00 00
};

int main(void)
{
  printf("len is %d\n",udph.len);
  //0x4000 = 4*16^3 = 16384未越界 
  char *pt = (char *) &udph;//使用指针pt指向udph的首地址   
  int i;
  for(i = 0;i<sizeof(udph);i++)
  {
    printf("%.02X ", 0xff & *pt++);//"%.2x"表示输出二进制为2位不足补零 
    //这里0xff是一个字节,*pt++对应的元素为short为两个字节 
	//小端存储:A8 C0 C0 AB 00 40 00 00
	//ff & A8 = A8 
	//ff & C0 = C0
	//ff & C0 = C0 
	//ff & AB = AB
	//ff & 00 = 00
	//ff & 40 = 40
	//ff & 00 = 00
	//ff & 00 = 00 
	//大端存储:C0 A8 AB C0 40 00 00 00
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



