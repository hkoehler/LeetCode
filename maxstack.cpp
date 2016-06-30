#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Stack {
public:
	void push(size_t v) {
		if (s.empty())
			ms.push_back(v);
		else
			ms.push_back(std::max(v, ms.back()));
		s.push_back(v);
	}

	size_t pop() {
		s.pop_back();
		ms.pop_back();
	}

	size_t max() {
		return ms.back();
	}
private:
	vector<size_t> s;
	vector<size_t> ms;
};

int main() {
	int cmd;
	int n;
	int v;
	Stack stack;
	
	cin >> n;
	while (n--) {
		cin >> cmd;
		switch (cmd) {
		case 1:
			cin >> v;
			stack.push(v);
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			cout << stack.max() << endl;
			break;
		default:
			cerr << "invalid cmd " << cmd << endl;
			break;
		}
	}
	return 0;
}
