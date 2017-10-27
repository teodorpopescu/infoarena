#include <bits/stdc++.h>

using namespace std;

const int kMaxL = 20;
const int kTrieChildren = 'z' - 'a' + 1;

typedef struct node {
	int x, n;
	node *parent;
	int index_in_parent;
	node *children[kTrieChildren];
} node_t;

node_t *allocate_node(node_t *parent, int index_in_parent)
{
	node_t *p = new node_t;
	p->x = 0;
	p->n = 0;
	p->parent = parent;
	p->index_in_parent = index_in_parent;
	for (int i = 0; i < kTrieChildren; ++i) p->children[i] = NULL;
	return p;
}

//Assume all children are deallocated...
void deallocate_node(node_t *p)
{
	p->parent->children[p->index_in_parent] = NULL;
	delete p;
}

void trie_insert(node_t *root, char *word)
{
	node_t *p = root;
	for (int i = 0; word[i] != '\0'; ++i) {
		int index = word[i] - 'a';
		if (p->children[index] == NULL) {
			p->children[index] = allocate_node(p, index);
			++p->n;
		}
		p = p->children[index];
	}
	++p->x;
}

//Assume word does exist...
void trie_erase(node_t *root, char *word)
{
	node_t *p = root;
	for (int i = 0; word[i] != '\0'; ++i) {
		p = p->children[word[i] - 'a'];
	}
	--p->x;
	while (p != root && p->x == 0 && p->n == 0) {
		node_t *aux;
		aux = p;
		p = p->parent;
		deallocate_node(aux);
		--p->n;
	}
}

int trie_find(node_t *root, char *word)
{
	node_t *p = root;
	for (int i = 0; word[i] != '\0'; ++i) {
		int index = word[i] - 'a';
		if (p->children[index] == NULL) return 0;
		p = p->children[index];
	}
	return p->x;
}

int trie_prefix(node_t *root, char *word)
{
	int i;
	node_t *p = root;
	for (i = 0; word[i] != '\0'; ++i) {
		int index = word[i] - 'a';
		if (p->children[index] == NULL) return i;
		p = p->children[index];
	}
	return i;
}

int main()
{
	freopen("trie.in", "rt", stdin);
	freopen("trie.out", "wt", stdout);
	node_t *trie = allocate_node(NULL, 0);
	int op;
	char word[kMaxL + 1];

	while (scanf("%d %s", &op, word) == 2) {
		switch (op) {
		case 0:
			trie_insert(trie, word);
			break;
		case 1:
			trie_erase(trie, word);
			break;
		case 2:
			printf("%d\n", trie_find(trie, word));
			break;
		case 3:
			printf("%d\n", trie_prefix(trie, word));
			break;
		}
	}

	return 0;
}
