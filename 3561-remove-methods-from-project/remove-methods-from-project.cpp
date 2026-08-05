class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<int> in(n);
        vector<vector<int>> adj(n);
        for (auto it : invocations) {
            ++in[it[1]];
            adj[it[0]].push_back(it[1]);
        }

        queue<int> q;
        vector<bool> vis(n);

        q.push(k);
        vis[k] = true;

        vector<int> all(n);
        iota(all.begin(), all.end(), 0);

        while (q.size()) {
            int node = q.front();
            q.pop();

            for (auto child : adj[node]) {
                if(in[child] > 0) --in[child];
                if (!vis[child]) {
                    vis[child] = true;
                    q.push(child);
                }
            }
        }

        vector<int> rem;
        for (int i = 0; i < n; i++) {
            if (vis[i] and in[i] > 0) {
                return all;
            } else if (!vis[i]) {
                rem.push_back(i);
            }
        }
        return rem;
    }
};