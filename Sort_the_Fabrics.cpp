#include<bits/stdc++.h>
using namespace std;
class fabric{
   public:
   string color;
   int d, u;
};
bool compAda(fabric &a, fabric &b){
    if(a.color != b.color)
        return a.color < b.color;
    return a.u < b.u;
}
bool compCharles(fabric &a, fabric &b){
    if(a.d != b.d)
        return a.d < b.d;
    return a.u < b.u;
}
int solve(){
    int n; cin >> n;
    vector<fabric> ada(n);
    for(int i = 0; i < n; i++){
        cin >> ada[i].color >> ada[i].d >> ada[i].u;
    }
    
    vector<fabric> charles = ada;
    
    sort(ada.begin(), ada.end(), compAda);
    sort(charles.begin(), charles.end(), compCharles);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(ada[i].color==charles[i].color
            and ada[i].d==charles[i].d
            and ada[i].u==charles[i].u)
            ++ans;
    }
    
    return ans;
}
int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #"<<i<<": "<<solve()<<endl;
    }
}