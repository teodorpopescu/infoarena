#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 8;

int n;
int v[kMaxN + 1];

void permutation(int k)
{
	if (k == n) {
		for (int i = 0; i < n; ++i) printf("%d ", v[i]);
		printf("\n");
	}
	for (int i = 1; i <= n; ++i) {
		bool valid = true;
		for (int j = 0; j < k; ++j) {
			if (v[j] == i) {
				valid = false;
				break;
			}
		}
		if (!valid) continue;
		v[k] = i;
		permutation(k + 1);
	}
}

int main()
{
	freopen("permutari.in", "rt", stdin);
	freopen("permutari.out", "wt", stdout);

	scanf("%d", &n);
	permutation(0);

	return 0;
}
