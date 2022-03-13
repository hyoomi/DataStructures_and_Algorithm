#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> V;
vector<int> S;
long long result;

int main(void) {
	cin.tie(NULL);  ios::sync_with_stdio(false);
	cin >> N; result = 0; V.assign(6, 0); S.assign(3, 0);

	for (int i = 0; i < 6; i++) { cin >> V[i]; }
	for (int i = 0; i < 3; i++) { S[i] = min(V[i], V[5 - i]); } //0 5, 1 4, 2 3 은 동시에 있을 수 없다
	sort(S.begin(), S.end());
		
	if (N == 1) { sort(V.begin(), V.end()); cout << V[0] + V[1] + V[2] + V[3] + V[4]; return 0; }
	result += (5 * (long long)N * N - 16 * N + 12) * S[0];
	result += (8 * N - 12) * (S[0] + S[1]);
	result += (long long)4 * (S[0] + S[1] + S[2]);
	cout << result; return 0;
}
