#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <tuple>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using IGraph = vector<vector<int>>;
using LLGraph = vector<vector<ll>>;
using BGraph = vector<vector<bool>>;

#define M_PI 3.14159265358979323846
#define MOD 10007
constexpr int kIMax = numeric_limits<int>::max();
constexpr ll kLLMax = numeric_limits<ll> ::max();


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

void dfs(const LLGraph& g, int start, vector<bool>& seen) {
	seen[start] = true;

	for (auto nextV : g[start]) {
		if (seen[nextV]) continue;
		dfs(g, nextV, seen);
	}
}

void bfs(const LLGraph& g, int start) {
	vector<bool> seen(g.size());
	seen[start] = true;
	
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int nextV : g[v]) {
			if (seen[nextV]) continue;

			seen[nextV] = true;
			q.push(nextV);
		}
	}
}

// pair<row, column>
const vector<pair<int, int>> direction = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};
using Grid = vector<vector<bool>>;

void gridDfs(const Grid& g, pair<int, int> start, Grid& seen) {
	seen[start.first][start.second] = true;

	for (auto dr : direction) {
		int rIdx = start.first + dr.first;
		int cIdx = start.second + dr.second;
		if ((int)seen.size() <= rIdx ||
			rIdx < 0 ||
			(int)seen[0].size() <= cIdx ||
			cIdx < 0) {
			continue;
		}

		if (seen[rIdx][cIdx] || !g[rIdx][cIdx]) continue;
		gridDfs(g, { rIdx, cIdx }, seen);
	}
}

void gridBfs(const Grid& g, pair<int, int> start, Grid& seen) {
	queue<pair<int, int>> q;

	seen[start.first][start.second] = true;
	q.emplace(start.first, start.second);

	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();

		for (auto dr : direction) {
			int rIdx = v.first + dr.first;
			int cIdx = v.second + dr.second;
			if ((int)seen.size() <= rIdx ||
				rIdx < 0 ||
				(int)seen[0].size() <= cIdx ||
				cIdx < 0) {
				continue;
			}

			if (seen[rIdx][cIdx] || !g[rIdx][cIdx]) continue;

			seen[rIdx][cIdx] = true;
			q.emplace(rIdx, cIdx);
		}
	}
}


