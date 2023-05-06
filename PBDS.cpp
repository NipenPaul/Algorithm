#include<bits/stdc++.h>
using namespace std;
/** Policy-based data structures
  order_of_key(n); return n data position
  find_by_order(n); return n index data
 */ 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


// PBDS MULTISET USING LESS_EQUAL
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
indexed_set s;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
indexed_set s;

int main(){
	s.insert(2);
	s.insert(3);
	s.insert(7);
	s.insert(9);
	auto x = s.find_by_order(2);
	cout << *x << "\n"; // 7
	cout << s.order_of_key(7) << "\n"; // 2
	cout << s.order_of_key(6) << "\n"; // 2
	cout << s.order_of_key(8) << "\n"; // 3
return 0;
}

