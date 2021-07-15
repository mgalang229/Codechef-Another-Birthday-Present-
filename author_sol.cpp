#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		// create another extra array named 'brr' with maximum size of 'n'
		int brr[n];
		for (int i = 0; i < k; i++) {
			int j = 0;
			// store the elements that are connected with the current element being
			// iterated upon having the constant difference of 'k' (index)
			for (int p = i; p < n; p += k) {
				brr[j++] = arr[p];
			}
			// sort this extra array (non-decreasing order)
			sort(brr, brr + j);
			// set the value 'j' to 0
			j = 0;
			// return the sorted elements in their respective positions
			for (int p = i; p < n; p += k) {
				arr[p] = brr[j++];
			}
		}
		// check if the array is sorted (non-decreasing order)
		int flag = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i] < arr[i - 1]) {
				flag = 1;
				break;
			}
		}
		cout << (flag == 0 ? "yes" : "no") << '\n';
	}
	return 0;
}
