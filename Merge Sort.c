#include <stdio.h>
#include <stdlib.h>

void merge( int arr[], int left, int right, int mid                ) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *l = (int *)malloc(n1 * sizeof(int));
	int *r = (int *)malloc(n2 * sizeof(int));

	for(int i = 0; i < n1; i++)
		l[i] = arr[left + i];
	for(int j=0; j<n2; j++)
		r[j] = arr[mid + 1 +j];
	int i =0, j=0, k= left;
	while(i<n1 && j<n2){
		if(l[i] <= r[j]) {
			arr[k++] = l[i++];

		} else {
			arr[k++] = r[j++];
		}


	}
	while (i < n1) 
		arr[k++] = l[i++];



	while (j < n2) 
		arr[k++] = r[j++];

	free(l);
	free(r);
    
    
    
    
}

void mergeSort( int arr[], int left, int right               ) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, right, mid);
	}
    
    
    
    
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
