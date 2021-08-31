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
    stack<ll> a, b;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i%2==0)
        a.push(arr[i]);
        else{
            ll temp = arr[i];
            while(!a.empty() && temp > 0){
                if(a.top() < temp){
                    ans += a.top();
                    temp -= a.top();
                    a.pop();
                    if(!b.empty()){
                        ans += ((b.top()+1)*(b.top()))/2;
                        b.pop();
                    }
                } else if(a.top() == temp){
                    ans += temp;
                    temp = 0;
                    a.pop();
                    if(!b.empty())
                    b.top()++;
                    else b.push(1);
                } else{
                    a.top() -= temp;
                    ans += temp;
                    b.push(1);
                    temp = 0;
                }
            }
        }
    }
    while(!b.empty()){
        ans += ((b.top()-1)*(b.top()))/2;
        b.pop();
    }
    cout << ans <<  endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 