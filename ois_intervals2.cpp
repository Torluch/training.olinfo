#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

#define int long long 

struct st{
    struct Node{
        int sum = 0; 
        void join(const Node &l, const Node &r){
            sum = l.sum + r.sum; 
        }
    };

    vector<Node> v; 
    int size = 1; 

    void init(int n){
        while(size < n) size *= 2; 

        v.resize(2*size, Node());      
    }

    void add(int pos, int val){
        int u = pos + size;
        v[u].sum += val; 

        while(u > 1){
            u /= 2; 
            v[u].join(v[2*u], v[2*u + 1]); 
        }
    }

    int get(int u, int l, int r, int x, int y){
        if(l >= y || r <= x) return 0; 
        if(l >= x && r <= y) return v[u].sum; 

        int mid = l + (r - l) / 2; 
        return get(2*u, l, mid, x, y) + get(2*u + 1, mid, r, x, y); 
    }

    int query(int l, int r){
        return get(1, 0, size, l, r + 1); 
    }
}; 

void solve(){

    int n; cin >> n; 
    vector<int> v(n + 1); 
    for(int i = 1; i <= n; i++) cin >> v[i];  

    int q; cin >> q; 
    vector<array<int, 3>> qq(q); 
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r; 
        qq[i] = {l, r, i}; 
    }

    sort(qq.rbegin(), qq.rend()); 

    st st; 
    st.init(n + 2); 

    function<void (int)> update = [&](int l) -> void {
        for(int i = l; i <= n; i++){
            if(v[i] % (i - l + 1) == 0){
                st.add(i, 1);             
            } else break; 
        }
    };

    vector<int> ans(q); 
    int cl = n + 1; 
    for(auto [l, r, i]: qq){
        while(cl != l){
            cl--; 
            update(cl); 
        }
        ans[i] = st.query(l, r); 
    }

    for(int i: ans) cout << i << "\n"; 

}

int32_t main(){
    int t; cin >> t; 
    while(t--){
        solve(); 
    }
}