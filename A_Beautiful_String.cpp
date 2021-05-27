//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ppb pop_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define mem(v,a) 		 memset(v, a, sizeof(v))
#define M 1000000007
bool comp(ll x,ll y)
{
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
bool check(string s, int n){
    rep(i,0,n-1){
        if(s[i]==s[i+1] and s[i]!='?')
        return false;
    }
    return true;
}
void solve(){
    string s; cin >> s;
    int n; n = s.length();
    int c = check(s, n);
    if(!c){
        cout<<"-1"<<endl;
        return;
    }
    vector<pair<int,char> > v;
    rep(i,0,n){
        if(s[i] != '?')
        v.pb(mk(i,s[i]));
    }
    // cout<<v.size();
    // rep(i,0,v.size()){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    string ans = "";
    int l = v.size();
    rep(i,0,l-1){
        if(v[i].first == v[i+1].first-1)
        ans += v[i].second;
        else{
            ans += v[i].second;
            if(v[i].second == 'a' and v[i+1].second == 'a'){
                int f = 0;
                for(int j = v[i].first+1; j < v[i+1].first; j+=1){
                    if(!f)
                    ans += 'b';
                    else ans += 'c';
                    f =  1-f;
                }
            }
            else if(v[i].second == 'b' and v[i+1].second == 'b'){
                int f = 0;
                for(int j = v[i].first+1; j < v[i+1].first; j+=1){
                    if(!f)
                    ans += 'a';
                    else ans += 'c';
                    f =  1-f;
                }
            }
            else if(v[i].second == 'c' and v[i+1].second == 'c'){
                int f = 0;
                for(int j = v[i].first+1; j < v[i+1].first; j+=1){
                    if(!f)
                    ans += 'b';
                    else ans += 'a';
                    f =  1-f;
                }
            }
            else if(v[i].second == 'a' and v[i+1].second == 'b'){
                int f = 0;
                for(int j = v[i].first+1; j < v[i+1].first; j+=1){
                    if(!f)
                    ans += 'c';
                    else ans += 'a';
                    f =  1-f;
                }
            }
            else if(v[i].second == 'b' and v[i+1].second == 'a'){
                int f = 0;
                for(int j = v[i].first+1; j < v[i+1].first; j+=1){
                    if(!f)
                    ans += 'c';
                    else ans += 'b';
                    f =  1-f;
                }
            }
            else if(v[i].second == 'a' and v[i+1].second == 'c'){
                int f = 0;
                for(int j = v[i].first+1; j < v[i+1].first; j+=1){
                    if(!f)
                    ans += 'b';
                    else ans += 'a';
                    f =  1-f;
                }
            }
            else if(v[i].second == 'c' and v[i+1].second == 'a'){
                int f = 0;
                for(int j = v[i].first+1; j < v[i+1].first; j+=1){
                    if(!f)
                    ans += 'b';
                    else ans += 'c';
                    f =  1-f;
                }
            }
            else if(v[i].second == 'b' and v[i+1].second == 'c'){
                int f = 0;
                for(int j = v[i].first+1; j < v[i+1].first; j+=1){
                    if(!f)
                    ans += 'a';
                    else ans += 'b';
                    f =  1-f;
                }
            }
            else if(v[i].second == 'c' and v[i+1].second == 'b'){
                int f = 0;
                for(int j = v[i].first+1; j < v[i+1].first; j+=1){
                    if(!f)
                    ans += 'a';
                    else ans += 'c';
                    f =  1-f;
                }
            }
        }
    }
    if(v.size()>0)
    ans += v.back().second;
    int i = n-1;
    while(i>=0 and s[i] == '?'){
        i -= 1;
    }
    if(i==-1){
        int f = 0;
        rep(i,0,n){
            if(!f)
            ans += 'a';
            else ans += 'b';
            f = 1-f;
        }
    }
    else{
        if(s[i]=='a'){
            int j = i+1;
            int f = 0;
            while(j < n){
                if(!f)
                ans += 'b';
                else ans += 'a';
                f = 1-f;
                ++j;
            }
        }
        else if(s[i]=='b'){
            int j = i+1;
            int f = 0;
            while(j < n){
                if(!f)
                ans += 'a';
                else ans += 'b';
                f = 1-f;
                ++j;
            }
        }
        else if(s[i]=='c'){
            int j = i+1;
            int f = 0;
            while(j < n){
                if(!f)
                ans += 'b';
                else ans += 'a';
                f = 1-f;
                ++j;
            }
        }
    }
    if(v.size() != 0 and v[0].first != 0){
        int c = v[0].first;
        if(v[0].second == 'a'){
            int j = 0, f = 0;
            while(j < c){
                if(!f) ans = 'b' + ans;
                else ans = 'c'+ans;
                f = 1 - f;
                j += 1;
            }
        }
        else if(v[0].second == 'b'){
            int j = 0, f = 0;
            while(j < c){
                if(!f) ans = 'a' + ans;
                else ans = 'c'+ans;
                f = 1 - f;
                j += 1;
            }
        }
        else if(v[0].second == 'c'){
            int j = 0, f = 0;
            while(j < c){
                if(!f) ans = 'a' + ans;
                else ans = 'b'+ans;
                f = 1 - f;
                j += 1;
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
 
 
 
 
// g++ -std=c++17