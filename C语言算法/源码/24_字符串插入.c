#include <stdio.h>
#include <string.h>

// 插入字符串函数
char* insert(int f, const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
     

    // 确保 f 在合法范围
    if (f < 0 || f > len1) {
        printf("插入位置非法！\n");
        return NULL;
    }
    char* res = (char*)malloc((len1+len2+1)*sizeof(char));
    // 复制 str1 的前 f 个字符
    strncpy(res, str1, f);
    res[f] = '\0'; // 添加终止符

    // 追加 str2
    strcat(res, str2);

    // 追加 str1 剩余部分
    strcat(res, str1 + f);
    return res;
}

// 主函数
int main() {
    char str1[100] = "HelloWorld";  // 原始字符串
    char str2[20] = "INSERT";       // 要插入的字符串
    char* result;               // 存储插入后的字符串
    int f = 5;                      // 插入位置

    // 调用 insert 函数
    result = insert(f, str1, str2);

    // 输出结果
    if (result) {  // 确保 result 有效
        printf("插入后字符串: %s\n", result);
        free(result);  // 释放动态分配的内存
    }

    return 0;
}

