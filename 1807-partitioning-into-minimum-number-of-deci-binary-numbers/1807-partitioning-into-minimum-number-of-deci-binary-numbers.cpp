class Solution {
public:
    int minPartitions(string n) {
        int m=INT_MIN;
        for(char c:n){
            m = max(m,c-'0');
        }
        return m;
        
    }
};