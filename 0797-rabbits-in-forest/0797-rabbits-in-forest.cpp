class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> v(1000, 0);
        for (int i : answers) {
            v[i]++;
        }

        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > 0) {
                int groupSize = i + 1;
                int groups = (v[i] + groupSize - 1) / groupSize;
                sum += groups * groupSize;
            }
        }
        return sum;
    }
};