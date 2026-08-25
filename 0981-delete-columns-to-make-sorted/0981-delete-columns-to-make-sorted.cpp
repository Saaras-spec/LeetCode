class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int R = strs.size(), C = strs[0].size();

        int ans = 0;
        for (int c = 0; c < C; ++c)
            for (int r = 1; r < R; ++r)
                if (strs[r][c] < strs[r - 1][c]) {
                    ++ans;
                    break;
                }
        
        return ans;
    }
};