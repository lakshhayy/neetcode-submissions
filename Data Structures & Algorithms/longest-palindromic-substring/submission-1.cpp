class Solution {
public:
    int ind = 0;
    int maxlen = 0;

    bool check(int i, int j, string &s, vector<vector<int>> &dp){
        if(i >= j){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j] = check(i+1, j-1, s, dp);
        }
        return 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(i,j,s,dp)){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        ind = i;
                    }
                }
            }
        }
        return s.substr(ind,maxlen);
    }
};
