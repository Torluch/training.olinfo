#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int MAX = 1e6 + 7e5; 

struct pt{
    struct Node{
        int sum = 0;
        int l = -1, r = -1; 

        void join(Node &l, Node &r){
            sum = l.sum + r.sum; 
        }
    };

    int count = -1; 
    Node v[MAX];
    int size = 1;

    vector<int> roots; 

    int newleaf(int val){
        v[++count].sum = val;
        return count; 
    }

    int newparent(int l, int r){
        v[++count].l = l; 
        v[count].r = r; 
        v[count].join(v[l], v[r]); 

        return count;
    }

    int copy(int version){
        v[++count] = v[version];
        return count; 
    }

    void init(int n){
        while(size < n) size *= 2;

        roots.push_back(build(0, size)); 
    }

    int build(int l, int r){
        if(l == r - 1){
            return newleaf(0); 
        }

        int mid = l + (r - l) / 2; 

        return newparent(build(l, mid), build(mid, r));   
    }

    int set(int u, int version, int l, int r, int x, int y, int val){
        if(l >= y || r <= x) return u;
        if(l >= x && r <= y){
            int nuovo = copy(u);
            v[nuovo].sum = val;
            return nuovo; 
        }
        int mid = l + (r - l) / 2; 
        return newparent(set(v[u].l, v[version].l, l, mid, x, y, val), set(v[u].r, v[version].r, mid, r, x, y, val));
    }

    int get(int u, int l, int r, int x, int y){
        if(l >= y || r <= x) return 0;
        if(l >= x && r <= y) return v[u].sum; 

        int mid = l + (r - l) / 2; 
        return get(v[u].l, l, mid, x, y) + get(v[u].r, mid, r, x, y); 
    }
};

pt pst; 


void init(int n){
    pst.init(n); 
}
void log(vector<int>& added, vector<int>& removed){
    int last = pst.roots.back();

    for(int i = 0; i < added.size(); i++){    
        last = pst.set(last, 0, 0, pst.size, added[i], added[i] + 1, 1); 
    }
    for(int i: removed){
        last = pst.set(last, 0, 0, pst.size, i, i + 1, 0);
    }

    pst.roots.push_back(last); 
}
int answer(int d, int x){
    return pst.get(pst.roots[d], 0, pst.size, x, pst.size);
}
