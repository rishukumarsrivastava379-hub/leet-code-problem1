#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        // 1 = visiting → cycle found
        if (state[node] == 1) return true;

        // 2 = already checked → no cycle
        if (state[node] == 2) return false;

        state[node] = 1; // mark as visiting

        for (int nei : adj[node]) {
            if (dfs(nei, adj, state)) return true;
        }

        state[node] = 2; // mark as visited
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // build graph
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0); // 0=unvisited

        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, adj, state)) return false; // cycle found
        }

        return true;
    }
};