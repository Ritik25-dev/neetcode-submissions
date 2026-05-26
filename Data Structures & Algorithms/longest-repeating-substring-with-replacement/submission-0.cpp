class Solution {
public:
    int characterReplacement(string s, int k) {
         int ft = 0, sd = 0;
        int freq = INT_MIN;
        int ans = INT_MIN;
        vector <int> freqArr(26,0);
        while(sd<s.size()){
            freqArr[s[sd]-'A']++;
            freq = max(freq,freqArr[s[sd]-'A']);
            if((sd-ft+1)-freq>k){
                freqArr[s[ft]-'A']--;
                ft++;
            }
            ans = max(ans, sd-ft+1);
            sd++;
        }
        return ans;
    }
};
