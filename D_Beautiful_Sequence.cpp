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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if((!a and !b and !c) or (!a and !b and !d) or (!a and !c and !d) or (!b and !c and !d)){
        if(a==1){
            cout<<"YES \n0"<<endl;
        }
        else if(b==1){
            cout<<"YES \n1"<<endl;
        }
        else if(c==1){
            cout<<"YES \n2"<<endl;
        }
        else if(d==1){
            cout<<"YES \n3"<<endl;
        } 
        else
        cout<<"NO";
        return;
    }
    if(!a and !b){
        if(c==d){
            cout<<"YES"<<endl;
            rep(i,0,c){
                cout<<"2 3 ";
            }
        }
        else if(c==d+1 or c+1==d){
            cout<<"YES"<<endl;
            if(c+1==d)
            cout<<"3 ";
            rep(i,0,min(c,d)){
                cout<<"2 3 ";
            }
            if(c==d+1)
            cout<<2;
        }
        else{
            cout<<"NO";
        }
        return;
    }
    else if(!a and !d){
        if(b==c){
            cout<<"YES"<<endl;
            rep(i,0,c){
                cout<<"1 2 ";
            }
        }
        else if(b==c+1 or b+1==c){
            cout<<"YES"<<endl;
            if(b+1==c)
            cout<<"2 ";
            rep(i,0,min(b,c)){
                cout<<"1 2 ";
            }
            if(b==c+1)
            cout<<1;
        }
        else{
            cout<<"NO";
        }        
        return;
    }
    else if(!c and !d){
        
        if(a==b){
            cout<<"YES"<<endl;
            rep(i,0,b){
                cout<<"0 1 ";
            }
        }
        else if(a==b+1 or a+1==b){
            cout<<"YES"<<endl;
            if(a+1==b)
            cout<<"1 ";
            rep(i,0,min(a,b)){
                cout<<"0 1 ";
            }
            if(a==b+1)
            cout<<0;
        }
        else
        cout<<"NO";
        return;
    }
    vector<int>ans;
    if(a==b){
        rep(i,0,a){
            ans.pb(0);
            ans.pb(1);
        }
        if(c==d+1 or c==d){
            rep(i,0,d){
                ans.pb(2);
                ans.pb(3);
            }
            if(c==d+1)
            ans.pb(2);
        }
        else{
            cout<<"NO";
            return;
        }
    }
    else if(a==b+1){
        rep(i,0,a){
            ans.pb(0);
            ans.pb(1);
        }
        ans.pb(0);
        if(c>0 or d>0){
            cout<<"NO";
            return;
        }
    }
    else if(a+1==b){
        rep(i,0,a){
            ans.pb(1);
            ans.pb(0);
        }
        ans.pb(1);
        if(c==d+1 or c==d){
            rep(i,0,d){
                ans.pb(2);
                ans.pb(3);
            }
            if(c==d+1)
            ans.pb(2);
            cout<<"YES"<<endl;
            print(ans);
            return;
        }
        ans.clear();
        rep(i,0,a){
            ans.pb(0);
            ans.pb(1);
        }
        b = b - a;
        if(c>=b){
            rep(i,0,b){
                ans.pb(2);
                ans.pb(1);
            }
            c -= b;
            if(c==d or c==d+1){
                rep(i,0,d){
                    ans.pb(2);
                    ans.pb(3);
                }
                if(c==d+1)
                ans.pb(2);
                cout<<"YES"<<endl;
                print(ans);
                return;
            }
        }
        cout<<"NO"<<endl;
        return;
    }
    else if(b>a){
        rep(i,0,a){
            ans.pb(0);
            ans.pb(1);
        }
        if(c >= b-a){
            rep(i,0,b-a){
                ans.pb(2);
                ans.pb(1);
            }
            if(c-b+a == d){
                rep(i,0,d){
                    ans.pb(2);
                    ans.pb(3);
                }
                cout<<"YES"<<endl;
                print(ans);
                return;
            }
            else if(c-b+a == d+1){
                rep(i,0,d){
                    ans.pb(2);
                    ans.pb(3);
                }
                ans.pb(2);
                cout<<"YES"<<endl;
                print(ans);
                return;
            }
        }ans.clear();
        ans.pb(1);
        rep(i,0,a){
            ans.pb(0);
            ans.pb(1);
        }
        b = b-a-1;
        if(c>=b){
            rep(i,0,b){
                ans.pb(2);
                ans.pb(1);
            }
        }
        if(c-b == d){
            rep(i,0,d){
                ans.pb(2);
                ans.pb(3);
            }
            cout<<"YES"<<endl;
            print(ans);
            return;
        }
        else if(c-b == d+1){
            rep(i,0,d){
                ans.pb(2);
                ans.pb(3);
            }
            ans.pb(2);
            cout<<"YES"<<endl;
            print(ans);
            return;
        }
        cout<<"NO";
        return;
    }
    else{
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl;
    print(ans);
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 