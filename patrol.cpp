#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt"); 

int main(){
    int n, m; fin >> n >> m; 
    int k; fin >> k; 

    vector<vector<int>> g(n); 
    for(int i = 0; i < m; i++){
        int a, b; fin >> a >> b; 
        g[a].push_back(b); 
        g[b].push_back(a); 
    }

    vector<vector<bool>> free(n, vector<bool> (420, 1)); 
    for(int i = 0; i < k; i++){
        int l; fin >> l; 

        for(int j = 0; j < l; j++){
            int a; fin >> a; 

            for(int q = j; q < 420; q += l){
                free[a][q] = 0; 
            }
        }
    }

    priority_queue<array<long long, 2>> pq; 
    pq.push({0, 0}); 
    vector<int> vis(n, 0); 


    while(!pq.empty()){
        auto [dist, current] = pq.top(); 
        pq.pop();
        dist = -dist;

        if(current == n - 1){
            fout << dist << endl; 
            return 0; 
        }

        if(vis[current] == 1) continue; 
        vis[current] = 1; 
        
        //fout << current << " "<< dist <<  endl; 

        int nuovadist = (dist + 1) % 420; 
        for(auto e: g[current]){
            if(!free[e][nuovadist]){
                for(int i = 2; i <= 420; i++){
                    if(nuovadist == (dist + i) % 420) continue;
                    if((dist + i) % 420 == dist % 420) continue; 

                    int nuovo = (dist + i) % 420; 
                    if(free[e][nuovo]){
                        pq.push({-dist - i, e});
                        break; 
                    }
                }
                continue; 
            }

            pq.push({-dist - 1, e}); 
        }
    }

    fout << -1; 
}