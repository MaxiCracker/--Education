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
        i++;
    }
    for (int j = i - 2; j > 0; j--) {
        printf("%d.", result[j]);
    }
    printf("\n");
}

ll exp(ll a, ll b){
  if(b == 1) return a;
  if(b%2 == 0) return ((exp(a,b/2))*(exp(a,b/2)));
  return (a*(exp(a,b-1)));
}

ll uppow(ll a, ll b, ll mod){
    ll curr = 1, p = a;
    for(int i = 0; i < b-1; ++i){
        p = exp(p,a);
        p %= mod;
    }
    return p;
}

ll fib_N(ll x, ll mod){
    if(x == 0) return 0;
    if(x== 1) return 1;
    ll curr = 0; ll next = 1;ll ans = 1;
    for(int i = 2; i <= x; ++i){
        ans = (curr+next)%mod;
        curr = next;
        next = ans;
    }
    return ans;
}

void Multiply2x2Matrices(ll A[2][2], ll B[2][2], ll m) {
    ll C[2][2];
    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % m;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % m;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % m;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % m;

    A[0][0] = C[0][0];
    A[0][1] = C[0][1];
    A[1][0] = C[1][0];
    A[1][1] = C[1][1];
}

void fastMatrixPower(ll F[2][2], ll n, ll mod) {
    if (n == 0 || n == 1) return;

    ll M[2][2] = {{1, 1}, {1, 0}};
    fastMatrixPower(F, n / 2, mod);
    Multiply2x2Matrices(F, F, mod);

    if (n % 2 != 0) Multiply2x2Matrices(F, M, mod);
}

void fastMatrixExponentiation2x2(ll F[2][2], ll n, ll m) {
    ll result[2][2] = {{1, 0}, {0, 1}};
    ll base[2][2] = {{F[0][0], F[0][1]}, {F[1][0], F[1][1]}};

    while (n > 0) {
        if (n % 2 != 0) {
            Multiply2x2Matrices(result, base, m);
        }
        Multiply2x2Matrices(base, base, m);
        n /= 2;
    }

    F[0][0] = result[0][0];
    F[0][1] = result[0][1];
    F[1][0] = result[1][0];
    F[1][1] = result[1][1];
}


ll fib_logN(ll n, ll mod) {
    if (n == 0) return 0;
    ll F[2][2] = {{1, 1}, {1, 0}};
    fastMatrixPower(F, n - 1, mod);
    return F[0][0];
}

ll pizanoo(ll m){
    ll curr = 0, next = 1, time = 0;
    while(1){
        ll oldNext = next;
        next = (curr+next)%m;
        curr = oldNext;
        ++time;
        if(curr == 0 && next == 1){
            return time;
        }
    }
    return time;
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
    /*unsigned int x;
    scanf("%u", &x);
    convert_to_factorial_base(x);*/

    // 7 task
    /*ll a=0,b=0,n=0 ,res=0, x, y;
    res = scanf("%lld %lld %lld", &a, &b, &n);
    assert(res == 3);
    ll ans = uppow(a,b,n);
    printf("%lld", ans);*/

    // 8 task
    /*ll a=0,mod=0,res=0;
    res = scanf("%lld %lld", &a, &mod);
    assert(res == 2);
    printf("%lld\n", fib(a,mod));*/

    // 9 task
    /*ll a=0,mod=0,res=0;
    res = scanf("%lld %lld", &a, &mod);
    assert(res == 2);
    ll fib_ = fib_logN(a,mod),pizano_ = pizanoo(mod);
    printf("%lld %lld", fib_, pizano_);*/

    // 11 task
    ll n=0,mod=0,res=0;
    ll f[2][2];
    res = scanf("%lld %lld %lld %lld %lld %lld", &f[0][0], &f[0][1], &f[1][0], &f[1][1], &n, &mod);
    assert(res == 6);
    fastMatrixExponentiation2x2(f, n, mod);
    printf("%lld %lld %lld %lld", f[0][0], f[0][1], f[1][0], f[1][1]);
}

