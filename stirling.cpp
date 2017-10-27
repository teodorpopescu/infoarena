#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 200;
const int kMaxM = 200;
const int kModulo = 98999;

int s[kMaxN + 1][kMaxM + 1];
int S[kMaxN + 1][kMaxM + 1];

int main()
{
	int t;
	freopen("stirling.in", "rt", stdin);
	freopen("stirling.out", "wt", stdout);

	//Build tables
	s[0][0] = S[0][0] = 1;
	for (int i = 1; i <= kMaxN; ++i) {
		for (int j = 1; j <= kMaxM; ++j) {
			s[i][j] = (s[i - 1][j - 1] - (i - 1) * s[i - 1][j]) % kModulo;
			S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j]) % kModulo;
		}
	}

	//Queries
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int x, n, m;
		scanf("%d%d%d", &x, &n, &m);
		switch (x) {
		case 1:
			printf("%d\n", s[n][m]);
			break;
		case 2:
			printf("%d\n", S[n][m]);
			break;
		}
	}

	return 0;
}
