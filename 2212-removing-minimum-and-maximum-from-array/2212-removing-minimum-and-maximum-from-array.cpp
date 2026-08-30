class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int left = max(minIdx, maxIdx) + 1;

        int right = n - min(minIdx, maxIdx);

        int both = min(minIdx, maxIdx) + 1
                 + n - max(minIdx, maxIdx);

        return min({left, right, both});
    }
};