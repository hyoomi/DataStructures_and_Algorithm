#include <iostream>
#include <queue>
using namespace std;

int N, M;
string V[101];
queue<pair<int, int>> Q;
int result[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool checkPath(int i, int j) {
	if (i >= N || j >= M || i < 0 || j < 0) //배열 범위 검사
		return false;
	if (result[i][j] != 0) return false; //이미 방문했는지 검사
	if (V[i][j] == '1') return true;
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
	cin >> N >> M; 

	for (int i = 0; i < N; i++) 
		cin >> V[i];
	
	Q.push(make_pair(0, 0));
	result[0][0] = 1;
	bfs();

	cout << result[N - 1][M - 1]; 
}
