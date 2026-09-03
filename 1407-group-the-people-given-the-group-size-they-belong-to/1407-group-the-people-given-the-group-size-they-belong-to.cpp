class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> sizeToPeople;
        vector<vector<int>> result;
        
        for (int person = 0; person < groupSizes.size(); person++) {
            int size = groupSizes[person];
            sizeToPeople[size].push_back(person);
            
            if (sizeToPeople[size].size() == size) {
                result.push_back(sizeToPeople[size]);
                sizeToPeople[size].clear();
            }
        }
        
        return result;
    }
};