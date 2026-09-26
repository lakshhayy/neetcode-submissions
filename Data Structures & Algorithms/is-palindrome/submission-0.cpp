class Solution {
public:
    bool isPalindrome(string s) {
        string check = "";

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                check += tolower(s[i]);
            }
        }

        string rev = check;
        reverse(rev.begin(), rev.end());

        return check == rev;
    }
};