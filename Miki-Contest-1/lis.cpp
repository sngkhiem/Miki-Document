#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e3+5;

int nums[N],len[N],n;

signed main() {
    cin >> n; for (int i = 1; i <= n; i++) cin >> nums[i];
    for (int i = 1; i <= n; i++) {
        len[i] = 1;
        for (int j = 1; j <= i; j++)
            if (nums[j] < nums[i]) len[i] = max(len[i],len[j]+1);
    }

    cout << *max_element(len+1,len+1+n);
    return 0;
}
