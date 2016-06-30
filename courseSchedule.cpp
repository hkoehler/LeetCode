class Solution {
public:
    struct Node {
        set<Node *> adj;
        size_t indegree = 0;
        size_t num;
    };
    
    vector<Node> nodes;
    
    void convert(int n, vector<pair<int, int>> &edges) {
        int i = 0;
        nodes.resize(n);
        for (auto &n : nodes)
            n.num = i++;
        for (auto &e : edges) {
            if (nodes[e.first].adj.insert(&nodes[e.second]).second)
                nodes[e.second].indegree++;
        }
    }
    
    bool bfs() {
        deque<Node*> queue;
        size_t visited = 0;

        // queue nodes with indegree 0        
        for (auto &curr : nodes)
            if (curr.indegree == 0) {
                //cout << "queue " << curr.num << endl;
                queue.push_back(&curr);
            }
        while (!queue.empty()) {
            auto curr = queue.front();
            queue.pop_front();
            visited++;
            //cout << "dequeued " << curr->num << " with outdegree " << curr->adj.size() << endl;
            for (auto adj : curr->adj) {
                adj->indegree--;
                //cout << "indegree of " << adj->num << " = " << adj->indegree << endl;
                if (adj->indegree == 0) {
                    //cout << "queue " << adj->num << endl;
                    queue.push_back(adj);
                }
            }
        }
        //cout << "visited " << visited << endl;
        return visited == nodes.size();
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        convert(numCourses, prerequisites);
        return bfs();
    }
};
