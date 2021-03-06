#include<iostream>
#include<cstring>
using namespace std;

const int N = 1000005;
int nxt[N];
char S[N], T[N];
int slen, tlen;
/*
这个模板 字符串是从0开始的
Next数组是从1开始的
*/
void getNext() {
    int j, k;
    j = 0; k = -1; nxt[0] = -1;
    while (j < tlen)
        if (k == -1 || T[j] == T[k])
            nxt[++j] = ++k;
        else
            k = nxt[k];

}
/*
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
*/
int KMP_Index() {
    int i = 0, j = 0;
    while (i < slen && j < tlen) {
        if (j == -1 || S[i] == T[j]) {
            i++; j++;
        }
        else
            j = nxt[j];
    }
    if (j == tlen)
        return i - tlen;
    else
        return -1;
}
/*
返回模式串在主串S中出现的次数
*/
int KMP_Count() {
    int ans = 0;
    int j = 0;
    for (int i = 0; i < slen; i++) {
        while (j > 0 && S[i] != T[j])
            j = nxt[j];
        if (S[i] == T[j])
            j++;
        if (j == tlen) {
            ans++;
            j = nxt[j];
        }
    }
    return ans;
}
int main() {
    int TT;
    cin >> TT;
    while (TT--) {
        cin >> T >> S;
        slen = strlen(S);
        tlen = strlen(T);
        getNext();
        for (int i = 1; i <= tlen; ++i) {
            cout << nxt[i] << ' ';
        }
        cout << endl;
        cout << "模式串T在主串S中首次出现的位置是: " << KMP_Index() << endl;
        cout << "模式串T在主串S中出现的次数为: " << KMP_Count() << endl;
    }
    return 0;
}
/*
1
abcabcabc abc

nxt[1~n]为：
0 0 0 1 2 3 4 5 6
*/
