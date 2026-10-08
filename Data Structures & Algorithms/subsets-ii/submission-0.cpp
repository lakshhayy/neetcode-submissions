class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& temp, vector<int>& nums){
        ans.push_back(temp);
        
        for(int x=i; x<nums.size(); x++){
            if(x>i && nums[x] == nums[x-1]){
                continue;
            }
            temp.push_back(nums[x]);
            solve(x+1,temp,nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
      vector<int> temp;
      solve(0,temp,nums);
      return ans;  
    }
};
