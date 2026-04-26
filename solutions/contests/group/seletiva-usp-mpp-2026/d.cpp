#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<vector<int>> msg(n, vector<int>());
    unordered_map<int, vector<int>> index;

    for (int i=0;i<n;i++){
        int k;
        cin >> k;

        for (int j=0;j<k;j++){
            int x;
            cin >> x;
            msg[i].push_back(x);
        }

        sort(msg[i].begin(), msg[i].end());
        msg[i].erase(unique(msg[i].begin(), msg[i].end()), msg[i].end());

        for (int x : msg[i]) {
            index[x].push_back(i);
        }
    }

    
    for (int i=0;i<n;i++){
        for (int x : msg[i]){

            for (int m : index[x]){
                if (m <= i) continue;

                auto it = upper_bound(msg[m].begin(), msg[m].end(), x);
                auto jt = upper_bound(msg[i].begin(), msg[i].end(), x);
                
                while (it != msg[m].end() && jt != msg[i].end()){
                    if (*it < *jt) ++it;
                    else if (*jt < *it) ++jt;
                    else {
                        cout << x  << " " << *it << " " << i+1 << " " << m+1;
                        return;
                    }
                
                }
            }
        }
    }

    cout << "impossible";
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}