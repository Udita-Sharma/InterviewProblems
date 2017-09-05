#include<iostream>
using namespace std;

int binarySearch(int *arr, int l, int r, int x)
{
	if (l <= r)
	{
		int mid = (l + (r - 1)) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}

int main()
{
	int arr[] = { 3, 5, 7, 12, 14, 15 };
	int r = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, r, 7);
	if (result != -1)
		cout << "Element present at position " << result+1;
	else
		cout << "element not present";
	return 0;
}