class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int n = s.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        int ans = 0;

        while(r < n){
            mp[s[r]]++;
            cnt = max(cnt, mp[s[r]]);

            while(r-l+1 - cnt > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
