#include <iostream> 
#include <cmath> 
#include <vector> 
#include <queue> 
#include <string> 
#include <sstream> 
#include <algorithm>  
#include <limits>  
#include <tuple>  
#include <set>  

#define M_PI 3.14159265358979323846

using namespace std;
using ll = ll;

unsigned gcd(unsigned m, unsigned n) {
	if (n == 0) return m;
	else return gcd(n, m % n);
}

unsigned lcm(unsigned m, unsigned n) {
	if (m == 0 || n == 0) return 0;
	return m / gcd(m, n) * n;
}

unsigned extGcd(ll a, ll b, ll& x, ll& y) {
	// 返り値はgcd(a, b)
	// ax + by = gcd(a, b)を満たすx, yを格納
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	// qx + y = s, x = t
	ll d = extGcd(b, a % b, y, x); // x = t
	y -= a / b * x; // y = s - qt
	return d;
}

unsigned getDigit(unsigned num) {
	return to_string(num).length();
}

bool isPrime(ll n) {
	if (n == 1) return false;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

vector<ll> enumDivisors(ll n) {
	vector<ll> result;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			result.push_back(i);
			if (n / i != i) result.push_back(n / i);
		}
	}
	// 必要ならソート
	sort(result.begin(), result.end());
	return result;
}

vector<pair<ll, ll>> primeFactorize(ll n) {
	vector<pair<ll, ll>> result;

	for (ll i = 2; i * i <= n; i++) {
		if (n % i != 0) continue;

		ll exp = 0;
		while (n % i == 0) {
			n /= i;
			exp++;
		}

		result.push_back({ i, exp });
	}

	if (n > 1) result.push_back({ n, 1 });
	return result;
}

ll eulerMethod(ll n) {
	const auto& pf = primeFactorize(n);
	ll result = n;
	for (auto p : pf) {
		result *= (p.first - 1);
		result /= p.first;
	}
	return result;
}

ll modpow(ll a, ll n, ll mod) {
	ll result = 1;
	while (n > 0) {
		if (n & 1) result = result * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return result;
}

ll modinv(ll a, ll mod) {
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;

}
