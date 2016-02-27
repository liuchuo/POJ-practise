POJ 3126-Prime Path-广度优先搜索bfs
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 15434		Accepted: 8704
Description

The ministers of the cabinet were quite upset by the message from the Chief of Security stating that they would all have to change the four-digit room numbers on their offices. 
— It is a matter of security to change such things every now and then, to keep the enemy in the dark. 
— But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know! 
— I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your office door. 
— No, it’s not that simple. Suppose that I change the first digit to an 8, then the number will read 8033 which is not a prime! 
— I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds. 
— Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime. 

Now, the minister of finance, who had been eavesdropping, intervened. 
— No unnecessary expenditure, please! I happen to know that the price of a digit is one pound. 
— Hmm, in that case I need a computer program to minimize the cost. You do not know some very cheap software gurus, do you? 
— In fact, I do. You see, there is this programming contest going on... Help the prime minister to find the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. Here is a solution in the case above. 
1033
1733
3733
3739
3779
8779
8179
The cost of this solution is 6 pounds. Note that the digit 1 which got pasted over in step 2 can not be reused in the last step – a new 1 must be purchased.
Input

One line with a positive number: the number of test cases (at most 100). Then for each test case, one line with two numbers separated by a blank. Both numbers are four-digit primes (without leading zeros).
Output

One line for each case, either with a number stating the minimal cost or containing the word Impossible.
Sample Input

3
1033 8179
1373 8017
1033 1033
Sample Output

6
7
0

#include <iostream>
#include <cmath> //sqrt()函数

using namespace std;
int a, b;
bool book[15000];//book用来标记该数字有没有使用过,book是标记的意思啦。
struct node {
    int num;
    int step;
};
struct node queue[15000];

bool isprime(int x) {
    if (x == 2 || x == 3)
        return 1;
    else if (x % 2 == 0 || x <= 1)
        return 0;
    else if (x > 3) {
        for (int i = 3; i <= sqrt((double)x); i += 2) {//一开始直接写的sqrt(x),Compile Error 了，查了一下发现sqrt只支持 float double 和 long double 三个原型，果断改成了sqrt((double)x)。不过当然也可以用i * i <= x 啦。
            if (x % i == 0)
                return 0;
        }
    }
    return 1;
}

void bfs() {
    int head = 0;
    int tail = 0;
    queue[tail].num = a;
    queue[tail].step = 0;
    book[a] = true;
    tail++;
    
    while (head < tail) {
        if (queue[head].num == b) {
            cout << queue[head].step << endl;
            return ;
        }
        
        int first = queue[head].num % 10;
        int second = queue[head].num / 10 % 10;
        //个位
        for (int i = 1; i <= 9; i += 2) { //个位数如果是偶数一定是不符合的，所以这里写 i += 2
            int c = queue[head].num / 10 * 10 + i;
            if (!book[c] && isprime(c) && c != queue[head].num) {
                queue[tail].num = c;
                queue[tail].step = queue[head].step + 1;//是在head的step基础上加1啊啊啊啊啊
                book[c] = true;
                tail++;
            }
        }
        
        //十位
        for (int i = 0; i <= 9; i++) {
            int c = queue[head].num / 100 * 100 + i * 10 + first;
            if (!book[c] && isprime(c) && c != queue[head].num) {
                queue[tail].num = c;
                queue[tail].step = queue[head].step + 1;//是在head的step基础上加1啊啊啊啊啊
                book[c] = true;
                tail++;
            }
        }
        
        //百位
        for (int i = 0; i <= 9; i++) {
            int c = queue[head].num / 1000 * 1000 + i * 100 + second * 10 + first;
            if (!book[c] && isprime(c) && c != queue[head].num) {
                queue[tail].num = c;
                queue[tail].step = queue[head].step + 1;//是在head的step基础上加1啊啊啊啊啊
                book[c] = true;
                tail++;
            }
        }
        
        //千位
        for (int i = 1; i <= 9; i++) {
            int c = queue[head].num % 1000 + i * 1000;
            if (!book[c] && isprime(c) && c != queue[head].num) {
                queue[tail].num = c;
                queue[tail].step = queue[head].step + 1;//是在head的step基础上加1啊啊啊啊啊
                book[c] = true;
                tail++;
            }
        }
        head++;
    }
    cout << "Impossible" << endl;
    return ;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        memset(book, false, sizeof(book));
        bfs();
    }
    return 0;
}









