class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=1;i<s.size()+1;i++ ){
            sum += i*(abs(s[i-1]-'z') +1);
        }
        return sum;
    }
};