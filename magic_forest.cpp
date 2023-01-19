#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt"); 
#define int long long

static constexpr unsigned int mod = 1e9 + 7;
vector<unordered_map<int, int>> memo;
vector<vector<pair<int, int>>> g;  

int f(int node, int fat, int valore) { // valore è superfluo per dp, serve per semplificare coding
    int sol = 1;
    //fout << "   " << node +1  << " " << fat + 1 << " " << valore << endl; 
    
    if(memo[node].count(fat)){
        return memo[node][fat];
    } 

    int found = 0; 
    for(auto [v, p]: g[node]) if(p == valore + 1){

        sol = (sol + f(v, node, p));
        found = 1; 
    }

    return memo[node][fat] = sol;
}



int32_t main(){
    int n, m; fin >> n >> m; 
    memo.resize(n); 
    g.resize(n); 
    
    vector<array<int, 3>> edges; 
    for(int i = 0; i < m; i++){
        int a, b, c; fin >> a>> b >> c; 
        a--; b--;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
        edges.push_back({c, a, b});   
    }

    sort(edges.rbegin(), edges.rend()); 

    
    int ans = 0; 
    
    for(int i = 0; i < m; i++){
        auto [c, a, b] = edges[i]; 
        ans = (ans + f(a, b, c));
        ans = (ans + f(b, a, c)); 
    }


    fout << (ans % mod - m % mod) % mod<< endl; 
}