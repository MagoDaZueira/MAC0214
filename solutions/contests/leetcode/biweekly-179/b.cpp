// https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people/

#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;

    ll fastPow(ll base, ll exp) {
        if (exp == 0) return 1;
        base %= mod;
        ll half = fastPow(base, exp / 2);
        ll half_sq = (half * half) % mod;
        
        if (exp % 2 == 0) {
            return half_sq;
        } else {
            return (half_sq * base) % mod;
        }
    }

    ll fact(ll n) {
        if (n == 1) return 1;
        return (n * fact(n-1)) % mod;
    }
    
    ll comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
    
        return fact(n) * fastPow(fact(k) * fact(n-k), mod - 2) % mod;
    }
    
    int countVisiblePeople(int n, int pos, int k) {
        return (comb(n-1, k) * 2) % mod;
    }
};