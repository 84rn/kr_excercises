#include <cstdio>

int binsearch(int x, int v[], int n);

int main(void)
{
	int arr[] = { 2, 4, 6, 7, 9, 29, 45, 46, 49, 50, 51 };

	int x = 29;
	printf("Index of %d -> %d\n", x, binsearch(x, arr, 11));

	x = 129;
	printf("Index of %d -> %d\n", x, binsearch(x, arr, 11));

	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low = 0, high = n - 1;
	int mid = (low + high) / 2;


	/* while the set is not empty, and we haven't found the index */
	while (low < high && v[mid] != x)
	{
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;

		mid = (low + high) / 2;
	}

	if (x == v[mid])
		return mid;
	else
		return -1;
}