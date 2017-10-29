#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
typedef vector<int> vi;

class UnionFind {
private: vi p, rank;
public:
	UnionFind(int n) {
		rank.assign(n,0);
		p.assign(n,0);
		rep(i,0,n) p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if(!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if(rank[x] < rank[y]) {
				p[x] = p[y];
			} else {
				p[y] = p[x];
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};
