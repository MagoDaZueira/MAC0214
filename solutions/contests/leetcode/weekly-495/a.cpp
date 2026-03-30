// https://leetcode.com/problems/first-matching-character-from-both-ends/

// nem testei local, saí correndo pra dar submit de tão trivial

class Solution {
public:
    int firstMatchingIndex(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[s.size()-i-1]) return i;
        }
        return -1;
    }
};