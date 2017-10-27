#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 100;
const int kInf = numeric_limits<int>::max() / 2;

int n;
int D[kMaxN][kMaxN];

void royfloyd()
{
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
}

int main()
{
	freopen("royfloyd.in", "rt", stdin);
	freopen("royfloyd.out", "wt", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &D[i][j]);
			if (D[i][j] == 0) D[i][j] = kInf;
		}
	}

	royfloyd();

	for (int i = 0; i < n; ++i) {
		D[i][i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", D[i][j] == kInf ? 0 : D[i][j]);
		}
		printf("\n");
	}

	return 0;
}
