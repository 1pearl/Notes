#include <stdio.h>
#include <string.h>

#define MAX_N 25  // N ���ֵ 5*5
#define QUEUE_SIZE 625  // 25*25 Ԥ�����пռ�

// �������飺�ϡ��¡�����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ���нṹ������ BFS��
typedef struct {
    int x, y, steps;
} QueueNode;

// �ж��Ƿ��ڵ�ͼ��Χ��
int isValid(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// ����ɴ﹫��վ������
int FindStat(const char *Map, unsigned int iArrN, unsigned int iPathLen) {
    int N = iArrN;  // �����С
    int startX = -1, startY = -1;  // ��� X λ��
    int count = 0;  // ͳ�ƿɴ﹫��վ��
    int visited[MAX_N][MAX_N] = {0};  // ���ʱ��
    QueueNode queue[QUEUE_SIZE];  // BFS ����
    int front = 0, rear = 0;  // ����ͷβ����
    int i;
    // ������� 'X'
    for (i = 0; i < N * N; i++) {
        if (Map[i] == 'X') {
            startX = i / N;
            startY = i % N;
            break;
        }
    }

    if (startX == -1) return 0;  // û���ҵ� 'X'

    // BFS ��ʼ��
    queue[rear++] = (QueueNode){startX, startY, 0};
    visited[startX][startY] = 1;

    // BFS ����
    while (front < rear) {
        QueueNode node = queue[front++];
        
        // ��������������ƣ�ֹͣ����
        if (node.steps > iPathLen) continue;

        // ��������վ 'S'������
        if (node.steps > 0 && Map[node.x * N + node.y] == 'S') {
            count++;
        }
        int d;
        // ���ĸ�������չ
        for (d = 0; d < 4; d++) {
            int newX = node.x + dx[d];
            int newY = node.y + dy[d];

            // ȷ����λ�úϷ���δ�����Ҳ����ϰ��� 'B'
            if (isValid(newX, newY, N) && !visited[newX][newY] && Map[newX * N + newY] != 'B') {
                queue[rear++] = (QueueNode){newX, newY, node.steps + 1};
                visited[newX][newY] = 1;  // ����ѷ���
            }
        }
    }

    return count;
}

// ���Ժ���
void TestEntry() {
    char map1[] = "...S........X.S.....S....";
    printf("Test 1: %d\n", FindStat(map1, 5, 3)); // Ԥ�������2

    char map2[] = "S...S.........BS........X";
    printf("Test 2: %d\n", FindStat(map2, 5, 5)); // Ԥ�������1
}

// ������
int main() {
    TestEntry();
    return 0;
}

