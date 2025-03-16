#include <stdio.h>
#include <string.h>

#define MAX_N 25  // N 最大值 5*5
#define QUEUE_SIZE 625  // 25*25 预留队列空间

// 方向数组：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 队列结构（用于 BFS）
typedef struct {
    int x, y, steps;
} QueueNode;

// 判断是否在地图范围内
int isValid(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// 计算可达公交站的数量
int FindStat(const char *Map, unsigned int iArrN, unsigned int iPathLen) {
    int N = iArrN;  // 矩阵大小
    int startX = -1, startY = -1;  // 起点 X 位置
    int count = 0;  // 统计可达公交站数
    int visited[MAX_N][MAX_N] = {0};  // 访问标记
    QueueNode queue[QUEUE_SIZE];  // BFS 队列
    int front = 0, rear = 0;  // 队列头尾索引
    int i;
    // 查找起点 'X'
    for (i = 0; i < N * N; i++) {
        if (Map[i] == 'X') {
            startX = i / N;
            startY = i % N;
            break;
        }
    }

    if (startX == -1) return 0;  // 没有找到 'X'

    // BFS 初始化
    queue[rear++] = (QueueNode){startX, startY, 0};
    visited[startX][startY] = 1;

    // BFS 遍历
    while (front < rear) {
        QueueNode node = queue[front++];
        
        // 如果超出步长限制，停止搜索
        if (node.steps > iPathLen) continue;

        // 遇到公交站 'S'，计数
        if (node.steps > 0 && Map[node.x * N + node.y] == 'S') {
            count++;
        }
        int d;
        // 向四个方向扩展
        for (d = 0; d < 4; d++) {
            int newX = node.x + dx[d];
            int newY = node.y + dy[d];

            // 确保新位置合法、未访问且不是障碍物 'B'
            if (isValid(newX, newY, N) && !visited[newX][newY] && Map[newX * N + newY] != 'B') {
                queue[rear++] = (QueueNode){newX, newY, node.steps + 1};
                visited[newX][newY] = 1;  // 标记已访问
            }
        }
    }

    return count;
}

// 测试函数
void TestEntry() {
    char map1[] = "...S........X.S.....S....";
    printf("Test 1: %d\n", FindStat(map1, 5, 3)); // 预期输出：2

    char map2[] = "S...S.........BS........X";
    printf("Test 2: %d\n", FindStat(map2, 5, 5)); // 预期输出：1
}

// 主函数
int main() {
    TestEntry();
    return 0;
}

