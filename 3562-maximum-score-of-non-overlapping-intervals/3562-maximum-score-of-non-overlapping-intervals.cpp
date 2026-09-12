class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[1] != y[1]) return x[1] < y[1];
            return x[3] < y[3];
        });

        vector<long long> ends(n);
        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5)
        );

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 4; k++)
                dp[i][k] = dp[i - 1][k];

            int p = lower_bound(
                ends.begin(),
                ends.begin() + i - 1,
                a[i - 1][0]
            ) - ends.begin();

            for (int k = 1; k <= 4; k++) {
                auto candidate = dp[p][k - 1];

                candidate.first += a[i - 1][2];
                candidate.second.push_back(a[i - 1][3]);

                sort(candidate.second.begin(), candidate.second.end());

                auto& cur = dp[i][k];

                if (candidate.first > cur.first ||
                    (candidate.first == cur.first &&
                     candidate.second < cur.second)) {
                    cur = candidate;
                }
            }
        }

        return dp[n][4].second;
    }
};