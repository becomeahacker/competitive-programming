#include<bits/stdc++.h>
using namespace std;
#define int int64_t
 
const int MAXN = 1e5 + 1;
int n , m;
int tree[ 4*MAXN ];
int a[MAXN];
 
void build(int v , int tl, int tr) {
	if(tl == tr){
		tree[v] = a[tl];
	}else {
		int tmid = (tl + tr)/2;
		build(2*v , tl , tmid);
		build(2*v + 1, tmid + 1 , tr);
		tree[v] = min(tree[2*v] , tree[2*v + 1]);
	}
}
 
void update(int v, int tl ,int tr , int idx , int val) {
	if(tl == tr) {
		tree[v] = val;
	} else {
		int tmid = (tl + tr)/2;
		if(idx > tmid) {
			update(2*v + 1 , tmid + 1 , tr , idx , val);
		} else {
			update(2*v , tl , tmid , idx , val);
		}
		tree[v] = min(tree[2*v] , tree[2*v + 1]);
	}
}
int query(int v , int tl , int tr , int l , int r) {
	if(tl > r || l > tr )
		return INT_MAX;
	if(tl >= l && tr <= r) 
		return tree[v];
	int tmid = (tl + tr)/2;
	return min( query(2*v , tl , tmid , l , r) , query(2*v + 1 , tmid + 1 , tr , l , r));
}
 
int32_t main() {
	cin >> n >> m;
	for(int i = 0 ; i < n; ++i) 
		cin >> a[i];
	build(1 , 0 , n-1);
	while(m--) {
		int q , l , r;
		cin >> q >> l >> r;
		if( q == 1) {
			update(1 , 0 , n-1 , l , r);
		} else {
			--r;
			cout << query(1 , 0 , n-1 , l , r) << "\n";
		}
	}
	
	
}