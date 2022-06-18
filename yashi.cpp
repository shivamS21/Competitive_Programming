#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; string s; cin >> n >> s;
    string ans = "";
    stack<char> st;
    for(int i = 0; i < n-1; i++){
        if(st.empty()) 
        st.push(s[i]);
        else if(st.top() >= s[i]) st.push(s[i]);
        else{
            while(!st.empty() and st.top() < s[i]){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
}
