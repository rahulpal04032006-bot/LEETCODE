class Solution {
public:
    int compareVersion(string s1, string s2) {
    int i=0;
    int j=0;
    while(i < s1.size() || j < s2.size()){
        long long x = 0,y = 0;
        while(i < s1.size() && s1[i] != '.'){
            x = x*10 + (s1[i] - '0');
            i++;
        }
        while(j < s2.size() && s2[j] != '.'){
            y = y*10 + (s2[j] - '0');
            j++;
        }
        if(x > y)
        return 1;
        if(x < y)
        return -1;
        if(i < s1.size()){
            i++;
        }
        if(j < s2.size()){
            j++;
        }
    }
    return 0;
    }
};