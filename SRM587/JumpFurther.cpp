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


class JumpFurther {
public:
	bool check(int x )
	{
		int y = 0;
		for (int i= 1; i < 3000;++i)
		{	
			y+=i;
			if ( y == x ) return true;
		}
		return false;
	}
	int furthest(int N, int badStep) {
		int sum = 0;
		sum = (1+N) * N /2;
		if (sum < badStep) return sum; else
		if (check(badStep)) return sum - 1; else return sum;	
		
	}
};



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!