#include <iostream>
using namespace std;

int main() {
    int n, m, H=-2147483647, h=2147483647;
    scanf("%d %d", &n, &m);
    int i, a;
    for(i=0; i<n; i++){
        scanf("%d", &a);
        H = max(a, H);
        h = min(a, h);
    }
    int cnt=0;
    for(i=0; i<m; i++){
        scanf("%d", &a);
        if(h<=a && a<=H) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
