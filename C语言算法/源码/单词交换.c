#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 交换字符串数组中的两个单词
void swapWords(char words[][20], int i, int j) {
    char temp[20];  
    strcpy(temp, words[i]);
    strcpy(words[i], words[j]);
    strcpy(words[j], temp);
}

// 处理函数
void exchange(const char *pIn, char *pOut) {
    char words[100][20]; // 存储拆分后的单词，最多100个，每个单词最长20字符
    int wordCount = 0;   // 记录单词总数
    int i = 0, j = 0, len = strlen(pIn);

    // 拆分字符串成单词
    while (i < len) {
        if (!isspace(pIn[i])) {
            int k = 0;
            while (i < len && !isspace(pIn[i])) {
                words[wordCount][k++] = pIn[i++];
            }
            words[wordCount][k] = '\0'; // 结束当前单词
            wordCount++; // 单词数量增加
        }
        i++; // 跳过空格
    }

    // 找到符合条件的单词
    int aIndex[100], nIndex[100], aCount = 0, nCount = 0;
    for (i = 0; i < wordCount; i++) {
        if (words[i][0] == 'A') aIndex[aCount++] = i; // 记录以'A'开头的单词索引
        int lastCharIndex = strlen(words[i]) - 1;
        if (words[i][lastCharIndex] == 'N') nIndex[nCount++] = i; // 记录以'N'结尾的单词索引
    }

    // 交换 A 开头 和 N 结尾的单词
    for (i = 0; i < aCount && i < nCount; i++) {
        swapWords(words, aIndex[i], nIndex[nCount - 1 - i]); 
    }

    // 重新组合字符串
    pOut[0] = '\0';
    for (i = 0; i < wordCount; i++) {
        strcat(pOut, words[i]);
        if (i < wordCount - 1) strcat(pOut, " "); // 添加空格
    }
}

// 测试函数
int main() {
    char input[] = "AM I OLDER THAN YOU";
    char output[100];
    
    exchange(input, output);
    printf("输出: \"%s\"\n", output);

    return 0;
}

