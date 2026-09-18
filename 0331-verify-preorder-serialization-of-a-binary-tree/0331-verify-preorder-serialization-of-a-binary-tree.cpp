class Solution {
public:
    bool isValidSerialization(string preorder) {
        int st = 1;
        for(int i=0;i<preorder.size();i++){
          string part = "";
          while(i<preorder.size() && preorder[i] != ','){
            part += preorder[i];
            i++;
          }
          if(st == 0){
            return false;
          }
          if(part != "#"){
            st++;
          }else{
            st--;
          }
        }
        return st == 0;
    }
};