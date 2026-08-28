class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        string ans = "";

        for(int i=2;i<=n-2;i++){
            int x=n;

            while (x > 0) {
                int rem = x % i;

                if (rem < 10) ans += char('0' + rem);
                else            ans += char('A' + (rem - 10));        
                x /= i;
            }
            string k = ans;

            reverse(ans.begin(), ans.end());
            if(k!=ans)            return false;
        
        }
        

        return true;;

        
        
    }
};