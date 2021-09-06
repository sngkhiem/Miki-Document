#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e3+5;

int n;
vector<int> nums,sub;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cur; cin >> cur;
        nums.push_back(cur);
    }

    for (auto x: nums)
        if (sub.empty() || sub[sub.size()-1] < x) sub.push_back(x);
        else {
            auto it = lower_bound(sub.begin(),sub.end(),x);
            *it = x;
        }

    cout << sub.size();
    return 0;
}
