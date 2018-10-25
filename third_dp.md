/*
 * 计算第i天之前的最大利润与第i天之后的最大利润
 * 得出第i天的利润最大值
 * 遍历得最终结果
 * 时间复杂度 O(n)
 */

	#include <bits/stdc++.h>
	using namespace std;
	
	const int MAX = 1e5 + 5;
	int arr[MAX];
	int arr_f[MAX],arr_e[MAX];
	int main() {
	    int n; //假设有n天
	    cin >> n;
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    int price = arr[0];
	    for(int i = 1; i < n; i++) {                        //第i天之前
	        price = min(price, arr[i]);
	        arr_f[i] = max(arr_f[i-1],arr[i] - price);
	    }
	    price = arr[n - 1];
	    for(int i = n - 2; i >= 0; i--) {                   //第i天之后
	        price = max(price, arr[i]);
	        arr_e[i] = max(arr_e[i + 1], price - arr[i]);
	    }
	    int maxPro = 0;
	    for(int i = 0; i < n; i++) {
	        maxPro = max(maxPro, arr_f[i] + arr_e[i]);
	    }
	    cout << maxPro << endl;
	    return 0;
	}
