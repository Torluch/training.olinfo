#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt");

int solve(){
    int n, k ; fin >> n>> k; 
    
    vector<int> v(n); 
    for(int &i: v) fin >> i; 

    sort(v.begin(), v.end()); 

    vector<pair<int, int>> diff(n);
    vector<int> di(n); 
    for(int i = 1; i < n; i++){
        diff[i] = {v[i] - v[i - 1], i};
        di[i] = v[i] - v[i - 1];
    }


    sort(diff.rbegin(), diff.rend()); 
    for(int i = 0; i < k - 1; i++){
        int pos = diff[i].second;
        di[pos] = 0; 
    }

    long long sol = 0; 
    for(int i = 0; i < n; i++){
        sol += di[i]; 
    }

    return sol;
}

int main(){
    int t; fin >> t; 
    for(int i = 0; i < t; i++){
         
        fout << "Case #" << i + 1 << ": " <<solve()<< endl; 

    }
}