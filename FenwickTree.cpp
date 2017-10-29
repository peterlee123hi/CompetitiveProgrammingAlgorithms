#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
typedef vector<int> vi;

class FenwickTree {
private: vi ft;
public:
	FenwickTree(int n) {
		ft.assign(n + 1,0);
	}

	int count(int x) {
        x++;
		int c = 0;
		while(x > 0) {
			c += ft[x];
            x += x & -x;
		}
		return c;
	}

	int count(int a, int b) {
		return count(b) - count(a - 1);
	}

	void inc(int x, int count) {
        x++;
		while(x < sz(ft)) {
            ft[x] += count;
            x += x & -x;
		}
	}
};
