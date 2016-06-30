#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Heap
{
public:
	void add(size_t v);
	void print();
	double median();
private:
	void bubbleUp(size_t i);
	size_t parent(size_t i) {
		return (i-1) / 2;
	}
	size_t left(size_t i) {
		return i*2+1;
	}
	size_t right(size_t i) {
		return i*2+2;
	}
	void swap(size_t i, size_t j) {
		auto tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	}
	size_t n = 0;
	std::vector<size_t> heap;
};

void Heap::bubbleUp(size_t i) {
	while (i > 0) {
		size_t p = parent(i);
		size_t l = left(p);
		size_t r = right(p);
		// swap child w/ parent if child < parent
		if (heap[i] < heap[p])
			swap(i, p);
		// swap siblings if right < left child
		if (l < n && r < n && heap[l] > heap[r])
			swap(l, r);
		i = p;
	}
}

void Heap::add(size_t v) {
	heap.resize(++n);
	heap[n-1] = v;
	bubbleUp(n-1);
}

void Heap::print() {
	for (auto v : heap)
		cout << v << " ";
	cout << endl;
}

double Heap::median() {
	if (n % 2 == 0) {
		size_t v1 = heap[n/2];
		size_t v2 = heap[n/2-1];
		return ((double)v1 + v2) / 2;
	} else {
		return heap[n/2];
	}
}

int main()
{
	size_t N;
	Heap heap;

	cin >> N;
	for (int i = 0; i < N; i++) {
		size_t v;
		cin >> v;
		heap.add(v);
	    cout << heap.median() << endl;
	}
	heap.print();

	return 0;
}
