#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void posiziona(int W, int T);

void budget(int B);
void irriga(int C, int N, vector<int>& X, vector<int>& P){
    priority_queue<array<int, 4>> pq;

    for(int i = 0; i < N; i++){
        pq.push({-X[i] + P[i], P[i], X[i], i});
    }

    long long ans = C + pq.top()[1]; 
    pair<int, int> last = {pq.top()[2], -pq.top()[1]};
    pq.pop();

    while(!pq.empty()){

        auto [x1, y1] = last; 
        auto [ordinata, y2, x2, j] = pq.top(); pq.pop();
        y2 = -y2; 
        long long y = (x1 - x2 + y1 + y2) / 2; 
        long long x = (x1 + x2 + y1 - y2) / 2;

        if(x2 <= x1) continue; 
        if(x <= x1) continue;

        int tmp = abs(y1 - y); 
        int tmp2 = C - y2;

        if(tmp2 < tmp){
            ans += tmp2; 
            posiziona(x1, -y1); 
            last = {x2, y2}; 
        } else {
            last = {x, y}; 
            ans += tmp; 
        }
    }

    posiziona(last.first, -last.second);
    budget(ans);
}
