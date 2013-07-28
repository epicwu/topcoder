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
#include <cstring>
using namespace std;

const long long MOD = 1000000009;
int N,LL,AA,BB;
int data[512];
long long f[310][310][2];

long long dp(int s,int M,int state)
{
	if (s == 4 && M ==1 && state == 1)
	{
		cout<<"stop"<<endl;
	} 
	if (M == 0)
	{
		if (state == 0) return 0; else return 1;
	}
	if (s >= N) return 0;
	if (f[s][M][state] >= 0) return f[s][M][state];
	long long ans = 0;
	if (state == 0)
	{
		int now = data[s];
		for (int i = 1 ; (i <= LL) && (s+i <=N); ++i)
		{
			if (now >= AA && now <= BB)
			if (i == LL)
			{
				ans = ( ans + dp(s+i,M-1,1) ) % MOD;
			} else
				ans = ( ans + dp(s+i,M-1,0) ) % MOD;
			now += data[s+i];
		}
	} else
	{
		int now = data[s];
		for (int i = 1 ; (i <= LL) && (s+i <=N); ++i)
		{
			if (now >= AA && now <= BB)
				ans = ( ans + dp(s+i,M-1,1) ) % MOD;
			now += data[s+i];
		}	
		for (int i = 1; s+i <= N; ++i)
		ans = (ans + dp(s+i,M,0)) % MOD;	
	}
	f[s][M][state] = ans;
	return ans;
}

class TheExperiment {
public:
	
	int countPlacements(vector <string> intensity, int M, int L, int A, int B) {
		LL = L;
		AA = A;
		BB = B;
		string tmp = "";
		for (int i = 0;  i < int(intensity.size()); ++i)
			tmp += intensity[i];
		N = tmp.size();
		for (int i = 0 ; i < N ; ++i) data[i] = tmp[i] - '0';

		memset(f,-1,sizeof(f));
		long long ans = 0;
		for (int i = 0 ; i < N; ++i)
			ans = (ans + dp(i,M,0)) % MOD;
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, int p3, int p4, bool hasAnswer, int p5) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	TheExperiment *obj;
	int answer;
	obj = new TheExperiment();
	clock_t startTime = clock();
	answer = obj->countPlacements(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	
	vector <string> p0;
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;
	/*
	{
	// ----- test 0 -----
	string t0[] = {"341156"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 3;
	p3 = 6;
	p4 = 10;
	p5 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	*/
	{
	// ----- test 1 -----
	string t0[] = {"999112999"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 4;
	p3 = 21;
	p4 = 30;
	p5 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 2;
	p3 = 2;
	p4 = 3;
	p5 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"59059","110","1132230231"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 5;
	p3 = 10;
	p4 = 20;
	p5 = 6;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"111111111111111111111111","111111111111111111111111111","11111111111111111111111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 12;
	p2 = 8;
	p3 = 4;
	p4 = 2700;
	p5 = 418629948;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
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
// Manao is conducting an experiment to measure the humidity level of some spongy material. The experiment is conducted in a closed room which is observed from a side, so we will consider it in two dimensions.
// 
// The room is N centimeters wide. There are N drop counters built in the ceiling of the room. Drop counter 0 is attached 0.5 centimeters from the left end of the room, and each next one is attached 1 centimeter to the right of the previous one. You are given a vector <string> intensity filled with digits. Concatenate its elements to obtain one string S of length N. The i-th (0-based index) drop counter drips exactly S[i] drops per minute, where S[i] is the digit at the i-th position in S.
// 
// Manao is going to place M sponges in the room. All sponges are exactly L centimeters long and their thickness is negligible.
// Each sponge must be placed horizontally, it must be entirely within the room, and the distance between the left wall of the room and the sponge must be an integer.
// In other words, the coordinate of its left end must be an integer between 0 and N-L, inclusive.
// Different sponges must be attached at different heights.
// Each sponge will totally absorb every drop that drips at it.
// For example, in the following picture, the sponges (from top to bottom) absorb 12, 5, and 3 drops per minute.
// 
// 
// 
// The experiment requires the sponges to be attached in such a way that each of them absorbs between A and B drops per minute, inclusive.
// Manao is interested in the number of ways in which this can be done.
// Two ways P and Q of attaching the sponges are the same if and only if for each sponge S1 in P there exists a sponge S2 in Q such that S1 and S2 lie directly beneath the same sets of drop counters.
// A sponge X lies directly beneath a drop counter Y if there is no other sponge between them.
// That is, if there is some water dripping from the drop counter Y, it all lands on the sponge X.
// Note that according to these definitions the sponges are indistinguishable.
// 
// You are given the vector <string> intensity and the ints M, L, A, and B.
// Count the number of different ways to attach the sponges and return that count modulo 1,000,000,009.
// 
// DEFINITION
// Class:TheExperiment
// Method:countPlacements
// Parameters:vector <string>, int, int, int, int
// Returns:int
// Method signature:int countPlacements(vector <string> intensity, int M, int L, int A, int B)
// 
// 
// CONSTRAINTS
// -intensity will contain between 1 and 6 elements, inclusive.
// -Each element of intensity will be between 1 and 50 characters long, inclusive.
// -Each element of intensity will consist of digits ('0'-'9') only.
// -M will be between 1 and 300, inclusive.
// -L will be between 1 and N, inclusive, where N is the total number of characters in intensity.
// -A will be between 1 and 2700, inclusive.
// -B will be between A and 2700, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"341156"}
// 3
// 3
// 6
// 10
// 
// Returns: 2
// 
// Manao needs to place three sponges of length 3 in such a way that they absorb between 6 and 10 drops per minute. The valid ways to attach the sponges are the following:
// 
// 
// In the first way, the sponges receive 8, 6 and 6 drops, from highest to lowest. In the second way, they absorb 7, 7 and 6. Note that Manao could interchange the heights of the lower two sponges in the second picture, but this would result in the same way.
// 
// 1)
// {"999112999"}
// 2
// 4
// 21
// 30
// 
// Returns: 2
// 
// One of the platforms should have its left end exactly at the left wall. The other's left end can be either 4 or 5 centimeters away from the left wall.
// 
// 2)
// {"111"}
// 2
// 2
// 2
// 3
// 
// Returns: 0
// 
// One of the platforms will never receive enough drops.
// 
// 3)
// {"59059", "110", "1132230231"}
// 1
// 5
// 10
// 20
// 
// Returns: 6
// 
// 
// 
// 4)
// {"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"}
// 12
// 8
// 4
// 2700
// 
// Returns: 418629948
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!