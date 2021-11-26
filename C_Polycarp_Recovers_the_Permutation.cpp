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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(arr[0] == n or arr[n-1] == n){
        deque<int> d;
        d.push_back(n);
        int a = 0, b = n-1;
        if(arr[0] == n) ++a;
        else --b;
        while(a < b){
            if(arr[a] < arr[b])
            d.push_front(arr[a]), a++;
            else d.push_back(arr[b]), b--;
        }
        if(a==b)
        d.push_front(arr[a]);
        while(!d.empty()){
            cout << d.front() << " ";
            d.pop_front();
        }
        cout << endl;
    } else cout << -1 << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 