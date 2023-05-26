#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
#define int long long

int solve(){
    int n; fin >> n; 
    priority_queue<int> pq; 
    for(int i = 0; i < n; i++) {
        int a; fin >> a; 
        pq.push(-a); 
    }
    
    int non_ottenibile = 1; 
    for(int i = 0; i < n; i++){
        int prec = non_ottenibile - 1;
        if(-pq.top() > non_ottenibile) return non_ottenibile; 
        non_ottenibile = prec - pq.top() + 1;
        pq.pop();
    }

    return non_ottenibile; 
}

int32_t main(){
    int q; fin >> q;  
    while(q--){
        fout << solve() << endl; 
    }
}
