
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int tt=1;
    cin >> tt;
    while(tt--){
        ll m,n,k;
        cin >> n;
        ll arr[n];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll cnt = 0, len = 1;

        for (ll i=0; i < n-1; ++i)
        {
            if (arr[i + 1] >= arr[i])
                len++;
            else
            {
                cnt += (((len - 1) * len) / 2);
                len = 1;
            }
        }

        if (len > 1)
            cnt += (((len - 1) * len) / 2);
        cout << cnt << endl;
    }
}
 
