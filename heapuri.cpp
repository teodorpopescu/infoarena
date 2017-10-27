#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 400000;
const int kInf = numeric_limits<int>::max() / 2;

int n; //current input index;
int size; //size of the heap
int heap[kMaxN + 1]; //heap with root at v[1]
int kth_to_heap[kMaxN + 1]; //hold the position in heap of kth input
int heap_to_kth[kMaxN + 1]; //the input number of an element in heap

inline void heap_swap(int i, int j)
{
	kth_to_heap[heap_to_kth[i]] = j;
	kth_to_heap[heap_to_kth[j]] = i;
	swap(heap_to_kth[i], heap_to_kth[j]);
	swap(heap[i], heap[j]);
}
	

void heap_up(int i)
{
	while (i != 1 && heap[i] < heap[i / 2]) {
		heap_swap(i, i / 2);
		i /= 2;
	}
}

void heap_down(int i)
{
	while (heap[i] != kInf) {
		if (heap[i] > heap[2 * i]) {
			if (heap[2 * i] < heap[2 * i + 1]) {
				heap_swap(i, 2 * i);
				i = 2 * i;
			} else {
				heap_swap(i, 2 * i + 1);
				i = 2 * i + 1;
			}
		} else if (heap[i] > heap[2 * i + 1]) {
			heap_swap(i, 2 * i + 1);
			i = 2 * i + 1;
		} else break;
	}
}

void heap_init()
{
	for (int i = 0; i < kMaxN; ++i) heap[i] = kInf;
}

void heap_insert(int x)
{
	++size; ++n;
	heap[size] = x;
	kth_to_heap[n] = size;
	heap_to_kth[size] = n;
	heap_up(size);
}

void heap_erase(int k)
{
	int i = kth_to_heap[k];
	heap_swap(i, size);
	heap[size] = kInf;	
	--size;
	if (i != 1 && heap[i] < heap[i / 2]) {
		heap_up(i);
	} else {
		heap_down(i);
	}
}

int heap_top()
{
	return heap[1];
}

int main()
{
	freopen("heapuri.in", "rt", stdin);
	freopen("heapuri.out", "wt", stdout);

	int m;
	scanf("%d", &m);

	heap_init();
	
	for (int i = 0; i < m; ++i) {
		int op, x;
		scanf("%d", &op);
		switch (op) {
		case 1:
			scanf("%d", &x);
			heap_insert(x);
			break;
		case 2:
			scanf("%d", &x);
			heap_erase(x);
			break;
		case 3:
			printf("%d\n", heap_top());
			break;
		}
	}

	return 0;
}
