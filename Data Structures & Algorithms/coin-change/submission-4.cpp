class Solution {
public:
    int solve(int i, int target, vector<vector<int>> &dp, vector<int>& coins){
        if(i == 0){
            if(target % coins[0] == 0){
                return target / coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(target == 0){
            return 0;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int notpick = solve(i-1,target,dp,coins);
        int pick = 1e9;
        if(target >= coins[i]){
            pick = 1 + solve(i,target - coins[i],dp,coins); // pick krlia toh dubara bhi pick krlo 
        } 
        return dp[i][target] = min(pick,notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<vector<int>> dp(n,vector<int>(amount+1,-1));
       int ans = solve(n-1,amount,dp,coins); 
       if(ans >= 1e9){
        return -1;
       }
       return ans;
    }
};