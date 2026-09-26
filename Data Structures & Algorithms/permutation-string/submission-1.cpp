class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(auto it : s1){
            mp1[it]++;
        }

        int n = s2.size();
        int l = 0;
        int r = 0;

        while(r < n){
            mp2[s2[r]]++;

            while(r-l+1 == s1.size()){
                if(mp1 == mp2){
                    return true;
                }
                mp2[s2[l]]--;
                if(mp2[s2[l]] == 0){
                    mp2.erase(s2[l]);
                }
                l++;
            }
            r++;
        }
        return false;
    }
};
