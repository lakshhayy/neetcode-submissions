class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, vector<int>& nums, vector<int>& temp,
    int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=start; i<nums.size(); i++){
            if(nums[i] > target){
                continue;
            }
            temp.push_back(nums[i]);
            solve(i,nums,temp,target-nums[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(0,nums,temp,target);
        return ans;
    }
};
