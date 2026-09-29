class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int idx = -1;
        for(int i=0;i<n;i++){
            if(ch == word[i]){
                idx = i;
                break;
            }
        }
        if(idx != -1){
            reverse(word.begin(),word.begin() + idx + 1);
        }
        return word;
    }
};