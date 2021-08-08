#include <bits/stdc++.h>

#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define int long long int

#define pb push_back
#define mpp make_pair
#define F first
#define S second
#define vec vector<int>
#define pr vector<pair<int, int>>
#define vecv vector<vec>
#define vecs vector<string>
#define vecc vector<char>

#define pi 3.141592653589793238
#define mod 1000000007
#define Mod 998244353
#define inf 1e16
#define precise(i) cout << fixed << setprecision(i);
#define endl "\n"
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define one cout << -1 << endl;

#define err1(a) cout << #a << " " << a << endl;
#define err2(a, b) cout << #a << " " << a << " " << #b << " " << b << endl;
#define err3(a, b, c) cout << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define show(a)             \
    for (auto xyz : a)      \
        cout << xyz << " "; \
    cout << endl;
#define show_nl(a)     \
    for (auto xyz : a) \
        cout << xyz << endl;
#define loop(a) for (auto xyz : a)
#define f(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = b; i >= a; i--)

const long double eps = 1e-8;

#define lb lower_bound //THIS GIVES THE ITR TO THE ELEMENT IN RANGE [SI,EI) THAT IS >= OUR VALUE
#define ub upper_bound //THIS GIVES THE ITR TO THE ELEMENT IN RANGE [SI,EI) THAT IS > OUR VALUE
using namespace std;

priority_queue<int,vector<int>, greater<int> > sz;
ll help(int arr[],int n){
    priority_queue<int,vector<int>, greater<int> > pq;
    int c=1;
    int i=0;
    int xt=0;
    for(i=0;i<n-1;i++){
        if(arr[i]<arr[i+1])c++;
        else{
            xt++;
            pq.push(c);
            c=1;
        }
    }
    pq.push(c);
    if(pq.size()==1){
        sz.push(pq.top());
        return;
    }
    //cout<<pq.size()<<" "<<xt<<endl;
    int f=0,sum=0;
    c=0;
    while(!pq.empty()){
        c++;
        sum+=pq.top();
        pq.pop();
        if(c%2==0){
            f+=sum;
            pq.push(sum),sum=0;
        }
    }
    sz.push(f+xt);
    //cout<<f+xt<<endl;
}
int sol(){
    int f=0,sum=0;
    int c=0;
    if(sz.size()==1){
        sz.pop();
        return sz.top();
    }
    //cout<<sz.size()<<" ";
    while(!sz.empty()){
        c++;
        sum+=sz.top();
        //cout<<sum<<" ";
        sz.pop();
        if(c%2==0){
            f+=sum;
            sz.push(sum),sum=0;
        }
    }
    int ans=f;
    while(!sz.empty()){
        sz.pop();
    }
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    int f[n];
    for(int i=0;i<n;i++){
        cin>>f[i];
        int arr[f[i]];
        f(j,0,f[i])cin>>arr[j];
        help(arr,f[i]);
    }
    int ans=sol();
    cout<<ans<<endl;
}

signed main()
{
    fastio;
    int t = 1;
    cin>>t;
    while (t--)
    {
        solve();
    }
}