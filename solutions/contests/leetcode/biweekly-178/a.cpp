// https://leetcode.com/problems/first-unique-even-element/

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& num : nums) {
            m[num]++;
        }

        for (auto& num : nums) {
            if (num % 2 == 0 && m[num] == 1) {
                return num;
            }
        }

        return -1;
    }
};