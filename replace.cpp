// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n; cin >> n;
//     string a, b; cin >> a >> b;
//     int ans = 0;
//     for(int i = 0; i < n; i++){
//         if(a[i] < b[i]){
//             cout << -1 << endl;
//             return 0;
//         }
//     }
//     for(char c = 'z'; c >= 'a'; c--){
//         vector<int> v;
//         set<int>s;
//         bool flag  = false;
//         for(int i = 0; i < n; i++){
//             if(b[i] == c){
//                 s.insert(a[i]);
//                 v.push_back(i);
//             }
//             if(a[i] == c)
//             flag = true;    
//         }
//         if(s.size()==0) continue;
//         if(s.size()==1){
//             if(*s.begin() == c) continue;
//             else{
//                 if(flag){
//                     for(int ele: v){
//                         a[ele] = c;
//                     }
//                     continue;
//                 }
//                 cout << -1 << endl;
//                 return 0;
//             }
//         } else{
//             if(*s.begin() == c){
//                 ++ans;
//                 for(int index: v){
//                     a[index] = c;
//                 }
//             }
//             else{
//                 if(flag){
//                     for(int ele: v){
//                         a[ele] = c;
//                     }
//                     continue;
//                 }
//                 cout << -1 << endl;
//                 return 0;
//             }
//         }
//     }
//     cout << ans << endl;
// }
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    map<int,int> mp;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[a] = i;
    }
    for(int i = 0; i < n; i++){
        ans += abs(mp[i]-i);
    }
    cout << ans << endl;
}