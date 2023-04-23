#include <bits/stdc++.h>

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;
using namespace std;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int* S;
static int res;

int riassumi(int N, int M, int A[], int B[], int S[]){
    int n = N, m = M; 

    vector<pair<int, int>> edges; 
    for(int i = 0; i < m; i++){
        int a, b; 
        a = A[i]; b = B[i]; 
        edges.push_back({a, b}); 
    }

    int cnt = 0; 
    vector<bool> presi(n + 3, 0);
    int j = 0; 


    function<bool (int)> f = [&] (int i) -> bool {
        if(cnt > 10) return false;

        if(i == m) return true; 
        
        auto [a, b] = edges[i]; 
        if(presi[a] == 1 || presi[b] == 1) return f(i + 1);

        cnt++; 
        presi[a] = 1; 
        if(f(i + 1)){
            S[j] = a; j++;
            return true; 
        }
        presi[a] = 0;

        presi[b] = 1; 
        if(f(i + 1)){
            S[j] = b;j++;
            return true; 
        }

        cnt--;
        presi[b] = 0; 

        return false; 
    };

    f(0);

    return cnt;
}
