未整理：
grundy数
bc16 c 异或和为0的问题
树上一个点到另外一个点的最大距离
斯坦纳树 未整理到模板
10^6 局部暴力
bc21 b
bc21 d
cf280 e
poj 1149
java modpow
cf 279 d 对数字进行奇怪的分解
斯坦纳树
矩阵旋转
poj 1284
反序拓扑
hdu 5165

注意事项：
多用递归的想法
图论问题 trick 1.图不连通 2.重边 3.自环
写<='9'时要小心
思维导图
分块
for(int i=1;i<=1000000;++i){
	for(int j=2;j*i<2000000;++j){
	}
}	//其复杂度只有2*10^7	ok
如果涉及01二进制问题可以考虑字典树或者高斯消元可不可以gao
无序图用并查集判环，有序图用拓扑判环，深搜判环会超时。
输出十分奇怪是，请看看是不是把整型的值设成char 或者 bool 类型了
括号匹配问题一般用栈做
以后注意给出余数的时候，要注意它是不是负的 
用usigned 类型的时候注意减法是不会有负数的
wa的时候多看看边缘数据
用INF时，要留心是否有值会比INF还大。
离线取区间最大最小值时，最好别用线段树
map count 是数有多少个key值
矩阵快速幂错误时，看看别的地方没有错，有可能就是矩阵构造问题了，如果题目有重复元素的话，矩阵元素不一定是1。
re 不外乎3个原因：最大越界，最小越界，爆栈
模除的时候结果出现负数，很有可能是因为没有(a+MOD)%MOD
要常常想到二分答案
