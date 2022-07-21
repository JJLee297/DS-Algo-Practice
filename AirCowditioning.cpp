// USACO December 2021 Bronze Problem 2
// Essentially counts the minimum number of increments/decrements required to reduce a list of numbers to 0, allowing adjacent numbers to share operations
// there is a much faster approach that works after a mathematical proof, and the final answer is just a formula

#include <vector>
#include <iostream>

using namespace std;

bool isLocalMax(vector<int>& bruh, int pos, int N) {
	if (pos > 0 && pos < N)
		return (bruh[pos] > bruh[pos - 1] && bruh[pos] > bruh[pos + 1]);
	else if (pos > 0)
		return (bruh[pos] > bruh[pos - 1]);
	else if (N > 0)
		return (bruh[pos] > bruh[pos + 1]);
	return true;
}

bool isLocalMin(vector<int>& bruh, int pos, int N) {
	if (pos > 0 && pos < N)
		return (bruh[pos] < bruh[pos - 1] && bruh[pos] < bruh[pos + 1]);
	else if (pos > 0)
		return (bruh[pos] < bruh[pos - 1]);
	else if (N > 0)
		return (bruh[pos] < bruh[pos + 1]);
	return true;
}

int calc(vector<int>& bruh, int start, int end) {
	int ret = 0;
	int N = bruh.size() - 1;
	for (int i = start; i < end; ++i) {
		if (isLocalMax(bruh, i, N)) {
			if ((i == start || i == end - 1) && bruh[i] < 0)
				continue;
			ret += bruh[i];
		}
		else if (isLocalMin(bruh, i, N)) {
			if ((i == start || i == end - 1) && bruh[i] > 0)
				continue;
			ret -= bruh[i];
		}
	}
	return abs(ret);
}

class Solution {
public:
	void solve() {
		int N;
		int tot = 0;
		cin >> N;
		vector<int> n(N);
		for (int i = 0; i < N; ++i)
			cin >> n[i];
		for (int i = 0; i < N;++i) {
			int x;
			cin >> x;
			n[i] -= x;
			if (i != 0 && (n[i] == n[i - 1])) {
				n.erase(n.begin() + i - 1);
				i--;
				N--;
			}
		}
		cout <<  calc(n, 0, N) << endl;
	}
};

int main() {
	Solution a;
	a.solve();
}
