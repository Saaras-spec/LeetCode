class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<int,string>> v;
        string s="";
        int x =0;
        text[0]=tolower(text[0]);

        for(char c:text){
            if(c==' '){
                v.push_back({x,s});
                s="";
                x=0;
            }else{
                s+=c;
                x++;
            }       

        }
        v.push_back({x,s});
        stable_sort(v.begin(), v.end(), [](auto &a, auto &b) {return a.first < b.first;});
        s="";
        for(auto &p : v){
            s+= p.second + ' ';
        }
        s[0]=toupper(s[0]);
        s.pop_back();
        return s;



        
    }
};