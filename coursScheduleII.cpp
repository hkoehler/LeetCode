// https://leetcode.com/problems/course-schedule-ii/

class Solution {
    
    struct Node {
        Node(int v) : val(v) {}
        int val;
        int indegree = 0;   // dependent nodes
        int visited = false;
        vector<Node*> nbs;
    };
    
    unordered_map<int, Node*> nodes;
    
public:
    Node *lookup(int n) {
        auto node = nodes.find(n);
        if (node != nodes.end())
            return node->second;
        auto newNode = new Node(n);
        nodes[n] = newNode;
        return newNode;
    }

    void build(vector<pair<int, int>> &edges) {
        for (auto &e : edges) {
            // first node depends on second
            auto first = lookup(e.first);
            auto second = lookup(e.second);
            first->indegree++;
            second->nbs.push_back(first);
        }
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        queue<Node *> q;
        vector<int> res;
        
        if (prerequisites.empty())
            return {};
        
        build(prerequisites);
        
        // find all node with in-degree 1
        for (auto node : nodes)
            if (node.second->indegree == 0)
                q.push(node.second);
        
        // process all nodes
        while (!q.empty()) {
            auto node = q.front();
            
            q.pop();
            // cycle!
            if (node->visited) {
                res = {};
                break;
            }
            node->visited = true;
            res.push_back(node->val);
            if (res.size() == numCourses)
                break;
            for (auto nb : node->nbs) {
                q.push(nb);
            }
        }
        return res;
    }
};