#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given n apples initially, each day with k apples remaining you choose uniformly at random x in [1..k] to eat.
Question: Expected number of days to have eaten at least m apples (i.e., total eaten >= m), given 1 <= m <= n <= 20.

Interpretation: Let E[a] be expected additional days to eat at least m apples when already eaten a (0..m).
We stop once eaten >= m, so E[a]=0 for a>=m. Each day consumes between 1 and remaining apples (n-a), uniformly.
Thus for a < m: E[a] = 1 + (1/(n-a)) * sum_{x=1}^{n-a} E[min(m, a+x)]
We can compute via DP from a=m downwards.

Precision: Output rounded to two decimals. We'll compute in double and print fixed<<setprecision(2).
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m)) return 0;
    m = min(m, n);
    vector<double> E(m+1, 0.0);
    // E[m] = 0.
    for(int a=m-1; a>=0; --a){
        int rem = n - a;
        // sum over next states
        double s = 0.0;
        for(int x=1; x<=rem; ++x){
            int na = a + x;
            if(na >= m) s += 0.0; // E[m]=0
            else s += E[na];
        }
        E[a] = 1.0 + s / rem;
    }

    cout.setf(std::ios::fixed); cout << setprecision(2) << E[0] + 1e-9 << '\n';
    return 0;
}

