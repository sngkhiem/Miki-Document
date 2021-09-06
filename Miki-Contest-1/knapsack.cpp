#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define ll long long
#define MAX 100005

ll n, W[1005], V[1005], dp[MAX], k, a, b, c, N, C,w,v;
int main(){
    scanf("%d %d", &N, &C);
    for (int i = 1; i <= N; ++i)
        cin >> W[i];
    for (int i = 1; i <= N; ++i)
        cin >> V[i];
    for (int i = 1; i <= N; i++){
//        scanf("%d %d", &w, &v);
        w = W[i];
        v = V[i];
        for (int j = C; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + v);
    }
    printf("%lld", dp[C]);
}