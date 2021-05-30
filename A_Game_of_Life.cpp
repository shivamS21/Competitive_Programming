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
    cin >> n >> m;
    string s;
    cin >> s;
    string ans(n,'0');
    if(s==ans){
        cout<<s<<endl;
        return;
    }
    ans = s;
    int c = 0;
    rep(i,0,n){
        if(s[i]=='0')
        ++c;
        else break;
    }
    // cout<<c<<endl;
    if(m>=c){
        rep(i,0,c)
        ans[i] = '1';
    }
    else{
        int a = m,i=c-1;
        while(a>0 and i>-1){
            ans[i] = '1';
            i -= 1;
            --a;
        }
    }
    int count = 0,a=-1;
    rep(i,c,n){
        if(ans[i]=='0'){
            ++count;
            if(a==-1)
            a = i;
        }
        else{
            if(!count)
            continue;
            else{
                // cout<<count;
                if(m>=count/2){
                    // cout<<a<<endl;
                    int b = count;
                    int j = a;
                    while(count>0){
                        ans[j] = '1';
                        --count;
                        ++j;
                    }
                    // cout<<ans<<endl;
                    if(b%2){
                        ans[a+b/2] = '0';
                    }
                    // cout<
                    a = -1;
                }
                else{
                    int b = a;
                    rep(j,0,m){
                        ans[a] = '1';
                        ++a;
                    }
                    int j = b + count-1;
                    int k = m;
                    while(k > 0){
                        ans[j] = '1';
                        j -= 1;
                        k -= 1;
                    }
                    a = -1;
                }
                count = 0;
            }
        }   
    }
    if(count>0){
        if(m>=count){
            int j = a;
            while(count>0){
                ans[j] = '1';
                --count;
                j+=1;
            }
        }
        else{
            int j = a;
            while(m>0){
                ans[j] = '1';
                j += 1;
                m -= 1;
            }
        }
    }
    cout<<ans<<endl;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 