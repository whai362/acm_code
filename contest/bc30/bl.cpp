//求n!里包含多少个因子m
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,m;
	long long o=1;
	for(int i=0;i<16;++i){
		o*=7;
	}
	cout<<o<<endl;
	return 0;
}
