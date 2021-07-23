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
    vector<int> arr(n+1), check(n+1, -1);
    if(n==2 or n == 3 or n==6){
        cout << -1; return;
    }
    int a = 1, b = n;
    while(a < b){
        int first = a, last = b-1;
        // cout << first << " " << last << endl;
        if(a == b-1 or a == b-2){
            check[b--] = last++;
            check[a++] = last;
            continue;
        } 
        check[b--] = last++;
        check[b--] = first++;
        check[a++] = first;
        check[a++] = last;
    }

    if(n%2 and n%4==1) check[n/2+1] = n/2+1;
    if(n%2 and n%4==3) check[n/2+1] = n/2;
    rep(i,1,n+1) cout << check[i] << " ";
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 