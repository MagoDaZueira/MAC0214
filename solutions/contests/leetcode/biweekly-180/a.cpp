// https://leetcode.com/contest/biweekly-contest-180/problems/traffic-signal-color/description/

class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0) return "Green";
        if (timer == 30) return "Orange";
        if (timer > 30 && timer <= 90) return "Red";
        return "Invalid";
    }
};