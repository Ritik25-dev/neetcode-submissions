class Solution {
public:
    bool isValid(string s) {
        stack <char> valid;

        for(char ch : s){
            if(ch == '(' || ch == '{' || ch =='['){
                valid.push(ch);
            }
            if(ch == ')' || ch == '}' || ch ==']'){
                if(valid.empty()) return false;
                char top = valid.top();
                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                    valid.pop();
                }else{
                    valid.push(ch);
                }
                
            }
        }

        if(valid.empty()){
            return true;
        }
        return false;
    }
};
