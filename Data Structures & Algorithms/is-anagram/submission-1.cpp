class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> freq(26,0);

        for(int i =0; i<s.size(); i++){
            freq[tolower(s[i])-'a']++;
        }
        for(int i =0; i<t.size(); i++){
            if(freq[tolower(t[i])-'a']<=0){
                return false;
            }
            freq[tolower(t[i])-'a']--;
        }
        for(int i = 0; i<26; i++){
            if(freq[i]>0){
                return false;
            }
        }
        return true;
    }
};
