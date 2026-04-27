// https://codeforces.com/gym/688480/problem/K

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int h; double m;

    cin >> h >> m;

    int hourAngle = 30 * (h / 30);

    if (h == (hourAngle + m/12)) cout << "yes";
    else cout << "no";
}
