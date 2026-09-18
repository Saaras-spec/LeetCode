class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> intervals;
        for (int i = 0; i < n; i++) {
            int start = i;
            int end = last[s[i] - 'a'];
            bool valid = true;
            int j = i;
            while (j <= end) {
                int c = s[j] - 'a';
                if (first[c] < start) {
                    valid = false;
                    break;
                }
                end = max(end, last[c]);
                j++;
            }
            if (valid) intervals.push_back({start, end});
        }

        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        vector<string> res;
        int lastEnd = -1;
        for (auto& p : intervals) {
            if (p.first > lastEnd) {
                res.push_back(s.substr(p.first, p.second - p.first + 1));
                lastEnd = p.second;
            }
        }
        return res;
    }
};