// https://leetcode.com/problems/course-schedule-ii/

class Solution {
    
    struct Node {
        Node(int v) : val(v) {}
        int val;
        int indegree = 0;   // dependent nodes
        vector<Node*> nbs;
    };
    
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, Node*> nodes;
        queue<Node *> q;
        vector<int> res;
        size_t visited = 0;
        
        // create all nodes
        for (int n = 0; n < numCourses; n++)
            nodes[n] = new Node(n);

        // create edges
        for (auto &e : prerequisites) {
            // first node depends on second
            auto first = nodes[e.first];
            auto second = nodes[e.second];
            first->indegree++;
            second->nbs.push_back(first);
        }

        // queue all node with in-degree 0
        for (auto node : nodes)
            if (node.second->indegree == 0)
                q.push(node.second);
        
        // process all nodes
        while (!q.empty()) {
            auto node = q.front();
            
            q.pop();
            visited++;
            if (res.size() == numCourses)
                break;
            for (auto nb : node->nbs)
                if(--nb->indegree == 0)
                    q.push(nb);
            res.push_back(node->val);
        }
        if (visited == numCourses)
            return res;
        else
            return {};
    }
};
