#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int x,y;
}cow[100001];
inline int readint()
{
    int i=0,f=1;
    char ch;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
    for(;ch>='0' && ch<='9';ch=getchar())
        i=(i<<3)+(i<<1)+ch-'0';
    return i*f;
}
inline bool cmp(const node&a,const node&b)
{
	return a.y<b.y;
}
int main()
{
	auto int n,time=0,l=1,r;
	freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);
	r=n=readint();
	for(int i=1;i<=n;++i) cow[i].x=readint(),cow[i].y=readint();
	sort(cow+1,cow+1+n,cmp);
	while(l<r)
	{
		time=max(time,cow[l].y+cow[r].y);
		if(cow[l].x<cow[r].x)
		{
			cow[r].x-=cow[l].x;
			while(!cow[++l].x);
		}
		else if(cow[l].x==cow[r].x)
		{
			while(!cow[++l].x);
			while(!cow[--r].x);
		}
		else
		{
			cow[l].x-=cow[r].x;
			while(!cow[--r].x);
		}
	}
	if(l==r) time=max(time,cow[l].y+cow[r].y);
	printf("%d\n",time);
	return 0;
}

