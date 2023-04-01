class Solution {
public:
    int ans = 0 , row , col , mod = 1e9 + 7;

    bool check(int rs , int re , int cs , int ce , vector<string>& pizza) {
        for(int i = rs ; i <= re ; i++) 
            for(int j = cs ; j <= ce ; j++)
                if(pizza[i][j] == 'A')
                    return true;
        return false;
    }
    
    int solve(int rs , int cs , vector<string>& pizza , int k , vector<vector<vector<int>>>& dp) {
        
        if(k == 1) {
            if(check(rs , row - 1 , cs , col - 1 , pizza))
                return dp[rs][cs][k] = 1;
            return dp[rs][cs][k] = 0;
        }

        if(dp[rs][cs][k] != -1)
            return dp[rs][cs][k];
        
        int ans = 0;

        // making horizontal cuts
        for(int i = rs ; i <= row - 1 ; i++) {
            if(check(rs , i , cs , col - 1 , pizza))
                ans = (ans + solve(i + 1 , cs , pizza , k - 1 , dp)) % mod;
        }

        // making vertical cuts
        for(int i = cs ; i <= col - 1 ; i++) {
            if(check(rs , row - 1 , cs , i , pizza))
                ans = (ans + solve(rs , i + 1 , pizza , k - 1 , dp)) % mod;
        }

        return dp[rs][cs][k] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        row = pizza.size() , col = pizza[0].size();
        vector dp(row + 1 , vector(col + 1 , vector<int>(k + 1 , -1)));
        return solve(0 , 0 , pizza , k , dp);
    }
};