class Solution {
public:
    vector<string> ans;

    void solve(int n, string s) {
        
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }


        solve(n, s + '1');

        
        if (s.empty() || s.back() != '0') {
            solve(n, s + '0');
        }
    }

    vector<string> validStrings(int n) {
        solve(n, "");
        return ans;
    }
};