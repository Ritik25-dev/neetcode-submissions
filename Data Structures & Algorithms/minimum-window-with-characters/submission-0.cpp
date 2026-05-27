class Solution {
public:
    string minWindow(string s, string t) {
        vector <int> freq(128,0);
       int counter = t.size();

       for(char ch : t){
        freq[ch]++;
       }
        int l =0,r=0;
        int st = 0;
        int len = INT_MAX;
       while(r<s.size()){
        if(freq[s[r]]>0){
            counter--;
            
        }
        freq[s[r]]--;
        while(counter == 0){
            if(r-l+1<len){
                len = r-l+1;
                st=l;
            }

            freq[s[l]]++;
            if(freq[s[l]]>0){
                counter++;
            }
            l++;

        }
        r++;
       }
       return len==INT_MAX?"":s.substr(st,len);
    }
};
