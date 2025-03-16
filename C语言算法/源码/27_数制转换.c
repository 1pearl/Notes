#include <stdio.h>
void DecToBin(unsigned int iDec,char pBin[32]){
	int i;
	for(i=31;i>=0;i--){
		pBin[i]=(iDec&1) ? '1' : '0';
		iDec >>= 1;
	}
	pBin[32] = '\0';
}

int main(){
	unsigned int iDec;
	char pBin[33];
	printf("输入一个整数\n");
	scanf("%u",&iDec);
	DecToBin(iDec,pBin);
	printf("%d转为二进制后为%s\n",iDec,pBin);
	return 0;

}

//#include <stdio.h>
//
//// 十进制转换为二进制
//void DecToBin(unsigned int iDec, char pBin[32]) {
//	int i;
//    for (i = 31; i >= 0; i--) {
//        pBin[i] = (iDec & 1) ? '1' : '0';  // 取出最低位，转换为 '0' 或 '1'
//        iDec >>= 1;  // 右移1位，继续处理下一位
//    }
//    pBin[32] = '\0';  // 字符串结束符
//}
//
//int main() {
//    unsigned int num;
//    char binStr[33];  // 32位+1个'\0'
//
//    printf("请输入一个整数：");
//    scanf("%u", &num);
//
//    DecToBin(num, binStr);
//    printf("转换后的二进制：%s\n", binStr);
//
//    return 0;
//}

