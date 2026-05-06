#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        // adjacency list: [node][color]
        vector<vector<vector<int>>> adj(n, vector<vector<int>>(2));

        // build graph
        for (auto &e : redEdges) {
            adj[e[0]][0].push_back(e[1]); // red
        }
        for (auto &e : blueEdges) {
            adj[e[0]][1].push_back(e[1]); // blue
        }

        // distance array
        vector<vector<int>> dist(n, vector<int>(2, -1));

        queue<pair<int,int>> q;

        // start from node 0 with both colors
        q.push({0, 0});
        q.push({0, 1});
        dist[0][0] = dist[0][1] = 0;

        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();

            // switch color
            int nextColor = 1 - color;

            for (int nei : adj[node][nextColor]) {
                if (dist[nei][nextColor] == -1) {
                    dist[nei][nextColor] = dist[node][color] + 1;
                    q.push({nei, nextColor});
                }
            }
        }

        // prepare answer
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1 && dist[i][1] == -1)
                ans[i] = -1;
            else if (dist[i][0] == -1)
                ans[i] = dist[i][1];
            else if (dist[i][1] == -1)
                ans[i] = dist[i][0];
            else
                ans[i] = min(dist[i][0], dist[i][1]);
        }

        return ans;
    }
};