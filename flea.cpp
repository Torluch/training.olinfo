#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt"); 
#define int long long

int32_t main(){
    int n; fin >> n;
    
    int sol = 0; 
    for(int i = 0; i < n; i++){
        char a; fin >> a; 
        if(a == 'R') sol++; 
        if(a == 'L') sol--; 
    }
    
    fout << abs(sol) << endl; 
}