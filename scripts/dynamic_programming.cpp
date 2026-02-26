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
#include <bit>

#define M_PI 3.14159265358979323846

using namespace std;
using ll = long long;
using IGraph = vector<vector<int>>;
using LLGraph = vector<vector<ll>>;
using BGraph = vector<vector<bool>>;

void knapsackDP(const vector<ll>& weight, const vector<ll>& value, LLGraph& dp) {
	// dpは事前にサイズ[データ数 + 1][最大重量 + 1]で初期化済みとする
	int N = (int)dp.size() - 1;
	int W = (int)dp[0].size() - 1;
	// 初期条件: dp[0][w] = 0
	for (int w = 0; w <= W; w++) dp[0][w] = 0;

	for (int i = 0; i < N; i++) {
		for (int w = 0; w <= W; w++) {
			if (w >= weight[i + 1]) dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
			else dp[i + 1][w] = dp[i][w];
		}
	}

	// デバッグ用
	for (int i = 0; i <= N; i++) {
		for (int w = 0; w <= W; w++) {
			cout << dp[i][w] << " ";
		}
		cout << endl;
	}
}

ll intervalDP(vector<vector<ll>>& dp, int left, int right) {
	// -1は未探索
	if (dp[left][right] != -1) return dp[left][right];
	if (abs(left - right) < 1) return dp[left][right] = 0;

	ll result = 0;
	// 適切に初期化
	result = right - left;

	for (int mid = left + 1; mid < right; mid++) {
		result = max(result, intervalDP(dp, left, mid) + intervalDP(dp, mid, right));
	}

	return dp[left][right] = result;
}

ll bitDP(vector<vector<ll>>& dp, vector<vector<ll>>& dist, int bit, int v) {
	// dpは事前にサイズ[1<<データ数][データ数]で初期化済みとする
	int N = dp[0].size();

	// bit: 全体集合の部分集合を表すビット列
	// -1は未探索
	if (dp[bit][v] != -1) return dp[bit][v];
	if (bit == (1ll << v)) return dp[bit][v] = 0;

	ll result = numeric_limits<ll>::max();
	int prev_bit = bit & ~(1 << v);

	for (int u = 0; u < N; u++) {
		if (!(prevBit & (1 << u))) continue;

		if (result > bitDP(dp, dist, prevBit, u) + dist[u][v]) {
			result = bitDP(dp, dist, prevBit, u) + dist[u][v];
		}
	}

	return dp[bit][v] = result;
}

// いもす法: 左上, 右下を+1、右上, 左下を-1で初期化済みとする
void imosCumulate(Graph& tiles) {
	int h = tiles.size();
	int w = tiles[0].size();

	// 横方向の累積和
	for (int y = 0; y < h; y++) {
		for (int x = 1; x < h; x++) {
			tiles[y][x] += tiles[y][x - 1];
		}
	}
	// 縦方向の累積和
	for (int y = 1; y < h; y++) {
		for (int x = 0; x < h; x++) {
			tiles[y][x] += tiles[y - 1][x];
		}
	}
}





