#include <stdio.h>

// 递归匹配函数
int isMatch(const char *ArrStr, const char *KeyStr) {
    // 如果 KeyStr 为空，则只有 ArrStr 也为空时匹配成功
    if (*KeyStr == '\0') return *ArrStr == '\0';

    // 处理 '?'：必须保证 ArrStr 还有字符，然后继续递归
    if (*KeyStr == '?') {
        return (*ArrStr != '\0') && isMatch(ArrStr + 1, KeyStr + 1);
    }

    // 处理 '*'：可以匹配 0 个字符（跳过 '*'） 或者多个字符（ArrStr+1 继续匹配）
    if (*KeyStr == '*') {
        return isMatch(ArrStr, KeyStr + 1) || (*ArrStr && isMatch(ArrStr + 1, KeyStr));
    }

    // 处理普通字符
    if (*ArrStr == *KeyStr) {
        return isMatch(ArrStr + 1, KeyStr + 1);
    }

    // 其他情况，不匹配
    return 0;
}

// 包装函数
int GetMatchSta(const char *ArrStr, const char *KeyStr) {
    return isMatch(ArrStr, KeyStr);
}

// 测试函数
void TestEntry() {
    printf("Test 1: %d\n", GetMatchSta("abcdefg", "a*"));       // 1
    printf("Test 2: %d\n", GetMatchSta("tommababcabc", "t?m*ab*abc")); // 1
    printf("Test 3: %d\n", GetMatchSta("hello", "h*o"));       // 1
    printf("Test 4: %d\n", GetMatchSta("abcdef", "a?c*f"));    // 1
    printf("Test 5: %d\n", GetMatchSta("abcdef", "a?c*d"));    // 0
}

// 主函数
int main() {
    TestEntry();
    return 0;
}

