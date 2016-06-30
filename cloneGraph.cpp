// https://leetcode.com/problems/clone-graph/

#include <vector>
#include <map>  
#include <deque>

using namespace std;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};


// BFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // map old to new nodes
        map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
        // queue of old nodes to be copied/visited
        deque<UndirectedGraphNode *> q;
        
        if (node)
            q.push_back(node);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop_front();
            auto newNode = new UndirectedGraphNode(curr->label);
            nodeMap[curr] = newNode;
            for (auto neighbor : curr->neighbors) {
                auto iter = nodeMap.find(neighbor);
                if (iter == nodeMap.end())
                    q.push_back(neighbor);
                else {
                    auto newNeighbor = iter->second;
                    newNode->neighbors.push_back(newNeighbor);
                    if (newNode != newNeighbor)
                        newNeighbor->neighbors.push_back(newNode);
                }
            }
        }
        return node ? nodeMap[node] : nullptr;
    }
};


// DFS
class Solution {
    // map old to new nodes
    map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return nullptr;
        
        if (nodeMap.find(node) != nodeMap.end())
            return nodeMap[node];
        auto newNode = new UndirectedGraphNode(node->label);
        nodeMap[node] = newNode;
        for (auto neighbor : node->neighbors)
            newNode->neighbors.push_back(cloneGraph(neighbor));
        return newNode;
    }
};

