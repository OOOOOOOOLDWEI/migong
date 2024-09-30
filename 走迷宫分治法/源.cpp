#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义方向 (上下左右)
const vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

// BFS 函数
int shortestPathInMaze(const vector<string>& maze, int n, int m) {
    // 记录起点和终点坐标
    int startX, startY;
    int endX, endY;

    // 找到起点 S 和终点 T 的位置
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            else if (maze[i][j] == 'T') {
                endX = i;
                endY = j;
            }
        }
    }

    // BFS 初始化
    queue<pair<int, int>> q; // 存储坐标
    q.push({ startX, startY }); // 起点入队
    vector<vector<int>> steps(n, vector<int>(m, -1)); // 记录步数
    steps[startX][startY] = 0;

    // 开始 BFS
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        // 判断是否到达终点
        if (x == endX && y == endY) {
            return steps[x][y]; // 返回步数
        }

        // 遍历四个方向
        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            // 检查边界及是否可行
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#' && steps[nx][ny] == -1) {
                steps[nx][ny] = steps[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    return -1; // 如果没有路径
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    int result = shortestPathInMaze(maze, n, m);
    if (result != -1) {
        cout << result << endl; 
    }
    else {
        cout << "No Path" << endl;
    }
    return 0;
}