// OJ: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author: github.com/lzl124631x
// Time: O(C(N)) where C(N) is the count of the result given `input` of length N
// Space: O(C(N))
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for (int i = 0; i < input.size(); ++i) {
            if (isdigit(input[i])) continue;
            auto lefts = diffWaysToCompute(input.substr(0, i));
            auto rights = diffWaysToCompute(input.substr(i + 1));
            for (int left : lefts) {
                for (int right : rights) {
                    switch(input[i]) {
                        case '+': ans.push_back(left + right); break;
                        case '-': ans.push_back(left - right); break;
                        case '*': ans.push_back(left * right); break;
                    }
                }
            }
        }
        return ans.size() ? ans : vector<int>{ stoi(input) };
    }
};