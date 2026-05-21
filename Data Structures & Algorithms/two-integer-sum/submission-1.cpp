class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> next;
        vector <int> ans;
        for(int i=0; i<nums.size();i++){
            int second =target - nums[i];
            if(next.find(second) != next.end()){
                ans.push_back(next[second]);
                ans.push_back(i);
            }
            next[nums[i]] = i;
        }
        return ans;
    }
};