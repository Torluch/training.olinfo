#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt"); 
#define int long long

const int mod = 1e9 + 7;

int32_t main(){
    int n, m; 
    fin >> n >> m; 

    vector<array<int, 3>> edges(m); 
    for(auto &[c, a, b]: edges){
        fin>> a >> b >> c; 
    }

    sort(edges.begin(), edges.end(), [&] (auto &a, auto &b){
        return a[0] > b[0]; 
    }); 

    int ans = 0;
    vector<unordered_map<int, int>> arrivo(n + 2); 
    
    for(auto [c, a, b]: edges){

        int tmpa = arrivo[b][c + 1]; 
        int tmpb = arrivo[a][c + 1]; 

        arrivo[a][c] += 1 + tmpa;
        arrivo[a][c] %= mod;
        
        arrivo[b][c] += 1 + tmpb;
        arrivo[b][c] %= mod; 

        ans += (tmpa + tmpb + 1) % mod;
        ans %= mod; 
    }

    fout << ans << endl; 
}