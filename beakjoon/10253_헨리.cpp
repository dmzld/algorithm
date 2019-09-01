#include<stdio.h>
int gcd(int a, int b) { return b == 0? a : gcd(b, a%b); }
int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        int x;
        scanf("%d %d", &a, &b);
        while(a != 1) {
            x = (b%a==0) ? (b/a) : (b/a+1);
            a = a*x - b;
            b *= x;
            int g = gcd(a,b);
            a /= g;
            b /= g;
        }
        printf("%d\n",b);
    }
    return 0;
}
