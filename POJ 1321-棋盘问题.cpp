POJ 1321-棋盘问题-简单搜索DFS
Description

在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
Input

输入含有多组测试数据。 
每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n 
当为-1 -1时表示输入结束。 
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。 
Output

对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
Sample Input

2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1
Sample Output

2
1

#include <iostream>
using namespace std;
int col[10];
char pic[8][8];
int cou = 0;
int n, k;
void dfs(int begin, int num) {
    for (int j = 0; j < n; j++) {
        if (pic[begin][j] == '#' && col[j] == 0) {
            if (num == 1) {
                cou++;
            } else {
                col[j] = 1;
                for (int h = begin + 1; h <= n - num + 1; h++) {
                    dfs(h, num - 1);
                }
                col[j] = 0;
            }
        }
    }
}

int main() {
    while ((cin >> n >> k) && !(n == -1 && k == -1)) {
        cou = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> pic[i][j];
            }
        }
        for (int i = 0; i <= n - k; i++) {
            dfs(i, k);
        }
        cout << cou << endl;
    }
    return 0;
}