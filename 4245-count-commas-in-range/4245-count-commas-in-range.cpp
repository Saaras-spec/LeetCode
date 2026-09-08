class Solution {
public:
    int countCommas(int n) {
        int s =n;
        int x=0;
        while(n!=0){
            x+=1;
            n/=10;
        }
        if(x<4) return 0;
        int comma =0;
        if(x%3==0){
            comma = x/3 -1;
        }
        else{
            comma = x/3;
        }
        return (s-1000 +1)*comma;

        
    }
};