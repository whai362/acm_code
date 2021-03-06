/*hdu 5277
  题意：
  给出一个平面图，n个点，m条边，直线边与直线边之间不相交，求最大团的数目。
  限制：
  1 <= n <= 1000
  思路：
  由于平面图，直线边与直线边之间不相交，所以最大团的大小最大为4，m<=3*n-6；
  所以对于答案4，枚举两条边；
  对于答案3，枚举一条边一个点；
 */
#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
#define MP make_pair
const int N=5000;
int fr[N],to[N];
int _set[N/4][N/4];
bool in(int f,int t){
	if(f==t) return false;
	if(f>t) swap(f,t);
	return _set[f][t]!=0;
}
bool ok(int i,int j){
	if(in(fr[i],fr[j]) && in(fr[i],to[j]) && in(to[i],fr[j]) && in(to[i],to[j])) return true;
	return false;
}

bool vis[9000010];
int get_id1(int i,int j){
	int a[4];
	a[0]=fr[i];
	a[1]=to[i];
	a[2]=fr[j];
	a[3]=to[j];
	sort(a,a+4);
	return _set[a[0]][a[1]]*3000+_set[a[2]][a[3]];
}
int four(int m){
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=0;i<m;++i){
		for(int j=i+1;j<m;++j){
			if(ok(i,j)){
				int id=get_id1(i,j);
				if(vis[id]) continue;
				++cnt;
				vis[id]=1;
			}
		}
	}
	return cnt;
}
int get_id(int a,int b,int c){
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	int ret=_set[a][b];
	ret=ret*1000+c;
	return ret;
}
int three(int n,int m){
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j){
			if(fr[j]==i || to[j]==i) continue;
			//cout<<fr[j]<<' '<<i<<endl;
			//cout<<to[j]<<' '<<i<<endl;
			if(in(i,fr[j]) && in(i,to[j])){
				int id=get_id(i,fr[j],to[j]);
				//cout<<id<<endl;
				if(vis[id]) continue;
				++cnt;
				vis[id]=1;
			}
		}
	}
	return cnt;
}
void gao(int n,int m){
	int ans=4;
	int cnt;
	cnt=four(m);
	if(cnt){ printf("%d %d\n",ans,cnt); return ;}
	--ans;
	cnt=three(n,m);
	//cout<<cnt<<endl;
	if(cnt){ printf("%d %d\n",ans,cnt); return ;}
	--ans;
	cnt=m;
	//cout<<cnt<<endl;
	if(cnt){ printf("%d %d\n",ans,cnt); return ;}
	printf("%d %d\n",1,n);
}
int main(){
	int n,m;
	int x,y;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(_set,0,sizeof(_set));
		for(int i=0;i<n;++i){
			scanf("%d%d",&x,&y);
		}
		for(int i=0;i<m;++i){
			scanf("%d%d",&fr[i],&to[i]);
			if(fr[i]>to[i]) swap(fr[i],to[i]);
			_set[fr[i]][to[i]]=i+1;
		}
		gao(n,m);
	}
	return 0;
}
