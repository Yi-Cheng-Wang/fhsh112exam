#include <algorithm>
#include <iostream>
using namespace std;

struct node{int P, R;} N[1000001], M[1000001];
bool cmp(node a, node b){
    return a.P < b.P;
}

int n, m;
long long dp[2][10001] = {};
int f_ = 0, t_ = 1;

int bs(int x, int tp){
    if(x <= M[0].P) return 0;

    int l=0, r=m, mid;
    while(r-l>1){
        mid = (r+l)/2;
        if(M[mid].P > x) r = mid;
        else if(M[mid].P < x) l = mid;
        else return mid;
    }
    if(tp) return r;
    return l;
}

int swPL, swPR, swCnt;

int swA(int l, int r){
    swPL = bs(l,1), swPR = swPL;
    swCnt = 0;
    while(M[swPR].P<=r){
        swCnt += M[swPR].R;
        swPR++;
    }
    swPR--;
    return swCnt;
}
int swB(int l, int r){
    while(M[swPL].P<l){
        swCnt -= M[swPL].R;
        swPL++;
    }
    while(swPL>0 && M[swPL-1].P>=l){
        swPL--;
        swCnt += M[swPL].R;
    }
    while(M[swPR].P>r){
        swCnt -= M[swPR].R;
        swPR--;
    }
    while(swPR<m && M[swPR+1].P<=r){
        swPR++;
        swCnt += M[swPR].R;
    }
    return swCnt;
}

int main() {
    scanf("%d %d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++) scanf(" %d %d", &N[i].P, &N[i].R);
    for (i = 0; i < m; i++) scanf(" %d %d", &M[i].P, &M[i].R);
    sort(N, N+n, cmp);
    sort(M, M+m, cmp);
    N[n] = (node){2000000000, 0};
    M[m] = (node){2000000000, 0};

    int pl=0, pr, rl, rr, l, r, d, al, ar, first_r=0, last_r=0;
    for (i = 0; i < n; i++) {
        pr=N[i+1].P-1;
        rl=N[i].P-N[i].R, rr=N[i].P+N[i].R;
        l = max(first_r+1, rl), r = min(pr, rr);
        dp[t_][0] = 0;

        swA(l, N[i].P);
        first_r = 2000000000;
        for(al=l, ar=N[i].P; al<=N[i].P && ar<r; al++){
            if((N[i].P-al)*3 < N[i].R){
                d = al-N[i].P; //負的
                ar = N[i].P+N[i].R+d*2;
            }
            else{
                d = (N[i].R-N[i].P+al)/2;
                ar = N[i].P+d;
            }
            if(ar>r) ar=r;
            first_r = min(first_r, ar);
            int x = ar-N[i].P;
            dp[t_][x] = max(dp[f_][min(al, last_r+1)-pl] + swB(al, ar), dp[t_][x]);
            dp[t_][x+1] = dp[t_][x];
            dp[t_][x+2] = dp[t_][x];

        }

        pl=N[i].P+1;
        f_ = 1-f_;
        t_ = 1-t_;
        last_r = r;
    }

    printf("%lld", dp[f_][last_r+1-pl]);
    return 0;
}
