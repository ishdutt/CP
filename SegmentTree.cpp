#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100000;
const int MOD = 1000000007;

int n, a[MAXN];

struct Node // data structure for segment tree
{
    int maximum, sum0, sum1; // longest increasing subsequence (LIS), the number of LIS, the number of second LIS.
    Node() {
        maximum = 0;
        sum0 = 0;
        sum1 = 0;
    }
}tree[MAXN * 4];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

Node merge(const Node &a, const Node &b) // merge two intervals
{
    Node ret;
    ret.maximum = max(a.maximum, b.maximum);
    if (a.maximum == ret.maximum) {
        add(ret.sum0, a.sum0);
        add(ret.sum1, a.sum1);
    } else if (a.maximum == ret.maximum - 1) {
        add(ret.sum1, a.sum0);
    }
    if (b.maximum == ret.maximum) {
        add(ret.sum0, b.sum0);
        add(ret.sum1, b.sum1);
    } else if (b.maximum == ret.maximum - 1) {
        add(ret.sum1, b.sum0);
    }
    return ret;
}

Node query(int num, int l, int r, int ll, int rr)
{
    if (ll <= l && r <= rr) {
        return tree[num];
    }
    if (l > rr || r < ll) {
        return Node();
    }
    int mid = l + r >> 1;
    return merge(query(num * 2, l, mid, ll, rr), query(num * 2 + 1, mid + 1, r, ll, rr));
}

void insert(int num, int l, int r, int pos, const Node &value)
{
    tree[num] = merge(tree[num], value);
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) {
        insert(num * 2, l, mid, pos, value);
    } else {
        insert(num * 2 + 1, mid + 1, r, pos, value);
    }
}

int main()
{
    int tests;
    for (scanf("%d", &tests) == 1; tests --; ) {
        scanf("%d", &n);
        vector<int> values;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
            values.push_back(a[i]);
        }
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        for (int i = 0; i < n; ++ i) {
            a[i] = lower_bound(values.begin(), values.end(), a[i]) - values.begin() + 1;
        }

        memset(tree, 0, sizeof(tree));
        Node one;
        one.sum0 = 1;
        insert(1, 0, values.size(), 0, one);
        for (int i = 0; i < n; ++ i) {
            Node cur = query(1, 0, values.size(), 0, a[i] - 1);
            cur.maximum += 1;
            insert(1, 0, values.size(), a[i], cur);
        }
        fprintf(stderr, "LIS = %d\n", tree[1].maximum);
        printf("%d\n", tree[1].sum1);
    }
    return 0;
}
