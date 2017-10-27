#include <bits/stdc++.h>

using namespace std;

const int kAlphabetSize = 26;
const int kMaxN = 100;

int ans[kMaxN];

typedef struct _trie_node_t {
	int ctr;
	vector<int> ending_strings;
	struct _trie_node_t** v;
	struct _trie_node_t* suffix_link, *parent;
} trie_node_t;

inline int char_to_int(char c)
{
	return c - 'a';
}

int wtf = 0;
trie_node_t* build_node(trie_node_t* p)
{
	trie_node_t* x = new trie_node_t;
	x->v = new trie_node_t*[kAlphabetSize];
	for (int i = 0; i < kAlphabetSize; ++i) x->v[i] = nullptr;
	x->suffix_link = nullptr;
	x->parent = p;
	x->ctr = 0;
	return x;
}

void insert_string(trie_node_t *r, string& s, int no)
{
	for (auto c : s) {
		int x = char_to_int(c);
		if (r->v[x] == nullptr) r->v[x] = build_node(r);
		r = r->v[x];
	}
	r->ending_strings.push_back(no);
}

void build_suffix_links(trie_node_t *r)
{
	queue<trie_node_t*> Q;
	for (int i = 0; i < kAlphabetSize; ++i) {
		if (r->v[i] == nullptr) continue;
		r->v[i]->suffix_link = r;
		Q.push(r->v[i]);
	}
	while (!Q.empty()) {
		r = Q.front();
		Q.pop();
		for (int i = 0; i < kAlphabetSize; ++i) {
			if (r->v[i] == nullptr) continue;
			trie_node_t *link = r->suffix_link;
			while (link->parent != nullptr && link->v[i] == nullptr) {
				link = link->suffix_link;
			}
			if (link->v[i] != nullptr) link = link->v[i];
			r->v[i]->suffix_link = link;
			Q.push(r->v[i]);
		}
	}
}

void ahocorasick(trie_node_t *r, string& s)
{
	trie_node_t *link = r;
	for (int i = 0; i < s.size(); ++i) {
		int x = char_to_int(s[i]);
		while (link->parent != nullptr && link->v[x] == nullptr) {
			link = link->suffix_link;
		}
		if (link->v[x] != nullptr) link = link->v[x];
		++link->ctr;
	}
}

void count_patterns(trie_node_t *r)
{
	vector<trie_node_t*> order;
	queue<trie_node_t*> Q;
	Q.push(r);
	while (!Q.empty()) {
		r = Q.front();
		Q.pop();
		for (int i = 0; i < kAlphabetSize; ++i) {
			if (r->v[i] != nullptr) Q.push(r->v[i]);
		}
		order.push_back(r);
	}
	for (auto it = order.rbegin(); it != order.rend(); ++it) {
		if ((*it)->parent != nullptr) (*it)->suffix_link->ctr += (*it)->ctr;
		for (auto x : (*it)->ending_strings) ans[x] += (*it)->ctr;
	}
}

int main()
{
	freopen("ahocorasick.in", "rt", stdin);
	freopen("ahocorasick.out", "wt", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	trie_node_t* trie;
	int n;
	string s;
	cin >> s >> n;
	trie = build_node(nullptr);
	for (int i = 0; i < n; ++i) {
		string t;
		cin >> t;
		insert_string(trie, t, i);
	}
	build_suffix_links(trie);
	ahocorasick(trie, s);
	count_patterns(trie);
	for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
	return 0;
}
