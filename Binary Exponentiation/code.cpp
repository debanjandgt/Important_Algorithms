#include <iostream>
using namespace std;
using lli = long long;

lli binpow(lli a, lli b, lli mod) {
    if (b == 0)
        return 1;
    if (b % 2) {
        return a * binpow(a, b - 1, mod) % mod;
    } else {
        lli temp = binpow(a, b / 2, mod);
        return temp * temp % mod;
    }
}

int main() {
    // Input values
    lli a, b;
    cin >> a >> b ;

    // Apply modulo to avoid overflow
    lli mod = 1000000007; // or any other modulo value
    a %= mod;
    b %= mod;

    lli ans = binpow(a,b, mod);


    // Output the result
    cout << ans << endl;

    return 0;
}
