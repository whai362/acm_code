/*poj 2217 寻找最长公共子串  
   首先解释，DP中的最长公共子序列和此处的最长公共子串区别:
   序列可以是不连续的，但是子串是连续的
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=600005;
int n;
//后缀数组模板
//注意k是全局变量不要乱用
int k;	//用于倍增法求后缀数组的全局变量
int rank[N],tmp[N];
int sa[N*2];
bool cmp_sa(int i,int j){
	if(rank[i]!=rank[j])
		return rank[i]<rank[j];
	else{
		int ri=i+k<=n? rank[i+k]:-1;
		int rj=j+k<=n? rank[j+k]:-1;
		return ri<rj;
	}
}
void build_sa(char *arr,int *sa){
	n=strlen(arr);	//这个只能用n不知道为什么
	for(int i=0;i<=n;++i){
		sa[i]=i;
		rank[i]=i<n?arr[i]:-1;
	}
	for(k=1;k<=n;k<<=1){
		sort(sa,sa+n+1,cmp_sa);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;++i){
			tmp[sa[i]]=tmp[sa[i-1]]+(cmp_sa(sa[i-1],sa[i])?1:0);
		}
		for(int i=0;i<=n;++i){
			rank[i]=tmp[i];
		}
	}
}
int lcp[N*2];
void build_lcp(char *arr,int *sa,int *lcp){
	n=strlen(arr);
	for(int i=0;i<=n;++i) rank[sa[i]]=i;
	int h=0;
	lcp[0]=0; 
	for(int i=0;i<n;++i){
		int j=sa[rank[i]-1];
		if(h>0) --h;
		for(;j+h<n && i+h<n;++h){
			if(arr[j+h]!=arr[i+h]) break;
		}
		lcp[rank[i]-1]=h;
	}
}
char S[N],T[N];
void gao(){
	int len1=strlen(S);
	S[len1]='#';
	S[len1+1]=0;
	strcat(S,T);
	int len2=strlen(S);
	build_sa(S,sa);
	build_lcp(S,sa,lcp);
	for(int i = 0; i <= len2; ++i)
		cout<<sa[i]<<' ';
	cout<<endl;
	for(int i = 0; i <= len2; ++i)
		cout<<lcp[i]<<' ';
	cout<<endl;
	int ans=0;
	for(int i=0;i<len2;++i){
		if((sa[i]<len1)!=(sa[i+1]<len1)){
			ans=max(ans,lcp[i]);
		}
	}
	printf("Nejdelsi spolecny retezec ma delku %d.\n", ans);
}
int main(){
	int TT;
	scanf("%d",&TT);
	getchar();
	while(TT--){
		gets(S);
		gets(T);
		gao();
	}
	return 0;
}
