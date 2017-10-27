#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 3000000;

int v[kMaxN];

int main()
{
	freopen("sdo.in", "rt", stdin);
	freopen("sdo.out", "wt", stdout);

	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
	nth_element(v, v + k - 1, v + n);
	printf("%d\n", v[k - 1]);

	return 0;
}	
