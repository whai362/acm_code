题意：
有n个苹果，m个人，要求分给第一个人最多，其他人随意，求有多少种分法。最后结果模1000000007。
限制：
1 <= n,m <= 100000
思路：
母函数，泰勒展开
枚举第一个人分到的苹果，设为u，
剩下的苹果为n-u个，分成m-1份，则有：
生成函数为：
G(x)=(1+x+x^2+...+x^(u-1))^(m-1)
=> G(x)=((1-x^u)/(1-x))^(m-1)
=> G(x)=(1-x^u)^(m-1) / (1-x)^(m-1)
=> G(x)=(1-x^u)^(m-1) * (1-x)^(1-m)	---一式

对于任意二项式，其泰勒展开为：
(1+x)^k = 1 + kx + k(k-1)/2!*x^2 + ... + k(k-1)...(k-n+1)/n!x^k + ... 

对"一式"进行泰勒展开，得到两个多项式相乘，然后对于每个u，就能通过求"一式"的x^(n-u)的系数，求结果。

