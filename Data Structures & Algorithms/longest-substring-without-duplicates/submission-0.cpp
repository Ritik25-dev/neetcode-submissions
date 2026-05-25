class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> freq;
        int st = 0, end = 0;
        int ans = 0;

        while(end<s.size()){
            if(freq.find(s[end]) == freq.end()){
                freq.insert(s[end]);
                ans = max(ans,end-st+1);
                end++;
            }else{
                freq.erase(s[st]);
                st++;
            }
            
        }
        return ans;
    }
};
