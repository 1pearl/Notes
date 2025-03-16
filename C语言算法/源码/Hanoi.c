#include <stdio.h>

// ��ŵ���ݹ�ʵ��
void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    // �Ƚ�n-1�����Ӵ�from�ƶ���aux������to
    hanoi(n - 1, from, to, aux);
    // ����n�����Ӵ�from�ƶ���to
    printf("Move disk %d from %c to %c\n", n, from, to);
    // �ٽ�n-1�����Ӵ�aux�ƶ���to������from
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

