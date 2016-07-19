// https://www.hackerrank.com/challenges/primsmstsub

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    // weight and destination
    vector<pair<int, int>> edges;
};

bool compare(pair<int, int> &lhs, pair<int, int> &rhs) {
    return lhs.first > rhs.first;
}

void push_edges(vector<pair<int, int>> &queue, Node &node) {
    for (auto &e : node.edges) {
        //cout << "queue " << e.second << endl;
        queue.push_back(e);
        push_heap(queue.begin(), queue.end(), compare);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<Node> nodes;
    vector<bool> visited;
    vector<pair<int, int>> queue;
    int numVisited = 0;
    int n, m;
    int res = 0;
    
    cin >> n >> m;
    if (n <= 1)
        return 0;
    nodes.resize(n+1);
    visited.resize(n+1);
    // read m edges
    for (int i = 0; i < m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        nodes[x].edges.push_back(make_pair(r, y));
        nodes[y].edges.push_back(make_pair(r, x));
    }
    
    // start with first node
    push_edges(queue, nodes[1]);
    visited[1] = true;
    numVisited++;
    while (numVisited < n && !queue.empty()) {
        pop_heap(queue.begin(), queue.end(), compare);
        auto e = queue.back();
        queue.pop_back();
        
        // node already visited
        if (visited[e.second])
            continue;
        //cout << "dequeued " << e.second << endl;
        res += e.first;
        numVisited++;
        visited[e.second] = true;
        push_edges(queue, nodes[e.second]);
    }
    
    cout << res << endl;
    return res;
}
