class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> freq;
        vector <vector<string>> ans;
        for(int i=0; i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            freq[s].push_back(strs[i]);
        }

        for(auto& val : freq){
            ans.push_back(val.second);
        }
        return ans;
    }
};
