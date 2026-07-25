class Solution {
public:
    void findComb(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans , int idx ){
        if(idx>=candidates.size()) return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        temp.push_back(candidates[idx]);
        findComb(candidates,target-candidates[idx],temp,ans,idx);
        temp.pop_back();
        findComb(candidates,target,temp,ans,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        findComb(candidates,target,temp,ans,0);
        return ans;
    }
};