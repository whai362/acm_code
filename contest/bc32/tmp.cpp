bc32 1003 卡特兰数
题意：
我们给出下列递归的合法括号序列的定义：
1. 空序列是合法括号序列
2. 如果s是一个合法括号序列，那么(s)也是合法括号序列
3. 如果a和b是合法括号序列，那么ab也是合法括号序列
4. 没有其它情况是合法括号序列

比如下列括号序列是合法括号序列
(), (()), ()(), ()(())
下列括号序列则不是
(, ), )(, ((), ((()

现在，我们要构造长度为n的合法括号序列，前面的一些括号已经给出，问可以构造出多少合法序列。
限制：
1 <= n <= 1e6
思路：
先求出剩余的左括号a个，右括号b个
然后ans=C(a+b,a)-C(a+b,a-1)

证明：
我们先看看一个卡特兰数的经典模型：

有n个1和m个-1(n>=m)，共n+m个数排成一列，满足对所有0<=k<=n+m的前k个数的部分和Sk >= 0的排列数。(和问题1不同之处在于此处部分和可以为0，这也是更常见的情况) 问题等价为在一个格点阵列中，从(0，0)点走到(n，m)点且不穿过对角线x==y的方法数(可以走到x==y的点)。
把(n，m)点变换到(n+1，m)点，问题变成了问题1。
方法数为：
((n+m+1, m)) - 2*((n+m+1-1, m-1))
或：((n+m+1-1, m)) - ((n+m+1-1, m-1))

我们从后往前看，然后')'就可以当作1，'('可以当作-1，就可以了。
