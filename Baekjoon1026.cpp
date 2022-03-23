#include <iostream>
#include <algorithm>
using namespace std;

int N;
vector<int> A;
vector<int> B;
int result;

int main(void) {
	cin.tie(NULL);  ios::sync_with_stdio(false);
	cin >> N; //V.assign(N, vector<int>(M, 0));
	A.assign(N, 0); B.assign(N, 0);
	result = 0;
	int min = 100; int max = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());
	for (int i = 0; i < N; i++) {
		result += A[i] * B[i];
	}
	cout << result;
}
