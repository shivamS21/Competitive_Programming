//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define M 1000000007
 
bool comp(ll x,ll y){
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k;
    cin >> n;
    vector<ll> arr(n);
    rep(i,0,n){
        cin >> arr[i];
    }
    int e = 0, o = 0;

    vector<int> even, odd;
    rep(i,0,n){
        if(arr[i]%2){
            o++;
            odd.pb(i);
        }
        else{
             e++;
             even.pb(i);
        }
    }

    if(abs(e-o) > 1){
        cout << -1 << endl;
        return;
    }
    int mn = 1e8;
    if (n%2==0){
        int ans1 = 0, ans2 = 0;
        for (int i=0;i<n;i+=2){
            ans1 += abs(i-even[i/2]);
        }
        int pos=0;
        for (int i=1;i<n;i+=2){
            ans2 += abs(i-even[pos]);
            pos++;
        }
        cout << min(ans1, ans2) << endl;
    }
    else{
        int ans1 = 0, ans2 = 0;
        if (e>o){
            for (int i=0;i<n;i+=2){
                ans1 += abs(i-even[i/2]);
            }
            mn = ans1;
        }
        else{
            for (int i=0;i<n;i+=2){
                ans2 += abs(i-odd[(i)/2]);
            }
            mn = ans2;
        }
        cout << mn << endl;
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 