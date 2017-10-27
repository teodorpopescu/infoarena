#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 50000;
const int kInf = numeric_limits<int>::max() / 2;

int n, m;
int D[kMaxN + 1], in_queue_count[kMaxN + 1];
bool in_queue[kMaxN + 1];
vector<pair<int, int> > G[kMaxN + 1];
queue<int> Q;

int main()
{
	freopen("bellmanford.in", "rt", stdin);
	freopen("bellmanford.out", "wt", stdout);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) D[i] = kInf;

	for (int i = 0; i < m; ++i) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		G[a].push_back(make_pair(b, d));
	}

	in_queue_count[1] = 1;
	in_queue[1] = true;
	Q.push(1);
	D[1] = 0;

	bool run = true;
	while (run && !Q.empty()) {
		int a = Q.front();
		in_queue[a] = false;
		Q.pop();
		for (auto it = G[a].begin(); it != G[a].end(); ++it) {
			if (D[a] + it->second < D[it->first]) {
				D[it->first] = D[a] + it->second;
				++in_queue_count[it->first];
				if (in_queue_count[it->first] >= n) {
					run = false;
					break;
				}
				if (!in_queue[it->first]) {
					in_queue[it->first] = true;
					Q.push(it->first);
				}
			}
		}
	}

	if (!run) printf("Ciclu negativ!\n");
	else {
		for (int i = 2; i <= n; ++i) printf("%d ", D[i]);
		printf("\n");
	}

	return 0;
}
