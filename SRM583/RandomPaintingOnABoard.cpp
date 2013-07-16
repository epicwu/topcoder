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


class RandomPaintingOnABoard {
public:
	int data[32][32],n,m,SUM;
	int f[32][2000];
	int row[32];
	int ans[2000];
	double DP()
	{
		memset(ans,0,sizeof(ans));
		for ( int mask =0 ; mask < (1<<m) ;++mask)
		{
			memset(row,0,sizeof(row));
			for (int i = 0; i <n; ++i)
				for (int j = 0; j < m ;++j)
					if ( ((1<<j) & mask) == 0 )
						row[i] += data[i][j];
			memset(f,0,sizeof(f));
			int sign = -1, tmp = 0;
			for (int i =0;i<m;++i)
			{
				if ( ((1<<i) & mask) > 0 )
					sign = -sign;
				tmp +=data[0][i];
			}
			f[0][row[0]] += sign;
			f[0][0] += -sign;
			for (int i=0;i<n-1;++i)
			{
				for (int x=0;x<SUM;++x)
				{
					f[i+1][x] += -f[i][x];
					if (x + row[i+1] <SUM)
					f[i+1][x + row[i+1]] += f[i][x];
				}
				//cout << "**" << i <<" : "<< f[i][1]<<endl;
				//cout<<"f[n-1,1] = "<<f[n-1][1]<<endl;
			}
			for (int i=0;i<SUM;++i)
				ans[i]+=f[n-1][i];
			//cout<<mask <<" : " << f[n-1][1]<<endl;
		}
		//for (int i = 0 ; i < SUM;++i)
		//	cout<< ans [i] <<endl;
		double E = 0;
		for (int i = 0 ; i < SUM;++i)
			E+=ans[i] * double(SUM)/double(SUM-i);
		return E;
	}
	double expectedSteps(vector <string> prob) {
		n = prob.size();
		m = prob[0].size();
		for (int i = 0;i < n; ++i)
			for (int j = 0;j < m;++j)
			if (n >= m)
				data[i][j] = prob[i][j] - '0';
			else
				data[j][i] = prob[i][j] - '0';
		if (n < m) swap(n,m);
		SUM = 0;
		for (int i= 0 ; i< n;++i)
			for (int j = 0;j<m;++j)
				SUM +=data[i][j];
		return DP();
	}
};
