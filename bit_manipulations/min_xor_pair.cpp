#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/* Function to return the minimum XOR values between pairs of numbers */
int minXORPair(vector<int> A) {

	int min_xor = INT_MAX;

	sort(A.begin(), A.end());

	for (int i = 0; i <= A.size() - 1; i++) {
		min_xor = min(min_xor, A[i]^A[i+1]);
	}

	return min_xor;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{
	vector<int> test = {0, 2, 5, 7};
	cout << minXORPair(test) << endl;
	return 0;
}
