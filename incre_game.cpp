#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];
    sort(a, a+n);
    sort(b, b+m);
    int ans = 0;
    int r = 0;
    while(k > 0){
        ans += a[r]+b[r];
        int i = r+1;
        int j = i;
        --k;
        while(k > 0 && i < n && j < m){
            if(a[i]+b[r] <= b[j]+a[r]){
                ans += a[i]+b[r];
                ++i;
            } else if(a[i]+b[r] > b[j]+a[r]){
                ans += b[j]+a[r];
                ++j;
            }
            --k;
        }
        if(k > 0){
            if(i < n){
                while(k > 0 && i < n){
                    ans += a[i]+b[r];
                    ++i;
                    --k;
                }
            }else{
                while(k > 0 && j < m){
                    ans += b[j] + a[r];
                    ++j;
                    --k;
                }
            }
        }
        ++r;

    }
    cout << ans << endl;

}