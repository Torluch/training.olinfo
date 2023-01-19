#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt");
#define int long long

int gcd(int a, int b){ // b minore
    if(b == 0){
        return a; 
    }

    return gcd(b, a % b); 
}

int solve(){
    int n;
    fin >> n; 

    int uno; fin >> uno; 
    int mcm = uno; 
    int mcd = uno; 
    
    for(int i = 1; i < n; i++){
        int val; fin >> val; 

        long long prod = mcm * val; 
        long long gcd1 = gcd(mcm, val); 
        mcm = prod / gcd1;  
    }

    return mcm; 
}

int32_t main(){
    int t; fin >> t; 
    for(int i = 0; i < t; i++){ 
        fout << "Case #" << i + 1 << ": " << solve()<< endl; 
    }
}