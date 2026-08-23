class Solution {
public:
    string toLowerCase(string s) {
        for(char &c :s){
            if(int(c) >=65 && int(c) <=90){
                c = char(int(c)+32);
            }
        }
        return s;
        
        
    }
};