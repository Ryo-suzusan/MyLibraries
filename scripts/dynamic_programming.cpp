#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <climits>
#include <tuple>
#include <map>
#include <set>
#include <random>

#define M_PI 3.14159265358979323846

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

void knapsackDP(const vector<ll>& weight, const vector<ll>& value, vector<vector<ll>>& dp) {
	// dpは事前にサイズ[データ数][最大重量]で初期化済みとする
	ll N = dp.size();
	ll W = dp[0].size();
	for (ll i = 0; i < N; i++) {
		for (ll w = 0; w <= W; w++) {
			if (w >= weight[i]) dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
			else dp[i + 1][w] = dp[i][w];
		}
	}
}

ll intervalDP(vector<vector<ll>>& dp, ll left, ll right) {
	// -1は未探索
	if (dp[left][right] != -1) return dp[left][right];
	if (abs(left - right) < 1) return 0;

	ll result = 0;
	// 適切に初期化
	result = right - left;
	for (ll mid = left + 1; mid < right; mid++) {
		result = max(result, intervalDP(dp, left, mid) + intervalDP(dp, mid, right));
	}

	return dp[left][right] = result;
}
