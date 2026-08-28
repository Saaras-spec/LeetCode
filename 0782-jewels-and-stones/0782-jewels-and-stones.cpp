class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);

        for(char c:jewels){
            if(isupper(c)){
                v1[c-'A']++;
            }else{
                v2[c-'a']++;
            }
        }
        int x=0;
        for(char c:stones){
            if(isupper(c)){
                if(v1[c-'A']!=0) x++;
            }else{
                if(v2[c-'a']!=0) x++;
            }
        }     
        return x;   
    }
};