class Solution {
public:
    long long sumAndMultiply(int n) {
        int s=0;
        int a=n;
        while(a!=0){
            s+=1;
            a/=10;
        }
        long long x=0;
        a=n;
        long long sum=0;

        while(n!=0){
            if(n/int(pow(10,s-1))!=0)          x = x*10 + int(n/pow(10,s-1));
            sum+=n/int(pow(10,s-1));
            n = n%int(pow(10,s-1));
            s--;            
        }
        return x*sum;

        
    }
};