// https://leetcode.com/problems/minimum-height-trees/

#include <array>
#include <string>
#include <locale>
#include <iostream>

using namespace std;

class Solution {
public:
    int walk(int node, vector<pair<int, int>> edges) {
        vector<pair<int, int>> direct_edges;
        vector<pair<int, int>> indirect_edges;
        int depth = 0;
        
        for (auto &e : edges)
            if (e.first == node || e.second == node)
                direct_edges.push_back(e);
            else
                indirect_edges.push_back(e);
            
        while (direct_edges.size()) {
            auto e = direct_edges.back();
            direct_edges.pop_back();
            int n = (e.first == node) ? e.second : e.first;
            int d = walk(n, indirect_edges) + 1;
            if (d > depth)
                depth = d;
        }
        return depth;
    }
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        vector<pair<int, int>> res;
        int min = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int h = walk(i, edges);
            res.push_back(make_pair(i, h));
            if (h < min)
                min = h;
        }
        for (auto &r : res)
            if (r.second == min)
                ret.push_back(r.first);
        return ret;
    }
};

class Solution {
public:
    struct Node {
        vector<Node*> nodes;
        int num;
        int root;
    };
    vector<Node> allNodes;
    
    int walk(int root, Node *node, int depth, int minTreeHeight) {
        int maxDepth = depth;
        
        //cout << "walk" << node->num << endl;
        if (depth > minTreeHeight)
            return maxDepth;
        node->root = root;
        for (auto &n : node->nodes) {
            if (n->root != root) {
                int d = walk(root, n, depth+1, minTreeHeight);
                maxDepth = max(maxDepth, d);
            }
        }
        return maxDepth;
    }
    
    void convert(int n, vector<pair<int, int>> &edges) {
        allNodes.resize(n);
        for (int i = 0; i < n; i++) {
            allNodes[i].num = i;
            allNodes[i].root = -1;
        }
        for (auto &edge : edges) {
            allNodes[edge.first].nodes.push_back(&allNodes[edge.second]);
            allNodes[edge.second].nodes.push_back(&allNodes[edge.first]);
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        vector<pair<int, int>> res;
        int min = INT_MAX;
        
        convert(n, edges);
        for (int i = 0; i < n; i++) {
            int h = walk(i, &allNodes[i], 1, min);
            res.push_back(make_pair(i, h));
            if (h < min) {
                min = h;
                //cout << "min height tree " << min << endl;
            }
        }
        for (auto &r : res)
            if (r.second == min)
                ret.push_back(r.first);
        return ret;
    }
};

class Solution {
public:
    struct Node {
        set<Node*> nodes;
        int num;
        int depth;
    };
    vector<Node> allNodes;
    
    void convert(int n, vector<pair<int, int>> &edges) {
        allNodes.resize(n);
        for (int i = 0; i < n; i++) {
            allNodes[i].num = i;
            allNodes[i].depth = 0;
        }
        for (auto &edge : edges) {
            allNodes[edge.first].nodes.insert(&allNodes[edge.second]);
            allNodes[edge.second].nodes.insert(&allNodes[edge.first]);
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        deque<Node*> queue;
        deque<Node*> visited;
        
        if (n == 0)
            return {};
        if (n == 1)
            return {0};
        
        convert(n, edges);
        
        // queue all verices with degree 1
        for (auto &curr : allNodes)
            if (curr.nodes.size() == 1)
                queue.push_back(&curr);

        // BFS topological sorting
        while (!queue.empty()) {
            auto curr = queue.front();
            
            queue.pop_front();
            visited.push_back(curr);
            for (auto &adj : curr->nodes) {
                adj->nodes.erase(curr);
                if (adj->nodes.size() == 1) {
                    adj->depth = curr->depth + 1;
                    queue.push_back(adj);
                }
            }
        }
        
        int depth = visited.back()->depth;
        ret.push_back(visited.back()->num);
        visited.pop_back();
        if (!visited.empty() && visited.back()->depth == depth)
            ret.push_back(visited.back()->num);
        
        sort(ret.begin(), ret.end());
        return ret;
    }
};


