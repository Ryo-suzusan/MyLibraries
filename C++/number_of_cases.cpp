#include <iostream> 
#include <cmath> 
#include <vector> 
#include <queue> 
#include <string> 
#include <sstream> 
#include <algorithm>  
#include <limits>  
#include <climits>  
#include <tuple>  
#include <set>  

#define M_PI 3.14159265358979323846

using namespace std;
using ll = long long;

ll facctorialMethod(int n) {
	ll result = 1;
	for (int i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}

// nPr
ll permutationMethod(int n, int r) {
	ll nNum = n - r;
	ll result = 1;
	for (int i = n; i > nNum; i--) {
		result *= i;
	}
	return result;
}

// nCr
ll combinationMethod(int n, int r) {
	if (r > n) return 0;
	if (n - r < r) r = n - r;
	if (r == 0) return 1;

	ll result = n;
	for (int i = 2; i <= r; i++) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}
