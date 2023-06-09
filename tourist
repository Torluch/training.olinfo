#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
#define int long long

int32_t GreatestHappiness(int32_t n, int32_t k, int32_t *h) {

    vector<pair<int, int>> v; 
    for(int i = 0; i < n; i++) v.push_back({h[i], i}); 
    sort(v.rbegin(), v.rend());

    deque<pair<int, int>> valori; 
    for(auto i: v) valori.push_back(i);


    unordered_map<int, int> presi; 
    
    int num_presi = 0; 
    int ans = 0; 
    int sum_tmp = 0; 
    for(int i = n - 1; i >= 0; i--){
        int da_prendere = k - i - num_presi; 
        if(da_prendere <= 0) continue;

        if(i != n - 1){
            // togli valore se era già stato preso; 
            int nuovo = h[i + 1]; 
            if(presi[nuovo]){
                presi[nuovo]--;
                sum_tmp -= nuovo;
                da_prendere++;
                num_presi--; 
            } 
        }

        //cout << i << " " << da_prendere << endl; 


        while(!valori.empty() && da_prendere > 0){
            auto [peso, indice] = valori.front(); 
            valori.pop_front(); 

            if(indice > i) continue; 

            presi[peso]++; 
            sum_tmp += peso;
            da_prendere--;
            num_presi++; 
        }

        //cout << i << " " << sum_tmp << endl; 

        ans = max(sum_tmp, ans);
    }

    return ans; 
}
