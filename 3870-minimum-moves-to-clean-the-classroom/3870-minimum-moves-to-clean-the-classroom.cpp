class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> id(m, vector<int>(n, -1));
        int sr = 0, sc = 0, k = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        if (k == 0) return 0;

        int masks = 1 << k;
        int total = m * n * masks;

        vector<unsigned char> best(total, 0);

        auto index = [&](int r, int c, int mask) {
            return ((r * n + c) * masks + mask);
        };

        struct State {
            int r, c, e, mask;
        };

        vector<State> q;
        q.reserve(total);

        int startMask = 0;
        int startIdx = index(sr, sc, startMask);
        best[startIdx] = energy + 1;
        q.push_back({sr, sc, energy, startMask});

        int head = 0;
        int moves = 0;

        static const int dr[4] = {1, -1, 0, 0};
        static const int dc[4] = {0, 0, 1, -1};

        while (head < (int)q.size()) {
            int end = q.size();

            while (head < end) {
                auto [r, c, e, mask] = q[head++];

                if (mask == masks - 1)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;

                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    int nmask = mask;

                    if (id[nr][nc] != -1)
                        nmask |= 1 << id[nr][nc];

                    int idx = index(nr, nc, nmask);

                    if (ne + 1 > best[idx]) {
                        best[idx] = ne + 1;
                        q.push_back({nr, nc, ne, nmask});
                    }
                }
            }

            ++moves;
        }

        return -1;
    }
};