class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(char ch: s){
          if(ch != ')'){
            st.push(ch);
          }else{
               string part = "";
                while(!st.empty() && st.top() != '('){
                part += st.top();
                st.pop();
          }
          if(!st.empty() && st.top() == '('){
          st.pop();
          }
            for(char ch :part){
                st.push(ch);
            }
          }
         
      
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};