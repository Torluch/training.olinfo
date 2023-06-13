#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
#define int long long

vector<long long> fib; 

long long solve(){
    int n, k; fin >> n >> k;  
    vector<int> guad(28, 0); 

    for(int i = 0; i < n; i++) {
        int a, b; 
        fin >> a >> b;
        
        if(a > 26) continue; 
        
        guad[a] = max(guad[a], b); 
    }

    vector<vector<int>> memo(28, vector<int> (k + 2, -1)); 
    
    function<long long (int, int)> f = [&](int ind, int rimasti) -> long long {
        if(rimasti <= 0) return 0;
        if(ind >= 27) return 0; 

        int &ans = memo[ind][rimasti]; 
        if(ans != -1) return ans; 

        int prendo = (fib[ind] != 0 && fib[ind] <= rimasti) ? guad[ind] + max(f(ind + 1, rimasti - fib[ind]), f(ind, rimasti - fib[ind])) : 0; 
        int non_prendo = f(ind + 1, rimasti); 

        return ans = max(prendo, non_prendo); 
    };

    return f(0, k); 
}

int32_t main(){
    int t; 
    fin >> t; 

    fib.resize(1e5 + 3, 1);
    for(int i = 2; i < 1e5 + 1; i++){
        fib[i] = fib[i - 1] + fib[i - 2]; 
    }

    while(t--){
        fout << solve() << endl;
    }
}