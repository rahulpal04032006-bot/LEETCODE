class Solution {
public:
    string decodeString(string s) {
        stack<int>st1;
        stack<string>st2;
        int num = 0;
        string curr = "";
        for(char ch:s){
            if(isdigit(ch)){
                num = num*10 + (ch - '0');
            }else if(ch == '['){
                st1.push(num);
                st2.push(curr);
                num = 0;
                curr = "";
            }else if(ch == ']'){
                int k = st1.top();
                st1.pop();
                string prev = st2.top();
                st2.pop();
                while(k--){
                    prev += curr;
                }
                curr = prev;
            }else{
                curr += ch;
            }
        }
        return curr;
    }
};