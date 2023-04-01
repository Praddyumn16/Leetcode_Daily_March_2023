class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<vector<int>>> adj_list(n + 1);
        
        for(auto a : roads) {
            adj_list[a[0]].push_back({a[1] , a[2]});
            adj_list[a[1]].push_back({a[0] , a[2]});
        }

        int ans = INT_MAX;
        vector<int> visited(n + 1 , 0);
        visited[1] = 1;

        queue<int> q;
        q.push(1);

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                int curr = q.front();
                q.pop();
                for(auto a : adj_list[curr]) {
                    ans = min(ans , a[1]);
                    if(!visited[a[0]]) {
                        visited[a[0]] = 1;
                        q.push(a[0]);
                    }
                }
            }
        }

        return ans;
    }
};