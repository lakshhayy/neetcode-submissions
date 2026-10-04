class Solution {
public:
    bool check(int i, int j, vector<vector<int>> &dp, string &s){
        if(i >= j){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j] = check(i+1,j-1,dp,s);
        }
        return 0;
    }

    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(i,j,dp,s)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
