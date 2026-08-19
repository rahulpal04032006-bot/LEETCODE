class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(char ch:s){
            if(ch == '('){
                st.push(0);
            }else{
                int x = st.top();
                st.pop();
               int ans = (x == 0)? 1:2*x;
                st.top() += ans;
            }
        }
        return st.top();
    }
};