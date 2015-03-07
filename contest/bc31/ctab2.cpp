#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
#define LL __int64
const int MOD=1000000007;
int ans[20][20];
int a[1<<16],cnt;
int tab[16][16]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,
	0,3,5,11,21,43,85,171,341,683,1365,2731,5461,10923,21845,43691,
	0,5,11,35,93,269,747,2115,5933,16717,47003,132291,372157,1047181,2946251,8289731,
	0,8,21,93,314,1213,4375,16334,59925,221799,817280,3018301,11134189,41096528,151643937,559640289,
	0,13,43,269,1213,6427,31387,159651,795611,4005785,20064827,100764343,505375405,536323131,724854929,851706016,
	0,21,85,747,4375,31387,202841,1382259,9167119,61643709,411595537,758179825,448963343,518352198,573271375,716227365,
	0,34,171,2115,16334,159651,1382259,12727570,113555791,29574624,258357071,605623228,361549414,928674293,295065969,684522478,
	0,55,341,5933,59925,795611,9167119,113555791,355115594,484061657,549328511,674425392,431913718,978012348,363063206,414679411,
	0,89,683,16717,221799,4005785,61643709,29574624,484061657,718817248,59031385,435203892,656660707,535833237,722768584,996059054,
	0,144,1365,47003,817280,20064827,411595537,258357071,549328511,59031385,789281595,298546930,255096739,647678030,196785642,770981649,
	0,233,2731,132291,3018301,100764343,758179825,605623228,674425392,435203892,298546930,245046738,624310766,911493467,712203752,78449372,
	0,377,5461,372157,11134189,505375405,448963343,361549414,431913718,656660707,255096739,624310766,681555006,234007277,697537938,825144798,
	0,610,10923,1047181,41096528,536323131,518352198,928674293,978012348,535833237,647678030,911493467,234007277,413451720,247090622,766966594,
	0,987,21845,2946251,151643937,724854929,573271375,295065969,363063206,722768584,196785642,712203752,697537938,247090622,571703274,855055410,
	0,1597,43691,8289731,559640289,851706016,716227365,684522478,414679411,996059054,770981649,78449372,825144798,766966594,855055410,7017421,
};
bool ok(int x,int b){
	int cnt=0;
	while(x>0){
		if(x & 1) ++cnt;
		x/=2;
	}
	return (cnt==b);
}
//��ͨ
LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
void print(int x){
	while(x>0){
		cout<<((x&1)==0?0 : 1);
		x/=2;
	}
	cout<<endl;
}
map< pair<pair<int,int>,int >,int> mp;
LL p[20];
LL gao(int x,int y,int L,int b){
	int X=x,Y=y;
	////cout<<x<<' '<<y<<' '<<L<<' '<<mp[make_pair(make_pair(x,y),L)]<<endl;
	//if(x==y && mp[make_pair(make_pair(x,y),L)]!=0) return 0;
	
	int C[20],R[20],cc=0,cr=0;
	memset(C,0,sizeof(C));
	memset(R,0,sizeof(R));
	int l=0,r=0;
	while(x>0){
		++r;
		if(x & 1){
			if(r-l-1) C[r-l-1]++;
			//if(r-l-1) C[cc++]=r-l-1;
			l=r;
		}
		x/=2;
	}
	r=L+1;
	if(r-l-1) C[r-l-1]++;

	int tmp=0,rec=0,pp;
	for(int i=1;i<=15;++i){
		for(int j=0;j<C[i];++j){
			//cout<<i<<endl;
			pp=(1<<(rec+i));
			rec+=i+1;
			tmp |= pp;
		}
	}
	//tmp ^= pp;
	x=tmp;
	//print(x);

	l=r=0;
	while(y>0){
		++r;
		if(y & 1){
			if(r-l-1) R[r-l-1]++;
			//if(r-l-1) R[cr++]=r-l-1;
			l=r;
		}
		y/=2;
	}
	r=L+1;
	if(r-l-1) R[r-l-1]++;

	tmp=0,rec=0;
	for(int i=1;i<=15;++i){
		for(int j=0;j<R[i];++j){
			//cout<<i<<endl;
			pp=(1<<(rec+i));
			rec+=i+1;
			tmp |= pp;
		}
	}
	//tmp ^= pp;
	y=tmp;
	//print(y);
	
	if(x>y) swap(x,y);
	tmp=mp[make_pair(make_pair(x,y),L)];
	if(tmp) return tmp;

	LL ret=1;
	for(int i=0;i<=15;++i)
		for(int j=0;j<=15;++j){
			if(C[i] && R[j] && tab[i][j]){
				ret=ret*a_b_MOD_c((LL)tab[i][j],(LL)C[i]*R[j],(LL)MOD)%MOD;
			}
		}
	ret=ret*p[b]%MOD;
	mp[make_pair(make_pair(x,y),L)]=ret;
	//cout<<x<<' '<<y<<' '<<L<<' '<<mp[make_pair(make_pair(x,y),L)]<<endl;
	return ret;
}
int tt[]={3,5,6,9,10,12};
int main(){
	p[0]=1;
	for(int i=1;i<=15;++i){
		p[i]=p[i-1]*i%MOD;
	}
	//gao(13,1,5,2);
	//LL sum=0;
	//LL tmp;
	//for(int i=0;i<6;++i){
	//	for(int j=0;j<6;++j){
	//		cout<<tt[i]<<' '<<tt[j]<<endl;
	//		tmp=gao(tt[i],tt[j],4,2);
	//		cout<<tmp<<endl;
	//		sum=(sum+tmp)%MOD;
	//	}
	//}
	//cout<<sum<<endl;
	//LL sum=0;
	//LL tmp;
	//for(int i=0;i<2;++i){
	//	for(int j=0;j<2;++j){
	//		cout<<tt[i]<<' '<<tt[j]<<endl;
	//		tmp=gao(tt[i],tt[j],4,2);
	//		cout<<tmp<<endl;
	//		sum=(sum+tmp)%MOD;
	//	}
	//}
	//sum=sum*4%MOD;
	//for(int i=0;i<6;++i){
	//	if(i!=2) sum=(sum+gao(6,tt[i],4,2)*2)%MOD;
	//	else sum=(sum+gao(6,6,4,2))%MOD;
	//}
	//for(int i=0;i<6;++i){
	//	if(i!=2 && i!=3) sum=(sum+gao(9,tt[i],4,2)*2)%MOD;
	//	else if(i==3) sum=(sum+gao(9,9,4,2))%MOD;
	//}
	//cout<<sum<<endl;
	//cout<<gao(0,0,2,0)<<endl;
	for(int i=1;i<=15;++i){
		for(int j=0;j<=15;++j){
			mp.clear();
			if(j>i){ cout<<"0,"; continue; }
			cnt=0;
			for(int k=0;k<(1<<i);++k)
				if(ok(k,j)) a[cnt++]=k;
			//if(i==1 && j==1){
			//	cout<<endl;
			//	for(int i=0;i<cnt;++i)
			//		cout<<a[i]<<' ';
			//	cout<<endl;
			//}
			LL sum=0;
			for(int k=0;k<cnt;++k)
				for(int l=0;l<cnt;++l)
					sum=(sum+gao(a[k],a[l],i,j))%MOD;
			////int lim=(cnt+1)/2-1;
			//int lim;
			//if(cnt&1) lim=cnt/2;
			//else lim=cnt/2-1;
			//for(int k=0;k<lim;++k)
			//	for(int l=0;l<lim;++l)
			//		sum=(sum+gao(a[k],a[l],i,j))%MOD;
			//sum=sum*4%MOD;
			//int p=lim;
			//for(int k=0;k<cnt;++k){
			//	if(k!=p) sum=(sum+gao(a[p],a[k],i,j)*2)%MOD;
			//	else sum=(sum+gao(a[p],a[k],i,j))%MOD;
			//}
			//if((cnt&1)==0){
			//	p=lim+1;
			//	for(int k=0;k<cnt;++k){
			//		if(k!=lim && k!=p) sum=(sum+gao(a[p],a[k],i,j)*2)%MOD;
			//		else if(k==p) sum=(sum+gao(a[p],a[k],i,j))%MOD;
			//	}
			//}
			
			//ans[i][j]=sum;
			cerr<<i<<' '<<j<<endl;
			cout<<sum<<',';
		}
		cout<<endl;
	}
}
