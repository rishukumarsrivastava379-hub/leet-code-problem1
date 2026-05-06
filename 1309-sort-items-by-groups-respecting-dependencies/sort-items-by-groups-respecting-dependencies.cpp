#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    // Topological sort helper
    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& indegree, int n) {
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            result.push_back(node);

            for (int nei : adj[node]) {
                if (--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return result.size() == n ? result : vector<int>();
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        // Step 1: assign new group to -1 items
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }

        // Step 2: build graphs
        vector<vector<int>> itemAdj(n), groupAdj(m);
        vector<int> itemIndegree(n, 0), groupIndegree(m, 0);

        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {
                
                // item graph
                itemAdj[prev].push_back(i);
                itemIndegree[i]++;

                // group graph
                if (group[i] != group[prev]) {
                    groupAdj[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        // Step 3: topo sort groups
        vector<int> groupOrder = topoSort(groupAdj, groupIndegree, m);
        if (groupOrder.empty()) return {};

        // Step 4: topo sort items
        vector<int> itemOrder = topoSort(itemAdj, itemIndegree, n);
        if (itemOrder.empty()) return {};

        // Step 5: group items
        vector<vector<int>> groupedItems(m);
        for (int item : itemOrder) {
            groupedItems[group[item]].push_back(item);
        }

        // Step 6: build final answer
        vector<int> result;
        for (int g : groupOrder) {
            for (int item : groupedItems[g]) {
                result.push_back(item);
            }
        }

        return result;
    }
};