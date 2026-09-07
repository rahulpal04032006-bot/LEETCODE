class Solution {
public:
    char kthCharacter(int k) {
       string word = "a";
     while(word.size() < k){
        string form;
        for(char c: word){
            form += c+1;
        }
        word += form;
     }
     return word[k-1];
    }
};