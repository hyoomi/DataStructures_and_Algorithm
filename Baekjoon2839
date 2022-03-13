#include <iostream>
using namespace std;

int N;
int five, three;

int main(void) {
	cin.tie(NULL);  ios::sync_with_stdio(false);
	cin >> N; five = three = 0;

	if (N / 5 > 0) { five += N / 5;  N = N % 5; }
	if (N / 3 > 0) { three += N / 3; N = N % 3; }

	if(N != 0) {
		while (five > 0 && N != 0) {
			five--; N += 5;
			if (N / 3 > 0) { three += N / 3; N = N % 3; }
		}		
	}

	if (N == 0) cout << five + three;
	else cout << -1;
}
