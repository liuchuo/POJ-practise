POJ 1426-Find The Multiple-深度优先搜索dfs
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 24137        Accepted: 9997      Special Judge
Description

Given a positive integer n, write a program to find out a nonzero multiple m of n whose decimal representation contains only the digits 0 and 1. You may assume that n is not greater than 200 and there is a corresponding m containing no more than 100 decimal digits.
Input

The input file may contain multiple test cases. Each line contains a value of n (1 <= n <= 200). A line containing a zero terminates the input.
Output

For each value of n in the input print a line containing the corresponding value of m. The decimal representation of m must not contain more than 100 digits. If there are multiple solutions for a given value of n, any one of them is acceptable.
Sample Input

2
6
19
0
Sample Output

10
100100100100100100
111111111111111111
#include <iostream>
using namespace std;
int flag;
int n;
void dfs(unsigned long int t,int k) {
    if (flag == 1) 
        return ;
    if (t % n == 0) {
        cout << t << endl;
        flag = 1;
        return ;
    }
    if (k == 19) //到第19层还没找到那就回溯，别找了
        return ;
    dfs(t * 10, k + 1);
    dfs(t * 10 + 1, k + 1);
}
int main() {
    while (cin >> n && n != 0) {
        flag = 0;
        dfs(1, 0);
    }
}