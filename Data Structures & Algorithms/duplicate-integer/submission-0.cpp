class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_map<int, int> element;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            element[nums[i]] = element[nums[i]] + 1;
        }

        for (int j = 0; j < n; j++) {
            if (element[nums[j]] > 1) {
                return true;
            }
            else {
                continue;
            }
        }

        return false;  
    }
};