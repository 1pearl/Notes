#include <stdio.h> 

struct udp{
short source_port;//short为2字节，16位，(最高位)2^15 = 32768，0~65535(无符号)或-32768-32767(有符号) 
short desport_port;
short len;
short check;
} udph = {//         大端(高位在前)        小端(低位在前) 
  0x100,  //0x0100   01 00                 00 01
  0x200,  //0x0200   02 00                 00 02
  0x8000, //0x8000   80 00                 00 80
  0x0     //0x0000   00 00                 00 00
};

int main(void)
{
  printf("len is %d",udph.len);
  //0x8000 = 1000 0000 0000 0000（2进制） = 2^15 = 32768 
  //short范围为-32768~32767,因此导致整数溢出,输出结果是len is -32768 
  char *pt = (char *) &udph;//使用指针pt指向udph的首地址   
  int i;
  for(i = 0;i<sizeof(udph);i++)
  {
    printf("%.02x ", 0xff & *pt++);//"%.2x"表示输出二进制为2位不足补零 
    //这里0xff是一个字节,*pt++对应的元素为short为两个字节 
	//小端存储:00 01 00 02 00 80 00 00 
	//ff & 00 = 00 
	//ff & 01 = 01
	//ff & 00 = 00 
	//ff & 02 = 02
	//ff & 00 = 80
	//ff & 00 = 00
	//ff & 00 = 00 
	//大端存储:01 00 02 00 80 00 00 00 
	//ff & 01 = 01
	//ff & 00 = 00 
	//ff & 02 = 02
	//ff & 00 = 00
	//ff & 80 = 80
	//ff & 00 = 00
	//ff & 00 = 00
	//ff & 00 = 00 
  }
  return 0;
}



