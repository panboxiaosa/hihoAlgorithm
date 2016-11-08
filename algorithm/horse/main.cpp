#include <iostream>

using namespace std;



int main()
{
	int m, n, len;
	int l, r, t, b;
	cin >> n >> m >> len >> l >> r >> t >> b;
	int shiftR = (m - r - l) > 0 ? n - r - l : 0;
	int shiftB = (n - b - t) > 0 ? n - b - t : 0;
	l += shiftR;
	r += shiftR;
	t += shiftB;
	b += shiftB;

	int ans = 0;
	for (int i = 1; i < len / 2 && i <= m; i++){
		for (int j = 1; j < len / 2 && j <= n; j++){
			if (2 * (i + j) > len)
				break;
			if (i <= l || j <= t)
				ans = i*j > ans ? i * j : ans;
			else if (i <= r && j <= b)
				ans = (i * j) - (i - l) * (j - t) > ans ? i*j - (i - l) * (j - t) : ans;
			else if (i <= r && j > b && (i + j) * 2 + (i - l) * 2 <= len)
				ans = (i * j) - (b - t) * (i - l) > ans ? (i * j) - (b - t) * (i - l) : ans;
			else if (i > r && j <= b && (i + j) * 2 + (j - t) * 2 <= len)
				ans = (i * j) - (r - l) * (j - t) > ans ? (i * j) - (r - l) * (j - t) : ans;
			else
				ans = i * j - (r - l) * (b - t) > ans ? i * j - (r - l) * (b - t) : ans;
		}
	}
	cout << ans << endl;
	return 0;
}
