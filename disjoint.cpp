#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 100000;

int n, m;
int v[kMaxN + 1];

int find_root(int a)
{
	while (v[a]) {
		a = v[a];
	}
	return a;
}

void mark_set(int a, int mark)
{
	int x;
	while (v[a]) {
		x = a;
		a = v[a];
		v[x] = mark;
	}
}

int main()
{
	freopen("disjoint.in", "rt", stdin);
	freopen("disjoint.out", "wt", stdout);

	int  r1, r2;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		switch (op) {
		case 1: //Reunite
			r1 = find_root(a);
			r2 = find_root(b);
			v[r1] = r2;
			mark_set(a, r2);
			break;
		case 2: //Query
			r1 = find_root(a);
			r2 = find_root(b);
			mark_set(a, r1);
			mark_set(b, r2);
			if (r1 == r2) printf("DA\n");
			else printf("NU\n");
			break;
		}
	}

	return 0;
}
