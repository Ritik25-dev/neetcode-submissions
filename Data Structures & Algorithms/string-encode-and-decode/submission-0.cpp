class Solution {
public:

    string encode(vector<string>& strs) {
        char space = '0';
        string encoded = "";
        for(int i =0; i<strs.size();i++){
            for(int j =0; j<strs[i].size();j++){
                int asc = int(strs[i][j]) + 17;
                int ch = asc;
                encoded.push_back(ch);
            }
            encoded.push_back(space);
        }

        return encoded;

    }

    vector<string> decode(string s) {
        vector <string> ans;
        string temp = "";
        for(int i =0; i< s.size(); i++){
            if(s[i]=='0'){
                ans.push_back(temp);
                temp = "";
                continue;
            }
            int asc = int(s[i]) - 17;
            int ch = asc;
            temp.push_back(ch);
        }

        return ans;
    }
};
