#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Job{
	int p,r,d;
	bool operator < (const Job &bj ) const{
		return d>bj.d;
	}
};

struct rcmp{
	bool operator()( const Job &a, const Job &b ){
		return a.r<b.r;
	}
};

struct pcmp{
	bool operator()( const Job &a, const Job &b ){
		return a.p>b.p;
	}
};

int main ()
{
	priority_queue<Job> ready;
	vector<Job> running;
	vector<Job> waiting;
	Job t;
	int T,J,M;
	int i,tp,td,tr,p;
	vector<Job>::iterator it;
	scanf("%d",&T);
	while(T--)
	{
		waiting.clear();
		running.clear();
		while(!ready.empty())ready.pop();
		scanf("%d %d",&J,&M);
		for(i=0;i<J;i++)
		{
			scanf("%d %d %d",&t.p,&t.r,&t.d);
			waiting.push_back(t);
		}
		sort(waiting.begin(),waiting.end(),rcmp());
		p=0;
		tp=td=tr=10000;
		if(!running.empty())tp=min_element(running.begin(),running.end(),pcmp())->p;
		if(!ready.empty())td=ready.top().d;
		if(p<waiting.size())tr=waiting[p].r;
		if(tr<= tp && tr<=td)
		{
			ready.push(waiting[p]);
			p++;
		}
		if(td<=tp && td<=tr)
		{
			it=max_element(running.begin(),running.end());
			if(it->d)
			ready.push(*it);
		}
	}

	return 0;
}