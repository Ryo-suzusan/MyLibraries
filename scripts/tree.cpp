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

struct Edge {
	int to;
	ll cost;
};
void dijkstra(const vector<vector<Edge>>& g, vector<ll>& dist, int v) {
	dist.assign(g.size(), numeric_limits<ll>::max());
	// q: {最短距離, 頂点}
	priority_queue < pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	q.emplace((dist[v] = 0), v);

	while (!q.empty()) {
		const ll remainDist = q.top().first;
		const int from = q.top().second;
		q.pop();

		if (dist[from] < remainDist) continue;

		for (const auto& edge : g[from]) {
			const ll newDist = (dist[from] + edge.cost);

			if (newDist < dist[edge.to]) {
				q.emplace((dist[edge.to] = newDist), edge.to);
			}
		}
	}
}

// dpはサイズ[頂点数][頂点数]、未知要素は十分に大きな値であるとする
void floyd_Warshall(Graph& dp) {
	int n = dp.size();

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

class UnionFind
{
private:
	// m_parentsOrSize[i] は i の 親,
	// ただし root の場合は (-1 * そのグループに属する要素数)
	std::vector<int> m_parentsOrSize;
public:
	UnionFind() = default;

	/// @brief Union-Find 木を構築します。
	/// @param n 要素数
	explicit UnionFind(size_t n)
		: m_parentsOrSize(n, -1) {
	}

	/// @brief 頂点 i の root のインデックスを返します。
	/// @param i 調べる頂点のインデックス
	/// @return 頂点 i の root のインデックス
	int find(int i)
	{
		if (m_parentsOrSize[i] < 0)
		{
			return i;
		}

		// 経路圧縮
		return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
	}

	/// @brief a のグループと b のグループを統合します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a != b)
		{
			// union by size (小さいほうが子になる）
			if (this->size(a) < this->size(b))
			{
				// bをaの子にする
				std::swap(a, b);
			}

			m_parentsOrSize[a] += m_parentsOrSize[b];
			m_parentsOrSize[b] = a;
		}
	}

	/// @brief a と b が同じグループに属すかを返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @return a と b が同じグループに属す場合 true, それ以外の場合は false
	bool connected(int a, int b)
	{
		return (find(a) == find(b));
	}

	/// @brief i が属するグループの要素数を返します。
	/// @param i インデックス
	/// @return i が属するグループの要素数
	int size(int i)
	{
		return -m_parentsOrSize[find(i)];
	}
};
// クラスカル方は隣接リスト向き(O(ElogV))
struct EdgeDetail
{
	int from;
	int to;
	ll cost;
	bool operator <(const Edge& other) const {
		return (cost < other.cost);
	}
};
// 最小全域木の重みを返す
ll kruskal(const vector<EdgeDetail>& edges, int vnum) {
	// 辺をコストの小さい順にソート
	sort(edges.begin(), edges.end());

	UnionFind uf(vnum);

	ll result = 0;
	for (const auto& edge : edges) {
		if (!uf.connected(edge.from, edge.to)) {
			uf.merge(edge.from, edge.to);
			result += edge.cost;
		}
	}

	return result;
}

// プリム法は隣接行列向き(O(V^2))
ll prim(const Graph& g, vector<ll>& mincost) {
	int n = g.size();
	mincost.assign(n, numeric_limits<ll>::max());
	vector<bool> seen(n, false);

	ll result = 0;
	mincost[0] = 0;

	while (true) {
		int to = -1;
		for (int u = 0; u < n; u++) {
			if (!seen[u] && (to == -1 || mincost[u] < mincost[to]))
				to = u;
		}

		if (to == -1) break;
		seen[to] = true;
		result += mincost[to];

		for (int from = 0; from < n; from++) {
			if (g[from][to] != -1)
				mincost[to] = min(mincost[to], g[from][to]);
		}
	}
	return result;
}
