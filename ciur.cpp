#include <bits/stdc++.h>

const int kMaxN = 2000000;

bool v[kMaxN + 1];

int main()
{
	int n;
	freopen("ciur.in", "rt", stdin);
	freopen("ciur.out", "wt", stdout);

	scanf("%d", &n);

	for (int i = 3; i * i <= n; i += 2) {
		if (!v[i]) {
			for (int j = i * i; j <= n; j += i) {
				v[j] = 1;
			}
		}
	}

	int ctr = 1; //2 included
	for (int i = 3; i <= n; i += 2) {
		if (!v[i]) ++ctr;
	}

	printf("%d\n", ctr);

	return 0;
}
