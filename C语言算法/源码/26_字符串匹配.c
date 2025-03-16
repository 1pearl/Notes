#include <stdio.h>

// �ݹ�ƥ�亯��
int isMatch(const char *ArrStr, const char *KeyStr) {
    // ��� KeyStr Ϊ�գ���ֻ�� ArrStr ҲΪ��ʱƥ��ɹ�
    if (*KeyStr == '\0') return *ArrStr == '\0';

    // ���� '?'�����뱣֤ ArrStr �����ַ���Ȼ������ݹ�
    if (*KeyStr == '?') {
        return (*ArrStr != '\0') && isMatch(ArrStr + 1, KeyStr + 1);
    }

    // ���� '*'������ƥ�� 0 ���ַ������� '*'�� ���߶���ַ���ArrStr+1 ����ƥ�䣩
    if (*KeyStr == '*') {
        return isMatch(ArrStr, KeyStr + 1) || (*ArrStr && isMatch(ArrStr + 1, KeyStr));
    }

    // ������ͨ�ַ�
    if (*ArrStr == *KeyStr) {
        return isMatch(ArrStr + 1, KeyStr + 1);
    }

    // �����������ƥ��
    return 0;
}

// ��װ����
int GetMatchSta(const char *ArrStr, const char *KeyStr) {
    return isMatch(ArrStr, KeyStr);
}

// ���Ժ���
void TestEntry() {
    printf("Test 1: %d\n", GetMatchSta("abcdefg", "a*"));       // 1
    printf("Test 2: %d\n", GetMatchSta("tommababcabc", "t?m*ab*abc")); // 1
    printf("Test 3: %d\n", GetMatchSta("hello", "h*o"));       // 1
    printf("Test 4: %d\n", GetMatchSta("abcdef", "a?c*f"));    // 1
    printf("Test 5: %d\n", GetMatchSta("abcdef", "a?c*d"));    // 0
}

// ������
int main() {
    TestEntry();
    return 0;
}

