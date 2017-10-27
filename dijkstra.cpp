#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 50000;
const int kInf = std::numeric_limits<int>::max();

int n, m;
int D[kMaxN + 1];
vector<pair<int, int> > G[kMaxN + 1];

void dijkstra(int s)
{ 
	auto comp = [](const pair<int, int> &a, const pair<int, int > &b) {
		return a.second > b.second;
	};
	priority_queue<pair<int, int>, vector<pair<int, int> >,
	               decltype (comp)> pQ(comp);
	pQ.push(make_pair(s, 0));
	while (!pQ.empty()) {
		int a = pQ.top().first;
		int d = pQ.top().second;
		pQ.pop();
		if (D[a] != kInf) continue;
		D[a] = d;
		for (auto it = G[a].begin(); it != G[a].end(); ++it) {
			if (D[(*it).first] != kInf) continue;
			pQ.push(make_pair((*it).first, d + (*it).second));
		}
	}
}

int main()
{
	freopen("dijkstra.in", "rt", stdin);
	freopen("dijkstra.out", "wt", stdout);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) D[i] = kInf;

	for (int i = 0; i < m; ++i) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		G[a].push_back(make_pair(b, d));
	}
	
	dijkstra(1);

	for (int i = 2; i <= n; ++i) printf("%d ", D[i] == kInf ? 0 : D[i]);
	printf("\n");

	return 0;
}
