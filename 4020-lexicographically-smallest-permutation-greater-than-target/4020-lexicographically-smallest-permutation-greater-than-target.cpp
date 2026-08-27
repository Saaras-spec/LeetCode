class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        string matched;
        int i = 0;
        while (i < n && cnt[target[i] - 'a'] > 0) {
            int idx = target[i] - 'a';
            cnt[idx]--;
            matched.push_back(target[i]);
            i++;
        }
        
        int L = i;
        if (L == n) {
            
            L--;
            char c = matched.back();
            matched.pop_back();
            cnt[c - 'a']++;
        }
        
        while (true) {
            int found = -1;
            for (int code = target[L] - 'a' + 1; code < 26; code++) {
                if (cnt[code] > 0) {
                    found = code;
                    break;
                }
            }
            
            if (found != -1) {
                cnt[found]--;
                string rest;
                for (int code = 0; code < 26; code++) {
                    if (cnt[code] > 0) {
                        rest.append(cnt[code], 'a' + code);
                    }
                }
                return matched + char('a' + found) + rest;
            }
            
            if (L == 0) return "";
            
            L--;
            char c = matched.back();
            matched.pop_back();
            cnt[c - 'a']++;
        }
    }
};