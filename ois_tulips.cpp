#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, b; cin >> n >> b; 

    vector<int> v(n); 
    for(int &i: v) cin >> i;
    
    int mn = 1e9; 
    vector<int> dp(n + 1); // dp con k = 1; 
    for(int i = n - 1; i >= 0; i--){
        mn = min(mn, v[i]);
        dp[i] = mn; 
    } 


    for(int k = 2; k <= b; k++){
        vector<int> newdp(n + 1); 
        stack<array<int, 3>> st;
         // valore, mx, indice

        for(int i = 0; i < k; i++) st.push({v[n - i], dp[n - i],  n - i}); 

        for(int i = n - k; i >= 0; i--){
            int ans = 0; 
            int val = v[i];
            int mx = dp[i]; // dp_mx nel blocco del mio numero

            while(!st.empty() && val < st.top()[0]){
                ans = max(v[i] + st.top()[1], ans);
                mx = max(mx, st.top()[1]); 
                st.pop();  
            }

            if(!st.empty()){
                ans = max(ans, newdp[st.top()[2]]);
                ans = max(ans, v[i] + dp[st.top()[2]]);
            }
                
            
            newdp[i] = ans;
            st.push({v[i], mx, i});  
        }



        dp = newdp; 
    }

    cout << dp[0]; 
}