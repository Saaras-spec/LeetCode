class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int l=0;

        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(i!=n-1 && s[i+1]!= ' '){
                l=0;

                }
            
                
            }else{
                l +=1;
            }
        }
        return l;
        
    }
};