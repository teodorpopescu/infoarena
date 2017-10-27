#include <bits/stdc++.h>

using namespace std;

const int kInf = numeric_limits<int>::max() / 2;

int main()
{
	freopen("ssm.in", "rt", stdin);
	freopen("ssm.out", "wt", stdout);

	int n;
	int s = -kInf, k, l, aux_s = -kInf, aux_k, aux_l;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int aux;
		scanf("%d", &aux);
		if (aux_s >= 0) {
			aux_s += aux;
			++aux_l;
		} else {
			aux_s = aux;
			aux_k = i;
			aux_l = 1;
		}
		if (aux_s > s) {
			s = aux_s;
			k = aux_k;
			l = aux_l;
		}
	}

	printf("%d %d %d\n", s, k, l + k - 1);

	return 0;
}
