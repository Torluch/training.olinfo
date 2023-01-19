#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt"); 

#define int long long

int32_t main(){
    int n, k; fin >> n >> k; 

    vector<int> v(n), fat(n), l(k); 
    
    for(int &i: v) fin >> i;
    //for(int &i: l) fin >> i; 
    for(int i = 0; i < n; i++) fat[i] = i; 

    function<int (int)> find = [&](int i) -> int {
        if(i == fat[i]) return i; 
        return fat[i] = find(fat[i]); 
    }; 

    vector<int> size(n, 1); 

    for(int &i : l){
        fin>> i; 
        for(int q = 0; q < n && q < i; q++){
            
            for(int j = q; j < n; j += i){
                int a = q, b = j;

                int c = find(a), d = find(b);
                if(c == d) continue; 

                if(size[c] > size[d]) swap(c, d); 

                size[c] += size[c];
                fat[c] = d; 
            }
        }
    }

    for(int i = 0; i < n; i++) fat[i] = find(i);

    //for(int i: fat) fout << i+1 << " "; fout << endl;  

    vector<vector<int>> valori(n); 

    for(int i = 0; i < n; i++){
        valori[fat[i]].push_back(v[i]); 
    }

    for(auto &i: valori){
        sort(i.rbegin(), i.rend()); 
    }


    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        ans[i] = valori[fat[i]].back();
        valori[fat[i]].pop_back(); 
    }

    for(int i: ans) fout << i << " "; 
    fout << endl; 
}