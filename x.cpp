/*
 * the time limit is very strict so I'll explain the main idea then we will try to optimize it
 * we loop from the first to the last row 
 * let last [M] , last[i] = is the last row which s[lastrow][i] = '0' 
 * we will put last [i] in a vector , sort it and try to get every perfix of the vector as a solution 
 * but sorting is expensive, we notice that every last [i] either will stay last [i] or will be equel to the current row 
 * if last [i] will be equel to the current row then for sure it will be the maximum last [i] 
 * so we just make another vector move all the last [i] which stayed last[i] then move the last[i] which become the current row
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , m , ans ;
vpi v ;
int last [1509] ;
int main () {
	fast ;
	mem ( last , -1 ) ;
	cin >> n >> m ;
	for ( int i = 0 ; i < m ; i ++ ) v .pb ( { -1 , i } ) ;
	for ( int i = 0 ; i < n ; i ++ ){
		string s ;
		cin >> s ;
		vpi newv ;
		for ( int j = 0 ; j < m ; j ++ ) {
			if ( s [j] == '0' ) last [j] = i ;
		}
		for ( auto u : v ) {
			if ( last [ u.se ] != i ) newv .pb ( u ) ;
		}
		for ( auto u : v ) {
			if ( last [ u.se ] == i ) newv .pb ( { i , u.se } ) ;
		}
		v = newv ;
		int last = 0 ;
		for ( auto u : v ) {
			last ++ ;
			ans = max ( ans , ( i - u.fi ) * last ) ;
		}
	}
	cout << ans << endl ; 
}
