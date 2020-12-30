#include <vector>
#include <cstdio>
#include <chrono>
#define INFINITY 9999999

using namespace std;
using namespace std::chrono;

typedef int cost;
typedef vector<cost> vcost;
typedef vector<int> vint;
typedef vector<vcost> vvcost;
typedef vvcost adjacency_matrix;

int prim(const adjacency_matrix& A) {
  int n = A.size();
  vcost dist(n, INFINITY);
  vint parent(n);
  int v = 0;
  int total_cost = 0;
  while (true) {
    dist[v] = -dist[v];
    for (int i = 0; i < n; ++i) {
      if (dist[i] > 0 && A[v][i] < dist[i]) {
        dist[i] = A[v][i];
        parent[i] = v;
      }
    }
    int mi = -1;
    for (int i = 0; i < n; ++i) {
      if ((mi == -1 || dist[i] < dist[mi]) && dist[i] > 0) mi = i;
    }
    if (mi == -1) break;
    total_cost += A[mi][parent[mi]];
    v = mi;
  }
  return total_cost;
}


int main() {
  int n, m, u, v;
  cost w;
  scanf("%d %d", &n, &m);
  adjacency_matrix A(n, vcost(n, INFINITY));
  for (int j = 0; j < m; ++j) {
    scanf("%d %d %d", &w, &u, &v);
    A[u][v] = A[v][u] = -w;
  }

  high_resolution_clock c;
  auto t1 = c.now();
  prim(A);
  auto t2 = c.now();
  printf("%ld\n", duration_cast<milliseconds>(t2 - t1).count());
}
