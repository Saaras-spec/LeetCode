class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> v;
        int mn = INT_MAX;

        for(int i = 0; i < arr.size() - 1; i++) {
            int diff = arr[i + 1] - arr[i];

            if(diff < mn) {
                mn = diff;
                v.clear();
                v.push_back({arr[i], arr[i + 1]});
            }
            else if(diff == mn) {
                v.push_back({arr[i], arr[i + 1]});
            }
        }

        return v;
    }
};