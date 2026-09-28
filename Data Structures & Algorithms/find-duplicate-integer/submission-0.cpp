class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slo = nums[0];
        int fast = nums[nums[0]];

        while(slo != fast){
            slo = nums[slo];
            fast = nums[nums[fast]];
        }

        slo = 0;
        while(slo != fast){
            slo = nums[slo];
            fast = nums[fast];
        }

        return slo;
    }
};
