#include <stdio.h>

// 汉诺塔递归实现
void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    // 先将n-1个盘子从from移动到aux，借助to
    hanoi(n - 1, from, to, aux);
    // 将第n个盘子从from移动到to
    printf("Move disk %d from %c to %c\n", n, from, to);
    // 再将n-1个盘子从aux移动到to，借助from
    hanoi(n - 1, aux, from, to);
}

int main() {
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);
    printf("\nSteps to solve the Tower of Hanoi with %d disks:\n", num);
    hanoi(num, 'A', 'B', 'C');
    return 0;
}

