#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int c[100000],tmp[100000];

class TriangleXor {
public:
	int theArea(int W) {
		double ans = 0 ;
		double M = W;
		ans = W+1;
		/*c[0] = 1;
		for (int i = 1 ; i<=M;++i)
		{
			if (i % 2 == 0)
			c[i] = 1; else c[i] = 0;
			for (int j = 0 ; j < i ;++j)
			c[i]-= (i+1-j) * c[j];
		}*/
		for (int i = 1; i <= M ;++i)
		{
			double tmp = -2;
			if (i % 2 ==0) tmp = 2;
			ans += tmp * double(M+1-i) * double(W)/double(W+i);
		}
		ans = ans * W / 2.0;
//		cout<<ans<<endl;
		return (int) ans;
	}
};



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
