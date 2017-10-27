#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 300;
const int kMaxM = 300;
const long double kPrecision = 1e-10;

long double A[kMaxN + 1][kMaxM + 1], x[kMaxM + 1], b[kMaxN + 1];

bool is_zero(long double x)
{
	return abs(x) < kPrecision;
}

int main()
{
	freopen("gauss.in", "rt", stdin);
	freopen("gauss.out", "wt", stdout);

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) scanf("%Lf", &A[i][j]);
		scanf("%Lf", &b[i]);
	}

	for (int i = 1, j = 1; i <= n && j <= m; ++i, ++j) {
		if (A[i][j] == 0) {
			int k;
			for (k = i + 1; k <= n; ++k) {
				if (A[k][j] != 0) break;
			}
			if (k > n) {
				--i; // stay on same line
				continue;
			}
			for (int p = j; p <= m; ++p) swap(A[k][p], A[i][p]);
			swap(b[i], b[k]);
		}
		for (int k = i + 1; k <= n; ++k) {
			long double ratio = A[k][j] / A[i][j];
			for (int p = j; p <= m; ++p) A[k][p] -= ratio * A[i][p];
			b[k] -= ratio * b[i];
		}
	}
/*	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) printf("%lf ", A[i][j]);
		printf("%lf\n", b[i]);
	}  */

	for (int i = n; i >= 1; --i) {
		int j;
		for (j = 1; j <= m; ++j) {
			if (!is_zero(A[i][j])) break;
		}
		if (j > m && !is_zero(b[i])) {
			printf("Imposibil\n");
			return 0;
		}
		long double sum = 0;
		for (int k = j + 1; k <= m; ++k) sum += A[i][k] * x[k];
		x[j] = (b[i] - sum) / A[i][j];
	}
	for (int j = 1; j <= m; ++j) printf("%.12Lf ", x[j]);
	printf("\n");

	return 0;
}
			
