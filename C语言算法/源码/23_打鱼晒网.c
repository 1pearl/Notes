#include <stdio.h>

// 每月天数（非闰年）
int daysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 判断是否是闰年
int isLeapYear(unsigned int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算某日与 1990-01-01 相差的总天数
int getDaysSince1990(unsigned int year, unsigned int month, unsigned int day) {
    int totalDays = 0;
    unsigned int y;
    // 计算 1990 到 year-1 之间的总天数
    for (y = 1990; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
	unsigned int m;
    // 计算当前年 1 月到 month-1 之间的天数
    for (m = 0; m < month - 1; m++) {
        totalDays += daysOfMonth[m];
        if (m == 1 && isLeapYear(year)) { // 2月额外加1天（闰年）
            totalDays += 1;
        }
    }

    // 加上当月天数
    totalDays += day - 1;

    return totalDays;
}

// 判断“打鱼”还是“晒网”
int isWorking(unsigned int year, unsigned int month, unsigned int day) {
    int totalDays = getDaysSince1990(year, month, day);
    return (totalDays % 5 < 3) ? 1 : 0;
}

// 测试函数
void TestEntry() {
    unsigned int year, month, day;
    printf("请输入日期 (年 月 日): ");
    scanf("%u %u %u", &year, &month, &day);

    int result = isWorking(year, month, day);
    if (result) {
        printf("%u-%u-%u 是“打鱼”日。\n", year, month, day);
    } else {
        printf("%u-%u-%u 是“晒网”日。\n", year, month, day);
    }
}

// 主函数
int main() {
    TestEntry();
    return 0;
}

