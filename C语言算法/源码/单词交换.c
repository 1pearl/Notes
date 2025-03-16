#include <stdio.h>
#include <string.h>
#include <ctype.h>

// �����ַ��������е���������
void swapWords(char words[][20], int i, int j) {
    char temp[20];  
    strcpy(temp, words[i]);
    strcpy(words[i], words[j]);
    strcpy(words[j], temp);
}

// ������
void exchange(const char *pIn, char *pOut) {
    char words[100][20]; // �洢��ֺ�ĵ��ʣ����100����ÿ�������20�ַ�
    int wordCount = 0;   // ��¼��������
    int i = 0, j = 0, len = strlen(pIn);

    // ����ַ����ɵ���
    while (i < len) {
        if (!isspace(pIn[i])) {
            int k = 0;
            while (i < len && !isspace(pIn[i])) {
                words[wordCount][k++] = pIn[i++];
            }
            words[wordCount][k] = '\0'; // ������ǰ����
            wordCount++; // ������������
        }
        i++; // �����ո�
    }

    // �ҵ����������ĵ���
    int aIndex[100], nIndex[100], aCount = 0, nCount = 0;
    for (i = 0; i < wordCount; i++) {
        if (words[i][0] == 'A') aIndex[aCount++] = i; // ��¼��'A'��ͷ�ĵ�������
        int lastCharIndex = strlen(words[i]) - 1;
        if (words[i][lastCharIndex] == 'N') nIndex[nCount++] = i; // ��¼��'N'��β�ĵ�������
    }

    // ���� A ��ͷ �� N ��β�ĵ���
    for (i = 0; i < aCount && i < nCount; i++) {
        swapWords(words, aIndex[i], nIndex[nCount - 1 - i]); 
    }

    // ��������ַ���
    pOut[0] = '\0';
    for (i = 0; i < wordCount; i++) {
        strcat(pOut, words[i]);
        if (i < wordCount - 1) strcat(pOut, " "); // ��ӿո�
    }
}

// ���Ժ���
int main() {
    char input[] = "AM I OLDER THAN YOU";
    char output[100];
    
    exchange(input, output);
    printf("���: \"%s\"\n", output);

    return 0;
}

