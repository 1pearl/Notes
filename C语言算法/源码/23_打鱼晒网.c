#include <stdio.h>

// ÿ�������������꣩
int daysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// �ж��Ƿ�������
int isLeapYear(unsigned int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ����ĳ���� 1990-01-01 ����������
int getDaysSince1990(unsigned int year, unsigned int month, unsigned int day) {
    int totalDays = 0;
    unsigned int y;
    // ���� 1990 �� year-1 ֮���������
    for (y = 1990; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
	unsigned int m;
    // ���㵱ǰ�� 1 �µ� month-1 ֮�������
    for (m = 0; m < month - 1; m++) {
        totalDays += daysOfMonth[m];
        if (m == 1 && isLeapYear(year)) { // 2�¶����1�죨���꣩
            totalDays += 1;
        }
    }

    // ���ϵ�������
    totalDays += day - 1;

    return totalDays;
}

// �жϡ����㡱���ǡ�ɹ����
int isWorking(unsigned int year, unsigned int month, unsigned int day) {
    int totalDays = getDaysSince1990(year, month, day);
    return (totalDays % 5 < 3) ? 1 : 0;
}

// ���Ժ���
void TestEntry() {
    unsigned int year, month, day;
    printf("���������� (�� �� ��): ");
    scanf("%u %u %u", &year, &month, &day);

    int result = isWorking(year, month, day);
    if (result) {
        printf("%u-%u-%u �ǡ����㡱�ա�\n", year, month, day);
    } else {
        printf("%u-%u-%u �ǡ�ɹ�����ա�\n", year, month, day);
    }
}

// ������
int main() {
    TestEntry();
    return 0;
}

