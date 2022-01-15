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
    stack<ll> st;
    ll arr[n+1]={0};
    for(ll i = 0; i < n; i++){
        ll a; cin >> a;
        arr[a]+=1;
    }
    ll steps = 0;
    //steps is basically the no of steps required to make upto i-1;
    ll ok = 1;
    for(ll i = 0; i <=n; i++){
        if(!arr[i]){
            //no presence of i in the array.
            if(!ok) cout << -1 << " ";
            else{
                cout << steps << " ";
                if(!st.empty()){
                    steps += i - st.top();
                    st.pop();
                }
                else ok = 0;
            }
        } else{
            if(!ok) cout<<-1 << " ";
            else{
                cout<<steps+arr[i] << " ";
                for(ll k = 1; k < arr[i]; k++) st.push(i);
            }
        }
    }
    cout << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 