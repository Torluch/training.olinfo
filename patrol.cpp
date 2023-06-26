#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
#define int long long

int32_t main(){
    int n, m, p; fin >> n >> m >> p;

    vector<vector<int>> g(n); 
    for(int i = 0; i < m; i++){
        int a, b; fin >> a>> b; 

        g[a].push_back(b); 
        g[b].push_back(a); 
    }

    for(int i = 0; i < n; i++) g[i].push_back(i);
 
    vector<vector<int>> occupati(n + 3, vector<int> (421, 0));
    for(int i = 0; i < p; i++){
        int md; fin >> md; 

        vector<int> v(md); 
        for(int &j: v) fin >> j; 

        for(int j = 0; j <= 420; j++) occupati[v[j % md]][j] = 1; 
    }

    
    vector<vector<int>> vis(n + 1, vector<int> (421, 0)); 
    queue<array<int, 2>> pq;

    pq.push({0, 0}); 

    while(!pq.empty()){
        auto [node, dist] = pq.front(); pq.pop(); 
        
        if(node == n - 1){
            fout << dist; 
            return 0; 
        }

        if(vis[node][dist % 420]) continue; 
        vis[node][dist % 420] = 1; 

        int nt = (dist + 1); 
        for(auto v: g[node]) if(!occupati[v][nt % 420]) {
            pq.push({v, nt});
        }
    }

    fout << -1 << endl; 
}
