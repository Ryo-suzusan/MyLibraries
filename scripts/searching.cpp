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

// めぐる式二分探索
ll binarySearch(const vector<ll>& v, ll key) {
	// indexが条件を満たすかどうか
	auto isOK = [&](ll index) {
		if (v[index] >= key) return true;
		else return false;
		};

	ll ng = -1;	// 解が存在しない値
	ll ok = (ll)v.size();	// 解が存在する値
	// (indexがv.size() - 1のときも条件を見たさない=解が存在しない可能性があるため、ok = v.size()と初期化)

	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;

		if (isOK(mid)) ok = mid;
		else ng = mid;
	}
	return ok;
}

void dfs(const Graph& g, int start, vector<bool>& seen) {
	seen[start] = true;

	for (auto nextV : g[start]) {
		if (seen[nextV]) continue;
		dfs(g, nextV, seen);
	}
}

void bfs(const Graph& g, int start, vector<bool>& seen) {
	queue<ll> q;

	seen[start] = 0;
	q.push(start);

	while (!q.empty()) {
		ll v = q.front();
		q.pop();

		for (int nextV : g[v]) {
			if (seen[nextV]) continue;

			seen[nextV] = true;
			q.push(nextV);
		}
	}
}

