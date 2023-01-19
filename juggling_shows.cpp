#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt"); 

int main(){
    int n; fin >> n; 
    vector<pair<int, int>> in(n); 

    for(auto &[i, j]: in) fin >> i >> j; 
    
    vector<vector<int>> v;
    
    vector<int> valori; 
    for(auto [i, j]: in){
        valori.push_back(i); 
        valori.push_back(j); 
    }
    
    sort(valori.begin(), valori.end()); 

    int count = 0; 
    map<int, int> rf; 
    
    rf[valori[0]] = count; 
    count++; 
    
    for(int i = 1; i < valori.size(); i++){
        if(valori[i] == valori[i - 1]) continue; 
        
        rf[valori[i]] = count; 
        count++; 
    }

    v.resize(count + 3); 
    
    for(auto &[i, j]: in){
        i = rf[i]; j = rf[j];
        v[i].push_back(j); 
    }



    int sol = 0; 
    for(int i = 0; i < count + 3; i++){

        queue<int> q; 
        int volte = v[i].size();
        while(volte--){

            q.push(i); 
            while(!q.empty()){
                auto current = q.front(); q.pop(); 
                if(v[current].size() == 0) continue;

                q.push(v[current].back()); 
                v[current].pop_back(); 
            }

            sol++; 
        }
    }

    fout << sol<< endl; 
}