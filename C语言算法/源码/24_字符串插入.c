#include <stdio.h>
#include <string.h>

// �����ַ�������
char* insert(int f, const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
     

    // ȷ�� f �ںϷ���Χ
    if (f < 0 || f > len1) {
        printf("����λ�÷Ƿ���\n");
        return NULL;
    }
    char* res = (char*)malloc((len1+len2+1)*sizeof(char));
    // ���� str1 ��ǰ f ���ַ�
    strncpy(res, str1, f);
    res[f] = '\0'; // �����ֹ��

    // ׷�� str2
    strcat(res, str2);

    // ׷�� str1 ʣ�ಿ��
    strcat(res, str1 + f);
    return res;
}

// ������
int main() {
    char str1[100] = "HelloWorld";  // ԭʼ�ַ���
    char str2[20] = "INSERT";       // Ҫ������ַ���
    char* result;               // �洢�������ַ���
    int f = 5;                      // ����λ��

    // ���� insert ����
    result = insert(f, str1, str2);

    // ������
    if (result) {  // ȷ�� result ��Ч
        printf("������ַ���: %s\n", result);
        free(result);  // �ͷŶ�̬������ڴ�
    }

    return 0;
}

