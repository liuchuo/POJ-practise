POJ 3278-Catch That Cow-广度优先搜索BFS
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 67866		Accepted: 21376
Description

Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. Farmer John has two modes of transportation: walking and teleporting.

* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute.

If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?

Input

Line 1: Two space-separated integers: N and K
Output

Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.
Sample Input

5 17
Sample Output

4
Hint

The fastest way for Farmer John to reach the fugitive cow is to move along the following path: 5-10-9-18-17, which takes 4 minutes.

#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
#define MAX 100005

queue<int> q;
int step[MAX];
bool visit[MAX];
int n, k;
int head, tail;

int bfs() {
	q.push(n);
	step[n] = 0;
	visit[n] = 1;
	while (!q.empty()) {
		head = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			if(i == 0)
				tail = head - 1;
			else if (i == 1)
				tail = head + 1;
			else
				tail = head * 2;
			if (tail > MAX || tail < 0)
				continue;
			if (!visit[tail]) {
				q.push(tail);
				step[tail] = step[head] + 1;
				visit[tail] = 1;
			}
			if(tail == k)
				return step[tail];
		}
	}
	return -1;
}
int main() {
	memset(visit, 0, sizeof(visit));
	cin >> n >> k;
	if (n > k) {
		cout << n - k;
	} else {
		cout << bfs();
	}
	return 0;
}