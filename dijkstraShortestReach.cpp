#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int x, y;
    int r;
};

struct Node {
    // map x to (r, y)
    vector<pair<int, int>> edges;
};

bool compare(const Edge &lhs, const Edge &rhs) {
    return lhs.r > rhs.r;
}

void queueNode(vector<Edge> &queue, vector<Node> &graph, int node) {
    for (auto e : graph[node].edges) {
        Edge newEdge = {node, e.second, e.first};
        queue.push_back(newEdge);
        push_heap(queue.begin(), queue.end(), compare);
        //cout << "queue x=" << node << " y=" << e.second << " r=" << e.first << endl;
    }
}

Edge dequeueEdge(vector<Edge> &queue) {
    Edge e;
    
    pop_heap(queue.begin(), queue.end(), compare);
    e = queue.back();
    queue.pop_back();
    //cout << "dequeue x=" << e.x << " y=" << e.y << " r=" << e.r << endl;
    return e;
}

vector<int> shortestPath(vector<Node> &graph, int start) {
    vector<Edge> queue;
    vector<int> dist(graph.size(), -1);
    int n = graph.size() - 1;
    
    if (n <= 1)
        return {};
    // queue first node
    dist[start] = 0;
    queueNode(queue, graph, start);
    while (!queue.empty()) {
        auto edge = dequeueEdge(queue);

        if (dist[edge.y] == -1) {
            dist[edge.y] = dist[edge.x] + edge.r;
            queueNode(queue, graph, edge.y);
        } else if (dist[edge.x] + edge.r < dist[edge.y])
            dist[edge.y] = dist[edge.x] + edge.r;
    }
    return dist;
}

int main() {
    int numTests;
    
    cin >> numTests;
    for (int t = 0; t < numTests; t++) {
        int n, m;
        vector<Node> graph;
        int start;
        
        cin >> n >> m;
        graph.resize(n + 1); // index starts at 1
        for (int i = 0; i < m; i++) {
            int x, y, r;
            
            cin >> x >> y >> r;
            graph[x].edges.push_back(make_pair(r, y));
            graph[y].edges.push_back(make_pair(r, x));
        }
        cin >> start;
        auto res = shortestPath(graph, start);
        // print distances of N - 1 nodes from node 1
        for (int j = 1; j < res.size(); j++)
            if (j != start)
                cout << res[j] << " ";
        cout << endl;
    }
    
    return 0;
}

