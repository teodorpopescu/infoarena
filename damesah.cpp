#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 15;

int n, s = 0;
int v[kMaxN];
bool L[kMaxN], D1[2 * kMaxN], D2[2 * kMaxN + 1];

void backtrack(int k)
{
	if (k == n + 1) {
		if (s == 0) {
			for (int i = 1; i <= n; ++i) printf("%d ", v[i]);
			printf("\n");
		}
		++s;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!L[i] && !D1[kMaxN + i - k] && !D2[i + k]) {
			v[k] = i;
			L[i] = true;
			D1[kMaxN + i - k] = true;
			D2[i + k] = true;
			backtrack(k + 1);
			L[i] = false;
			D1[kMaxN + i - k] = false;
			D2[i + k] = false;
		}
	}
}
int main()
{
	freopen("damesah.in", "rt", stdin);
	freopen("damesah.out", "wt", stdout);

	scanf("%d", &n);
	backtrack(1);
	printf("%d\n", s);

	return 0;
}
