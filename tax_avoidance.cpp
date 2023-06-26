#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");



int32_t main(){
    int32_t n, m; 
    cin >> n >> m; 

    vector<vector<long double>> dist(n, vector<long double> (n, 0)); 
    
    for(int i = 0; i < m; i++){
        int a, b; int c;
        cin >> a >> b >> c; 

        dist[a][b] = max(dist[a][b], (long double) (1000.0 - c) / 1000.0); 
    }

    array<long double, 3> ans = {0, 0, 0}; 
    ans[0] = 1;

    for(int k = 0; k < n; k++)
        for(int a = 0; a < n; a++)
            for(int b = 0; b < n; b++)
                dist[a][b] = max(dist[a][b], dist[a][k] * dist[k][b]);
            
        
    

    for(long double i = 0; i < n; i++){
        for(long double j = 0; j < n; j++){
            if(i == j) continue; 
            if(dist[i][j] < ans[0]){
                ans = {dist[i][j], i, j};
            }
        }
 
    }

    cout << ans[1] << " " << ans[2] << endl; 
}
