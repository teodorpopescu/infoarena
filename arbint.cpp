#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 128 * 1024;

int n, m;
int tree[2 * kMaxN]; //root is 1

void tree_insert(int p, int l, int r, int k, int x)
{
	if (l == k && r == k + 1) {
		tree[p] = x;
		return;
	}
	int mid = (l + r) / 2;
	if (k < mid) tree_insert(p * 2, l, mid, k, x);
	else tree_insert(p * 2 + 1, mid, r, k, x);
	tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
}

int tree_query(int p, int l, int r, int a, int b)
{
	if (l == a && r == b) return tree[p];
	int mid = (l + r) / 2;
	if (l <= a && b <= mid) return tree_query(p * 2, l, mid, a, b);
	else if (mid <= a && b <= r) return tree_query(p * 2 + 1, mid, r, a, b);
	else return max(tree_query(p * 2, l, mid, a, mid),
	                tree_query(p * 2 + 1, mid, r, mid, b));
}
int main()
{
	freopen("arbint.in", "rt", stdin);
	freopen("arbint.out", "wt", stdout);

	int op, a, b;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		tree_insert(1, 1, n + 1, i, a);
	}
	for (int j = 1; j <= m; ++j) {
		scanf("%d %d %d", &op, &a, &b);
		switch (op) {
		case 0:
			printf("%d\n", tree_query(1, 1, n + 1, a, b + 1));
			break;
		case 1:
			tree_insert(1, 1, n + 1, a, b);
			break;
		}
	}

	return 0;
}
