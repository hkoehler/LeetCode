#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int T;

class Graph {
public:
    Graph(int N) : nodes(N+1), distances(N+1, -1) {}
    
    void bfs(int node);
    
    // IN
    std::vector<std::pair<int, int>> edges;
    std::vector<int> nodes;
    
    // OUT
    std::vector<int> distances;
};

void Graph::bfs(int node) {
	std::list<int> queue;

	distances[node] = 0;
	queue.push_back(node);

	while (queue.empty() == false) {
		node = queue.front();
		queue.pop_front();
		for (auto edge : edges) {
			int next = -1;

			if (edge.first == node)
				next = edge.second;
			if (edge.second == node)
				next = edge.first;
			if (next != -1 && distances[next] == -1) {
				distances[next] = distances[node] + 6;
				queue.push_back(next);
			}
		}
	}
}

int main() {
    int T;
    
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M, S;
        
        std::cin >> N >> M;
        
        Graph graph(N);
        for (int m = 0; m < M; m++) {
            int x, y;
            std::cin >> x >> y;
            graph.edges.push_back(make_pair(x,y));
        }
        std::cin >> S;
        graph.bfs(S);
        for (int i = 1; i <= N; i++)
            if (i != S)
                std::cout << graph.distances[i] << " ";
        std::cout << std::endl;
    }
    
    return 0;
}

