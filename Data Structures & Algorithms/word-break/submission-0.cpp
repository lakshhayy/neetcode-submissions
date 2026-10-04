class Solution {
public:
    unordered_set<string> st;

    bool solve(int i, string &s, vector<int> &dp){
        int n = s.size();
        if(i >= n){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        for(int x=i; x<n; x++){
            if(st.find(s.substr(i, x-i+1)) != st.end()){
                if(solve(x+1,s,dp)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto it : wordDict){
            st.insert(it);
        }
        vector<int> dp(n, -1);
        return solve(0,s,dp);
    }
};
