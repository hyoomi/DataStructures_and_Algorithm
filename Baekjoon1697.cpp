#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
int N, M;
queue<int> Q;
int result[100001];
int dx[3] = { 1, 1, 2 }; // X * dx
int dn[3] = { 1, -1, 0 }; // X + dn
bool findM;

bool checkPath(int nx, int x) {
	if (nx >  MAX || nx < 0) //배열 범위 검사
		return false;
	if (result[nx] > result[x] + 1 || result[nx] == 0) return true; //더 좋은 루트인지 검사
	return false;
}

void bfs() {
	if (Q.empty() || findM) return;
	int x = Q.front();
	Q.pop();
	for (int i = 0; i < 3; i++) {
		int nx = x * dx[i] + dn[i];
		if (checkPath(nx, x)) {			
			Q.push(nx);
			result[nx] = result[x] + 1;
			if (nx == M) { findM = true; return; }
		}
	}	
	bfs();
}

int main(void) {
	cin.tie(NULL);  ios::sync_with_stdio(false);
	cin >> N >> M; findM = false;

	Q.push(N);
	result[N] = 1;
	bfs();

	cout << result[M] - 1; 
}
