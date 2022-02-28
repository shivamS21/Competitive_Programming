#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string a, b; cin >> a >> b;
        int n = a.length();
        vector<string> arr;
        arr.push_back(a);
        for(int i = 0; i < n-1; i++){
            string st = arr.back();
            string temp = "";
            temp += st[n-1];
            for(int j = 0 ; j < n-1; j++)
            temp += st[j];
            arr.push_back(temp);
        }
        int ans = 0, found = 0;
        for(int i = 1; i < arr.size(); i++){
            ++ans;
            if(arr[i] == b){
                found = 1;
                break;
            }
        }
        if(found)cout<<ans;
        else cout<<"Foul";
        cout<<endl;
    }
}