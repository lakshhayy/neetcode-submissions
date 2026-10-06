class Solution {
public:
    bool checkValidString(string s) {
        stack<int> brack;
        stack<int> aster;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                brack.push(i);
            }
            else if(s[i] == '*'){
                aster.push(i);
            }
            else{
                if(!brack.empty()){
                    brack.pop();
                }
                else if(!aster.empty()){
                    aster.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!brack.empty() && !aster.empty()){
            if(brack.top() > aster.top()){
                return false;
            }
            brack.pop();
            aster.pop();
        }

        return brack.empty();
    }
};