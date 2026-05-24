// https://leetcode.com/problems/password-strength/

class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char, bool> seen;
        int ans = 0;
        for (char c : password) {
            if (seen[c]) continue;
            seen[c] = true;
            if (c == '!' || c == '@' || c == '#' || c == '$') ans += 5;
            else if (c >= '0' && c <= '9') ans += 3;
            else if (c >= 'A' && c <= 'Z') ans += 2;
            else if (c >= 'a' && c <= 'z') ans += 1;
        }
        return ans;
    }
};