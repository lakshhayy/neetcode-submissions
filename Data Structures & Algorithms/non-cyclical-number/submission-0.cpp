class Solution {
public:
    int helper(int n){
        int sum = 0;
        while(n){
            int dig = n%10;
            sum = sum + dig*dig;
            n=n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slo = n;
        int fast = helper(n);

        while(slo != fast && fast != 1){
            slo = helper(slo);
            fast = helper(helper(fast));
        }
        if(fast == 1){
            return true;
        }
        return false;
    }
};
