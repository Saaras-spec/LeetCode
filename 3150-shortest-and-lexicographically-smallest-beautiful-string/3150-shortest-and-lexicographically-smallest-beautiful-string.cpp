class Solution {
public:
    
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> v;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                v.push_back(i);
            }
        }
        if(v.size()==0 || v.size()<k) return "";
        if(v.size()!=0 && k==1) return "1";
        int i=0;
        int j=k-1;
        int a =0;
        int b=0;
        int m=INT_MAX;

        while(j<v.size()){
            int min =v[j]-v[i];
            if(min<m){
                m=min;
                a=v[i];
                b=v[j];
            }
            else if(min==m){
                int x=a;
                int y=b;
                int c=v[i];
                int d=v[j];
                bool check = false;
                while(x<=y && c<=d){
                    if(s[x]>s[c]){
                        check = true;
                        break;
                    }else if(s[x]<s[c]) break;
                    x++;
                    c++;
                }
                if(check){
                    a=v[i];
                    b=v[j];
                }

            }
            i++;
            j++;

        }
        string s1="";
        for(int j=a;j<=b;j++){
            s1+=s[j];
        }
        return s1;       


        
    }
};