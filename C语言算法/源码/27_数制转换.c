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
	printf("����һ������\n");
	scanf("%u",&iDec);
	DecToBin(iDec,pBin);
	printf("%dתΪ�����ƺ�Ϊ%s\n",iDec,pBin);
	return 0;

}

//#include <stdio.h>
//
//// ʮ����ת��Ϊ������
//void DecToBin(unsigned int iDec, char pBin[32]) {
//	int i;
//    for (i = 31; i >= 0; i--) {
//        pBin[i] = (iDec & 1) ? '1' : '0';  // ȡ�����λ��ת��Ϊ '0' �� '1'
//        iDec >>= 1;  // ����1λ������������һλ
//    }
//    pBin[32] = '\0';  // �ַ���������
//}
//
//int main() {
//    unsigned int num;
//    char binStr[33];  // 32λ+1��'\0'
//
//    printf("������һ��������");
//    scanf("%u", &num);
//
//    DecToBin(num, binStr);
//    printf("ת����Ķ����ƣ�%s\n", binStr);
//
//    return 0;
//}

