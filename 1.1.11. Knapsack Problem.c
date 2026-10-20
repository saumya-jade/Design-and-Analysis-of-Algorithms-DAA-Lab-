#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, w;
	if (scanf("%d", &n) != 1) return 0;
	int *values = (int *)malloc(n * sizeof(int));
	int *weights = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &values[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &weights[i]);
	}
	scanf("%d", &w);
	int *dp = (int *)calloc(w + 1, sizeof(int));
	for (int i = 0; i < n; i++) {
		int val = values[i];
		int wt = weights[i];
		for (int j = w; j >= wt; j--) {
			if (dp[j - wt] + val > dp[j]) {
				dp[j] = dp[j - wt] + val;
			}
		}
	}
	printf("%d\n", dp[w]);
	free(values);
	free(weights);
	free(dp);
	return 0;
}
