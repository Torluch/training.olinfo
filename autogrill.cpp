#include <bits/stdc++.h> 
using namespace std; 
ifstream fin("input.txt"); 
ofstream fout("output.txt"); 

set<long long> s; 

void apri(long long p){
    s.insert(p); 
}

void chiudi(long long p){
    auto it = s.find(p); 
    s.erase(it); 
}

long long chiedi(long long p){
    if(p < *s.begin()) return *s.begin(); 
    
    if(s.size() == 0) return -1; 

    auto it = s.lower_bound(p);
    
    if(it == s.end()) return *prev(it); 
    
    auto it2 = *prev(it);
    
    if(abs(p - *it) <= abs(p - it2)){
        return *it; 
    }

    return it2; 

}

void inizia(){}


int main() {
    int Q;
    fin >> Q;

    inizia();

    for (int i = 0; i < Q; i++){
        long long p;
        char t;
        fin >> t >> p;
        if (t == 'a') apri(p);
        else if (t == 'c') chiudi(p);
        else{

            fout << chiedi(p) << endl;
            //for(auto i: s) fout << i << " "; 
            //fout << endl; 
        }
    }

    return 0;
}
