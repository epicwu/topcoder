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
bool f[10008];


class TheNumberGameDivOne {
public:
	string find(long long n) {
		
		if (n < 10)
		{
			if (n  == 4 || n == 6) return "John"; else return "Brus";			
		} else
		{
			long long tmp = n , cnt = 0;
			while (tmp % 2 == 0)
			{
				tmp/=2;
				cnt++;
			}
			if (cnt == 0) return "Brus"; else
			if (tmp != 1) return "John"; else
			if (cnt % 2 == 1) return "Brus"; else return "John";
		}

	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, long long p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	TheNumberGameDivOne *obj;
	string answer;
	obj = new TheNumberGameDivOne();
	clock_t startTime = clock();
	answer = obj->find(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	long long p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = 6ll;
	p1 = "John";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2ll;
	p1 = "Brus";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 747ll;
	p1 = "Brus";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 128ll;
	p1 = "Brus";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// John and Brus play a game with a number.
// The game starts with a positive integer n.
// The two players take alternating turns, John starts.
// Each move looks as follows:
// Let C be the current value of the integer.
// The current player has to choose a positive divisor of the number C, other than 1 and C.
// Once he chooses the divisor, he has to subtract it from C.
// The result is the new number with which the other player now starts his move.
// If a player cannot make a valid move, he loses the game.
// 
// 
// For example, if they start with n=15, one possible gameplay can look as follows:
// 
// John takes the number 15, chooses its divisor 3, and decreases the number to 15-3 = 12.
// Brus takes the number 12, chooses its divisor 4, and decreases the number to 12-4 = 8.
// John takes the number 8, chooses its divisor 2, and decreases the number to 8-2 = 6.
// Brus takes the number 6, chooses its divisor 3, and decreases the number to 6-3 = 3.
// John takes the number 3, and as there are no divisors other than 1 and 3, he has no valid move and thus he loses the game.
// 
// 
// 
// You are given the long long n.
// Assume that both players use the optimal strategy while playing the game.
// Return "John" (quotes for clarity) if John wins the game and "Brus" otherwise.
// 
// 
// DEFINITION
// Class:TheNumberGameDivOne
// Method:find
// Parameters:long long
// Returns:string
// Method signature:string find(long long n)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 10^18, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 6
// 
// Returns: "John"
// 
// John has two possible moves: either decrease 6 by 2 or decrease 6 by 3.
// If he chooses the second option, Brus will have no possible moves, hence John will win the game.
// 
// 1)
// 2
// 
// Returns: "Brus"
// 
// 
// 
// 2)
// 747
// 
// Returns: "Brus"
// 
// 
// 
// 3)
// 128
// 
// Returns: "Brus"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
