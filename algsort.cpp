#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500000;

int v[kMaxN], av[kMaxN];

void merge_sort(int a, int b)
{
	if (a == b) return;
	if (a + 1 == b) {
		if (v[a] > v[b]) {
			int aux = v[a];
			v[a] = v[b];
			v[b] = aux;
		}
		return;
	}
	int m = (a + b) / 2, i, j, k;
	merge_sort(a, m);
	merge_sort(m + 1, b);
	i = a; j = m + 1; k = a;
	while (i <=m && j <= b) {
		if (v[i] < v[j]) av[k++] = v[i++];
		else av[k++] = v[j++];
	}
	while (i <= m) av[k++] = v[i++];
	while (j <= b) av[k++] = v[j++];
	for (int i = a; i <= b; ++i) v[i] = av[i];
}

int main()
{
	freopen("algsort.in", "rt", stdin);
	freopen("algsort.out", "wt", stdout);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

	merge_sort(0, n - 1);

	for (int i = 0; i < n; ++i) printf("%d ", v[i]);
	printf("\n");

	return 0;
}
