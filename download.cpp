#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt");

pair<int, int> solve(){
    int n, f, c; fin >> n >> f >> c; 

    int presif = n / f; 
    int restanti = n - presif * f; 
    int presic = restanti / c; 

    return {presif, presic}; 
}

int main(){
    int t; fin >> t; 
    for(int i = 0; i < t; i++){
        auto [nf, nc] = solve(); 
        fout << "Case #" << i + 1 << ": " << nf << " " << nc<< endl; 

    }
}