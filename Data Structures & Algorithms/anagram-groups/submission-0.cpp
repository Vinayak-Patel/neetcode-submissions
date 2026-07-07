class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strsSorted;
        for (string str : strs) {
            string strSorted = str;
            sort(strSorted.begin(),strSorted.end());

            strsSorted.push_back(strSorted);
        }

        unordered_map<string, vector<int>> map;

        for (int i = 0; i < strs.size(); i++) {
            map[strsSorted[i]].push_back(i);
        }

        vector<vector<string>> output;
        for (auto const& pair : map) {
            vector<int> indices = pair.second;
            vector<string> group;

            for (int idx : indices) {
                group.push_back(strs[idx]);
            }

            output.push_back(group);
        }
        return output;
    }
};