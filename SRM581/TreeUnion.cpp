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


class TreeUnion {
public:
	vector<int> T1,T2;
	int queue[512];
	int cost[512];
	vector<int> E[512];
	int N;
	string tmp;
	void stringRead(vector<string> &tree)
	{
		for (int i = 0 ; i < 512; ++i) E[i].clear();
		tmp = "";
		for (int i = 0; i< tree.size();++i)
			tmp += tree[i];
		tmp +=' ';
		int val = 0;
		N = 1;
		for (int i = 0; i < tmp .size();++i)
			if (tmp[i] ==' ')
			{
				E[val].push_back(N);
				E[N].push_back(val);
				N++;
				val = 0;
			} else
			val = val * 10 + tmp[i] - '0';
	}
	void countPath(vector<string> &tree, vector<int> &ans)
	{
		stringRead(tree);
		for (int i = 0 ; i < N;++i)
			ans.push_back(0);
		for (int i = 0; i < N; ++ i)
		{
			int root = i;
			memset(cost, -1 ,sizeof(cost));
			//cout << cost[0]<<endl;
			int qn = 1, ptr = 0;
			cost[root] = 0;
			queue[0] = root;
			while (ptr < qn)
			{
				int now = queue[ptr];
				for (int j = 0; j < E[now].size() ;++j)
				{
					int next  = E[now][j];
					if (cost[next] < 0)
					{
						cost[next]=cost[now] + 1;
						queue[qn++] =  next;
					}
				}
				ptr++;
			}
			for (int j = root + 1; j < N ;++j)
				ans[cost[j]]++;
		}
	}
	double expectedCycles(vector <string> tree1, vector <string> tree2, int K) {
		countPath(tree1,T1);
		countPath(tree2,T2);
		double ans = 0;
		if (K < 4) return 0;
		for (int i = 1; i < K ;++i)
			if ( K - 2 - i <N && i<N && K-2-i>=0)
		ans += T1[i] * T2[K-2-i];
		ans = ans * 2 / double(N)/double(N-1); 
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, int p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	TreeUnion *obj;
	double answer;
	obj = new TreeUnion();
	clock_t startTime = clock();
	answer = obj->expectedCycles(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
	vector <string> p1;
	int p2;
	double p3;
	
	{
	// ----- test 0 -----
	string t0[] = {"0"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	p3 = 1.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"0 1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0 1"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	p3 = 1.3333333333333333;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0 1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0 1"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	p3 = 0.3333333333333333;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"0 ","1 1 1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0 1 0 ","1"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 5;
	p3 = 4.0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"0 1 2 0 1 2 0 1 2 5 6 1","0 11"," 4"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0 1 1 0 2 3 4 3 4 6 6"," 10 12 12"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 7;
	p3 = 13.314285714285713;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!