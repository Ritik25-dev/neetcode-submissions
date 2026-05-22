class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> f;
        multimap <int, int, greater<int>> freq;
        for(int num : nums){
            f[num]++;
        }
        for(auto& val:f){
            freq.insert({val.second,val.first});
        }
        vector <int> ans;
        auto it = freq.begin();
        while(k>0){
            ans.push_back(it->second);
            it++;
            k--;
        }
        return ans;
    }
};
