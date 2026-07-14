class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        sort(nums.begin(), nums.end());

        for (int num : nums) {
            ++count[num];
            if(count[num]>nums.size()/2) {
                return num;
                break;
            }
        }


    }
};