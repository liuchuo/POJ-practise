POJ-2488 A Knights Journey-深度优先搜索
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 37974        Accepted: 12896
Description

Background 
The knight is getting bored of seeing the same black and white squares again and again and has decided to make a journey 
around the world. Whenever a knight moves, it is two squares in one direction and one square perpendicular to this. The world of a knight is the chessboard he is living on. Our knight lives on a chessboard that has a smaller area than a regular 8 * 8 board, but it is still rectangular. Can you help this adventurous knight to make travel plans? 

Problem 
Find a path such that the knight visits every square once. The knight can start and end on any square of the board.
Input

The input begins with a positive integer n in the first line. The following lines contain n test cases. Each test case consists of a single line with two positive integers p and q, such that 1 <= p * q <= 26. This represents a p * q chessboard, where p describes how many different square numbers 1, . . . , p exist, q describes how many different square letters exist. These are the first q letters of the Latin alphabet: A, . . .
Output

The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print a single line containing the lexicographically first path that visits all squares of the chessboard with knight moves followed by an empty line. The path should be given on a single line by concatenating the names of the visited squares. Each square name consists of a capital letter followed by a number. 
If no such path exist, you should output impossible on a single line.
Sample Input

3
1 1
2 3
4 3
Sample Output

Scenario #1:
A1

Scenario #2:
impossible

Scenario #3:
A1B3C1A2B4C2A3B1C3A4B2C4
Source

TUD Programming Contest 2005, Darmstadt, Germany


#include <iostream>
using namespace std;
int next1[8][2]={
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1}
};   //记录方向
int a, b, flag;
int book[26][26], path[26][2];
void dfs(int i, int j, int k) {
    if (k == a * b) {
        for (int t = 0; t < k; t++) {
            printf("%c", path[t][0] + 'A');
            cout << path[t][1]+1;
        }
        cout << endl;
        flag = 1;
    } else {
        for (int t = 0; t < 8; t++) {
            int n = i + next1[t][0];
            int m = j + next1[t][1];
            if (n >= 0 && n < b && m >= 0 && m < a && book[n][m] == 0 && flag == 0) {
                book[n][m] = 1;
                path[k][0] = n;
                path[k][1] = m;
                dfs(n, m, k + 1);
                book[n][m] = 0;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int m = 0; m < N; m++) {
        flag = 0;
        cin >> a >> b;
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                book[i][j] = 0;
        book[0][0] = 1;
        path[0][0] = 0,path[0][1] = 0;
        cout << "Scenario #" << m + 1 << ":" << endl;
        dfs(0, 0, 1);
        if (!flag)
            cout << "impossible" << endl;
        cout << endl;
    }
    return 0;
}