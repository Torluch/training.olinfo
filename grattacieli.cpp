#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long costruisci(int n, int m, vector<long long>& h, vector<int>& a, vector<int>& b, vector<int>& c){
    vector<vector<pair<int, int>>> g(n);

    vector<long long> sol = h;

    for(int i = 0; i < m; i++){
        g[a[i]].push_back({b[i], c[i]}); 
    }

    priority_queue<pair<long long, int>> pq; 
     
    for(int i = 0; i < n; i++){
        pq.push({-h[i], i}); 
    }

    vector<int> vis(n, 0); 

    while(!pq.empty()){
        auto [altezza, current] = pq.top(); 
        pq.pop();

        if(vis[current] == 1) continue; 
        vis[current] = 1; 

        for(auto [nodo, delta]: g[current]){
            if(sol[current] + delta < sol[nodo]){
                sol[nodo] = delta + sol[current]; 
                pq.push({-sol[nodo], nodo}); 
            }
        }
    }


    long long ans = 0; 
    for(int i = 0; i < n; i++) ans += sol[i];

    return ans; 
}

int main() {
    // Input da file:
    // freopen("input.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);

    int n, m;
    fin >> n >> m;
    vector<long long> h(n);
    vector<int> a(m), b(m), c(m);

    for(size_t i = 0; i < n; i++) {
        fin >> h[i];
    }
    for(size_t j = 0; j < m; j++) {
        fin >> a[j] >> b[j] >> c[j];
    }
    fout << costruisci(n, m, h, a, b, c) << endl;
    return 0;
}

