class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int>m;
        for(auto x:s){
            if(m.count(x)!=0)return x;
            m[x]++;
        }
        return '-1';
        
    }
};