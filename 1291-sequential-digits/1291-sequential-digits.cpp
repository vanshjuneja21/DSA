class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;
        int minLen = to_string(low).size();
        int maxLen = to_string(high).size();
        for (int len = minLen; len <= maxLen; len++) {
            for (int start = 0; start + len <= 9; start++) {
                int num = stoi(digits.substr(start, len));
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};