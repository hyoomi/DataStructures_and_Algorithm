#include <iostream>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> V;
queue<pair<int, int>> Q;
int result[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool checkPath(int i, int j) {
	if (i >= N || j >= M || i < 0 || j < 0) //배열 범위 검사
		return false;
	if (result[i][j] != 0) return false; //이미 방문했는지 검사
	if (V[i][j] == 0) return true; // 안익은 토마토인지 검사
	return false;
}

void bfs() {
	if (Q.empty()) return;
	int x = Q.front().first;
	int y = Q.front().second;	
	Q.pop();
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (checkPath(nx, ny)) {
			Q.push(make_pair(nx, ny));
			result[nx][ny] = result[x][y] + 1;
		}
	}	
	bfs();
}

int main(void) {
	cin.tie(NULL);  ios::sync_with_stdio(false);
	cin >> M >> N; V.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> V[i][j];
			if (V[i][j] == 1) {
				Q.push(make_pair(i, j));
				result[i][j] = 1;
			}
			else if (V[i][j] == -1) {
				result[i][j] = -1;
			}
		}
	}

	bfs();

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (result[i][j] == 0) {
				cout << -1; return 0;
			}
			if (result[i][j] > max)
				max = result[i][j];
		}
	}
	cout << max - 1; 
}
