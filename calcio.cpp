#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt");
#define int long long

long long solve(){
    long long n, m; fin >> n>> m;
    long long k; fin >> k;

    long long v, o; fin>> v >> o;  
    
    vector<vector<long long>> prefix(n, vector<long long> (m, 0)); 
    for(long long i = 0; i < k; i++){
        long long a, b; fin >> a >> b; 
        prefix[a][b]++; 
    }


    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            long long pref1 = (i - 1 >= 0) ? prefix[i - 1][j]: 0; 
            long long pref2 = (j - 1 >= 0) ? prefix[i][j - 1]: 0;
            long long pref3 = (j - 1 >= 0 && i - 1 >= 0) ? prefix[i - 1][j - 1]: 0; 

            prefix[i][j] += pref1 + pref2 - pref3; 
        }
    }



    long long sol = k;

    v--; o--; 
    for(long long i = v; i < n; i++){
        for(long long j = o; j < m; j++){
            long long pref1 = (i - v - 1 >= 0) ? prefix[i - v - 1][j] : 0; 
            long long pref2 = (j - o - 1 >= 0) ? prefix[i][j - o - 1] : 0; 

            long long pref3 = (j - o -1 >= 0 && i - v - 1 >= 0) ? prefix[i - v - 1][j - o - 1] : 0;

            long long tmp = prefix[i][j] - pref1 - pref2 + pref3;
            sol = min(sol, tmp); 
        }
    }

    return sol; 
}

int32_t main(){
    int t; fin >> t; 
    for(int i = 0; i < t; i++){
        long long sol = solve(); 
        fout << "Case #" << i + 1 << ": " <<sol<< endl; 
    }
}