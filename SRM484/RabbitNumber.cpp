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


class RabbitNumber {
public:
	long long MAX;
	long long Check(long long x)
	{
		if (x>MAX) return 0; else
		{
			long long sum1 = 0,sum2 = 0;
			long long x2 = x;
			x2 *= (long long)x;
			
			while (x > 0){ 
			sum1 += x % 10;
			x/=10; 
			} 
			while (x2 > 0){ 
			sum2 += x2 % 10;
			x2/=10; 
			} 
			if (sum1 * sum1 == sum2) return 1; else return 0;
		}
	}
	long long Count(long long x)
	{

		long long sum = Check(x);
		if (x < MAX)
		{
			int t;
			if (x == 0) t = 1; else t = 0;
			for (int i = t;i<4;++i)
			sum += Count(x * 10 + i);
		}
		//cout<< x<<" ++ = " << sum <<endl;
		return sum;
	}
	int theCount(int low, int high) {
		MAX = high;
		
		long long tmp =Count(0);
		MAX = low - 1;
		cout<<tmp<<endl;
		tmp -= Count(0);
		return tmp;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	RabbitNumber *obj;
	int answer;
	obj = new RabbitNumber();
	clock_t startTime = clock();
	answer = obj->theCount(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 22;
	p1 = 22;
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 484;
	p1 = 484;
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 58;
	p2 = 12;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 58;
	p1 = 484;
	p2 = 24;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1000000000;
	p1 = 1000000000;
	p2 = 1;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
