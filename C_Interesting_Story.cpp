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
 
bool comp(ll a, ll b){
    return a > b;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k;
    cin >> n;
    vector<string> arr(n);
    rep(i,0,n) cin >> arr[i];
    int over = 0;
    for(char ch='a'; ch <= 'e'; ch++){
        vector<int> p;
        rep(i,0,n){
            m = arr[i].length();
            int count = 0;
            rep(j,0,m){
                if(arr[i][j] == ch) ++count;
            }
            p.pb(2*count - m);
        }
        // cout << ch << " ";
        // print(p)
        sortd(p);
        // cout << ch << " ";
        // print(p)
        int sum = 0, ans = 0;
        rep(i,0,n){
            if(sum + p[i] > 0){
                sum += p[i];
                ans += 1;
            }
        }
        over = max(over, ans);

    }
    cout << over << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
