#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500;

long long v[kMaxN + 1];
long long M[kMaxN + 1][kMaxN + 1];

int main()
{
	freopen("podm.in", "rt", stdin);
	freopen("podm.out", "wt", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) scanf("%lld", &v[i]);
	for (int k = 1; k < n; ++k) {
		for (int i = 1; i <= n - k; ++i) {
			M[i][i + k] = M[i][i] + M[i + 1][i + k] + v[i - 1] * v[i] * v[i + k];
			for (int j = i + 1; j < i + k; ++j) {
				M[i][i + k] = min(M[i][i + k],
				                  M[i][j] + M[j + 1][i + k] +
				                  v[i - 1] * v[j] * v[i + k]);
			}
		}
	}
	printf("%lld\n", M[1][n]);
	return 0;
}
