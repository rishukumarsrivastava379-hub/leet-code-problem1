#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(string a, string b) {
        parent[find(a)] = find(b);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        // Step 1: initialize
        for (auto &acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                parent[acc[i]] = acc[i];
                emailToName[acc[i]] = name;
            }
        }

        // Step 2: union emails in same account
        for (auto &acc : accounts) {
            for (int i = 2; i < acc.size(); i++) {
                unite(acc[i], acc[1]);
            }
        }

        // Step 3: group emails
        unordered_map<string, set<string>> groups;
        for (auto &p : parent) {
            string root = find(p.first);
            groups[root].insert(p.first);
        }

        // Step 4: build result
        vector<vector<string>> result;

        for (auto &g : groups) {
            vector<string> temp;
            temp.push_back(emailToName[g.first]);

            for (auto &email : g.second) {
                temp.push_back(email);
            }

            result.push_back(temp);
        }

        return result;
    }
};