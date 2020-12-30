#include <cstdio>
#include <algorithm>
#include <functional>
#include <map>
#include <utility>
#include <vector>


//Sereja and Increasing subsequence....lis on queries..same hai...bt ek conndition change karin hai
    
#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1E6 + 10, MAXL = 2E3 + 10;

int n, m;
int a[MAXN];

vector<PII> q[MAXN];
int ans[MAXN];

int main(){
	int cas;
	scanf("%d", &cas);
	while (cas--){
		scanf("%d%d", &n, &m);

		for (int i = 1; i <= n; ++i){
			scanf("%d", a + i);
			q[i].clear();
		}
		for (int l, r, i = 0; i < m; ++i){
			scanf("%d%d", &l, &r);
			q[r].push_back(PII(l, i));
		}

		vector<map<int, int> > b;
		for (int i = 1; i <= n; ++i){
			int len = 0;
			for (; len < b.size() && b[len].begin()->st < a[i]; ++len);
			if (len == b.size())
				b.push_back(map<int, int>());

			for (int j = len; j >= 0; --j){
				int t = j == 0 ? i : (--b[j - 1].lower_bound(a[i]))->nd;
				auto l = b[j].lower_bound(a[i]), r = l; 

				if (l == b[j].begin() || (--l)->nd < t){
					l = r;
					for (; r != b[j].end() && r->nd <= t; ++r);
					b[j].erase(l, r);
					b[j].insert(PII(a[i], t));
				}
			}

			for (int j = 0; j < q[i].size(); ++j){
				int low = 0, high = b.size(), mid;
				while (low < high){
					mid = low + (high - low >> 1);
					if (q[i][j].st <= b[mid].rbegin()->nd)
						low = mid + 1;
					else
						high = mid;
				}
				ans[q[i][j].nd] = low;
			}
		}

		for (int i = 0; i < m; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}
