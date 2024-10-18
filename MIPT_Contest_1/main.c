#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;

// 1 task
ull gcd(ull x,ull y) {
  ull q = -1;
  x = abs(x); y  = abs(y);
  while(q != 0){
    if(y > x){
        ull tmp = x;
        x = y;
        y = tmp;
    }
    assert (y > 0);
    q = x % y;
    if(q == 0) return y;
    x = y;
    y = q;
  }
  return q;
}

// 2 task
void second(ull x, ull y){
    if (y == 0) {
        return;
    }
    ull divide = x / y;
    printf("%llu ", divide);
    second(y, x % y);
}

// 3 task
ll third(ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = 0; *y = 1;
        return b;
    }
    ll x1, y1;
    ll d = third(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return d;
}

void convert_to_base(unsigned int x, unsigned int y) {
    char result[32];
    int index = 0;

    while (x > 0) {
        result[index++] = '0' + (x % y);
        x /= y;
    }

    for (int i = index - 1; i >= 0; i--) {
        putchar(result[i]);
    }
    putchar('\n');
}

int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}

void convert_to_factorial_base(int number){
    int i = 1, coeff;
    int result[20];
    while (number > 0) {
        coeff = number % i;
        result[i - 1] = coeff;
        number /= i;
        printf("%d %d\n",coeff,number);
        i++;
    }
    for (int j = i - 2; j > 0; j--) {
        printf("%d.", result[j]);
    }
    printf("\n");
}

int main() {
  // 1 task
  /*unsigned long long x = 0, y = 0, g;
  int res;

  res = scanf("%llu %llu", &x, &y);
  assert(res == 2);
  g = gcd(x, y);
  printf("%llu\n", g);
  return 0;*/

  // 2 task
  /*ull x=0,y=0, res;
  res = scanf("%llu %llu", &x, &y);
  assert(res == 2);
  second(x,y);*/

  // 3 task
    /*ll a=0,b=0, res=0, greatest = 0, x, y;
    res = scanf("%lld %lld", &a, &b);
    assert(res == 2);
    ll g = third(a, b, &x, &y);
    if (g < 0) {
        g = -g;
        x = -x;
        y = -y;
    }
    printf("%lld %lld %lld",x,y,g);*/

    // 4 task
    /*ll a=0,b=0,c=0 ,res=0, x, y;
    res = scanf("%lld %lld %lld", &a, &b, &c);
    assert(res == 3);
    ll g = third(abs(a), abs(b), &x, &y);
    if(c%g != 0){
        printf("NONE\n");
        return 0;
    }
    x *= (c/g); y *= (c/g);
    if(a < 0) x *= (-1);
    if(b < 0) y *= (-1);
    printf("%lld %lld", x, y);*/

    // 5 task
    /*unsigned int x, y;
    scanf("%u %u", &x, &y);
    convert_to_base(x, y);
    return 0;*/

    // 6 task
    unsigned int x;
    scanf("%u", &x);
    convert_to_factorial_base(x);
}

