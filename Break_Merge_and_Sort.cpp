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
    ll n;
    cin>>n;
    ll br = 0;
    vector<ll>s;

    for (int i=0;i<n;i++)
    {
        ll a;
        cin>>a;

        ll arr[a];
        for (int j=0;j<a;j++)
        {
            cin>>arr[j];
        }
        ll cnt=1;
        ll cur_size = a;
        ll maxa = 0;
        for (int j=0;j<a-1;j++)
        {
            if (arr[j+1]>arr[j])
            cnt++;
            else
            {
                s.push_back(cnt);
                //br += min(cnt,cur_size-cnt);
                cur_size -= cnt;
                maxa = max(maxa,cnt);
                cnt = 1;
            }
        }

        if (cnt>0)
        {
            s.push_back(cnt);
            maxa = max(maxa,cnt);
        }

        br +=  a-maxa;

    }
    // print(s);
    multiset<ll> ss;
    ll ans = 0, temp = 0;
    ll x = s.size();
    rep(i,0,x){
        ss.insert(s[i]);
    }
    while(ss.size() > 1){
        ll p = *ss.begin();
        ss.erase(ss.begin());
        ll q = *ss.begin();
        ss.erase(ss.begin());
        ss.insert(p+q);
        ans += p+q;
    }
    cout << ans + br << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 