#include<iostream>
#include<algorithm>
using namespace std;

int findIndex(int a[], int n, int x, int p) {
    int min = 100000000, minp=-1;
    for(int i=0;i<n;i++){
        if(a[i] == x) {
            if(abs(p-i) < min) {
                cout<<"I"<<i<<" "<<a[i]<<endl;
                min = abs(p-i);
                minp = i;
            }
        }
    }
    cout<<"TEST="<<minp<<endl;
    return minp;
}
void solve() {
    int N, X, p, k;
    cin >> N >> X >> p >> k;
    int a[N];
    for(int i=0;i<N;i++)
    cin >> a[i];
    sort(a, a+N);
    int index = findIndex(a, N, X, p);
    int count = 0;
    //WHEN NO X IS PRESENT
    if(a[index] != X) {
        a[k-1] = X;
        sort(a, a+N);
        count++;
    }
    //C1
    cout<<"COUNT="<<count<<endl;
    if(a[p-1] == X) {
        cout << 0+count;
        return;
    }
    //C2
    if(p < k && a[p-1] < X) {
        cout<<"HELLO\n";
        cout << -1;
        return;
    }
    //C3
    if(p > k && a[p-1] > X) {
        cout<<"CONAN\n";
        cout << -1;
        return;
    }
    //SAME AS YOURS ;) abs(xindex+1-p)
    index = findIndex(a, N, X, p)+1;
    cout << abs(p-index)+count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
return 0;
}