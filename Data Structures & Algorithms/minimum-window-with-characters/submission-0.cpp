class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        int len = INT_MAX;
        int ind = -1;
        unordered_map<char, int> mp;

        for(auto ch : t){
            mp[ch]++;
        }

        while(r < n){
            if(mp[s[r]] > 0){
                cnt++;
            }

            while(cnt == t.size()){
                if(r-l+1 < len){
                    len = r-l+1;
                    ind = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    cnt--;
                }
                l++;
            }

            mp[s[r]]--;
            r++;
        }

        if(len == INT_MAX){
            return "";
        }
        return s.substr(ind, len);
    }
};
