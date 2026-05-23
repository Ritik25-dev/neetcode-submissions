class Solution {
public:
    bool isPalindrome(string s) {
        string merged="";
        for(int i =0;i<s.size();i++){
            char c = tolower(s[i]);
            int asc = int(c);
            if((asc >= 65 && asc<=90) || (asc >= 97 && asc <= 122) || (asc>=48 && asc<=57)){
                merged.push_back(c);
            }
        }

        int st =0, end=merged.size()-1;
        while(st<end){
            if(merged[st] != merged[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};
