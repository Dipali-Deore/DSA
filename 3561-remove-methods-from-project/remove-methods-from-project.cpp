class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Adjacency list
        vector<vector<int>> graph(n);

        // Build graph
        for (auto &edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }

        // suspicious[i] = true if method i is reachable from k
        vector<bool> suspicious(n, false);

        // DFS to mark all suspicious methods
        function<void(int)> dfs = [&](int node) {

            suspicious[node] = true;

            for (int next : graph[node]) {
                if (!suspicious[next])
                    dfs(next);
            }
        };

        dfs(k);

        // Check whether any non-suspicious method
        // invokes a suspicious method.
        for (auto &edge : invocations) {

            int from = edge[0];
            int to = edge[1];

            if (!suspicious[from] && suspicious[to]) {

                // Invalid removal.
                vector<int> ans;

                for (int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        // Removal is possible.
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};