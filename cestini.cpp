#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt");

string solve(){
    int n, m, q; fin >> n >> m >> q; 
    vector<string> cest(m);
    
    fin >> cest[0]; 

    string sol = ""; 
    for(int i = 0; i < q; i++){
        char a; fin >> a; 
        int uno, due; fin >> uno >> due; 

        if(a == 's'){
            auto tomove = cest[uno].back(); 
            cest[due].push_back(tomove);
            cest[uno].pop_back();  
        }

        if(a == 'c'){
            sol += cest[uno][due]; 
        }
    }

    return sol; 
}

int main(){
    int t; fin >> t; 
    for(int i = 0; i < t; i++){ 
        fout << "Case #" << i + 1 << ": " << solve()<< endl; 
    }
}