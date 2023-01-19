#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt"); 

pair<int, int> solve(){
    int n, a, b; fin >> n >> a >> b; 

    queue<int> q; 
    vector<vector<int>> g(n); 
    vector<int> dist(n, 1e9); 

    for(int i = 0; i < a; i++){
        int val; fin >> val; 
        q.push(val);
        dist[val] = 1; 
    } 

    for(int i = 0; i < b; i++){
        int c, d; 
        fin >> c >> d; 

        g[c].push_back(d); 
        g[d].push_back(c); 
    }

    while(!q.empty()){
        auto current = q.front(); q.pop(); 
        for(auto e: g[current]){
            if(dist[e] > dist[current] + 1){
                dist[e] = dist[current] + 1;
                q.push(e); 
            } 
        }
    }

    int sol, freq = 0; 
    for(int i = 0; i < n; i++){
        if(freq < dist[i]){
            sol = i; freq = dist[i]; 
        }
    }

    return {sol, freq}; 
}

int main(){
    int t; fin>> t; 
    for(int i = 1; i <= t; i++){
        auto [sol, freq] = solve(); 
        fout << "Case #" << i << ": " << sol << " " << freq<< endl; 
    }
}