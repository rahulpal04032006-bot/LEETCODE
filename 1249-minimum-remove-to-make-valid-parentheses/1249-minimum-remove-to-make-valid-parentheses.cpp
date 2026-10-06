class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack<char>st;
        // string ans = "";
        // int count1 = 0,count2 = 0;
        // for(char ch: s){
        //     if(ch == '('){
        //          count1++;
        //         if(count1 - count2 > 0)
        //         st.push(ch);
               
        //     }else if(ch == ')'){
        //         count2++;
        //         if(count1 - count2 >= 0){
        //             st.push(ch);
        //         }else{
                    
        //             continue;
        //         }
        //     }else{
        //         st.push(ch);
        //     }
        // }
        // while(!st.empty()){
        //     ans += st.top(); 
        //     st.pop(); 
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(!st.empty())
                st.pop();
                else
                s[i] = '#';
            }
        }
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        string ans = "";
       for(char ch :s){
        if(ch != '#'){
            ans += ch;
        }
       }
       return ans;
    }
};