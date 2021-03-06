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


class ShoutterDiv1 {
public:
	vector<int> S,T;
	int N ;
	void processNumber(vector <string> &s1000, vector <string> &s100, vector <string> &s10, vector <string> &s1,vector<int> &x)
	{
		string tmp="";
		for (int i = 0; i < s1000.size();++i) tmp += s1000[i];
		N = tmp.size();
		for (int i = 0; i < N ;++i)	x.push_back(tmp[i]-'0');

		tmp = "";
		for (int i = 0; i < s100.size();++i) tmp += s100[i];
		for (int i = 0; i < N ;++i)	x[i] =  x[i] * 10 + tmp[i]-'0';
		tmp = "";
		for (int i = 0; i < s10.size();++i) tmp += s10[i];
		for (int i = 0; i < N ;++i)	x[i] =  x[i] * 10 + tmp[i]-'0';
		tmp = "";
		for (int i = 0; i < s1.size();++i) tmp += s1[i];
		for (int i = 0; i < N ;++i)	x[i] =  x[i] * 10 + tmp[i]-'0';
	}
	int solve()
	{
		int ans = 0;
		for (int i = 0 ; i < N;++i)
		{
			int now =T[i], right = T[i];
			for (int j=0; j < N ; ++j )
				if (T[j] >= S[i])
				{
					if (!(S[j] > now || T[j] < S[i]))
					right = max(right,T[j]);
					if (S[j] > now)
					{
						if (S[j] > right) return -1;
						ans ++;
						now = right;
						right = max(right,T[j]);
					}
				}
		}
		return ans;
	}
	void mySort(vector<int> &S,vector<int> &T)
	{
		for (int i = 0; i < N;++i)
			for (int j = i+1 ; j < N ;++j)
				if (S[j] < S[i])
				{
					swap(S[i],S[j]);
					swap(T[i],T[j]);
				}
	}
	int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1) {
		processNumber(s1000,s100,s10,s1,S);
		processNumber(t1000,t100,t10,t1,T);
		mySort(S,T);
		for (int i = 0 ; i <N;++i)
			cout<< S[i]<<"-->"<<T[i]<<endl;
		
		int tmp = solve(),ans;
		if (tmp<0) return tmp; else ans = tmp;
		for (int i =0; i<N;++i)
		{
				S[i] = - S[i];
				T[i] = - T[i];
				swap(S[i],T[i]);
		}
		mySort(S,T);
		tmp = solve();
		if (tmp<0) return tmp; else ans += tmp;
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, vector <string> p3, vector <string> p4, vector <string> p5, vector <string> p6, vector <string> p7, bool hasAnswer, int p8) {
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
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p3[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p4[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p5.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p5[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p6.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p6[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p7.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p7[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ShoutterDiv1 *obj;
	int answer;
	obj = new ShoutterDiv1();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2, p3, p4, p5, p6, p7);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p8 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p8;
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
	vector <string> p2;
	vector <string> p3;
	vector <string> p4;
	vector <string> p5;
	vector <string> p6;
	vector <string> p7;
	int p8;
	
	{
	// ----- test 0 -----

	string t0[] = {"0000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0100"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"8039"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"3138"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"0000"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"1101"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"0190"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"6120"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"00"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"00"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"00"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"13"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"00"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"00"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"00"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"24"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = -1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"0000"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"1234"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"0000"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"0000"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"0000"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"2345"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"0000000000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0000000000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"0000000000"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"7626463146"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"0000000000"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"0000000000"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"0000000000"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"9927686479"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 18;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"00000000000000000000000000000000000000000000000000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"00000000000000000000000000000000000000000000000000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"50353624751857130208544645495168271486083954769538"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"85748487990028258641117783760944852941545064635928"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"00000000000000000000000000000000000000000000000000"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"00000000000000000000000000000000000000000000000000"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"61465744851859252308555855596388482696094965779649"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"37620749792666153778227385275518278477865684777411"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 333;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
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
