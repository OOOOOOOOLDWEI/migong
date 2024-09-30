#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���巽�� (��������)
const vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

// BFS ����
int shortestPathInMaze(const vector<string>& maze, int n, int m) {
    // ��¼�����յ�����
    int startX, startY;
    int endX, endY;

    // �ҵ���� S ���յ� T ��λ��
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

    // BFS ��ʼ��
    queue<pair<int, int>> q; // �洢����
    q.push({ startX, startY }); // ������
    vector<vector<int>> steps(n, vector<int>(m, -1)); // ��¼����
    steps[startX][startY] = 0;

    // ��ʼ BFS
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        // �ж��Ƿ񵽴��յ�
        if (x == endX && y == endY) {
            return steps[x][y]; // ���ز���
        }

        // �����ĸ�����
        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            // ���߽缰�Ƿ����
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#' && steps[nx][ny] == -1) {
                steps[nx][ny] = steps[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    return -1; // ���û��·��
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