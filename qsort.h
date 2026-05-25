#pragma once
template <class T>
void qsort(T* arr, int left, int right) {
	int k = (left + right) / 2;
	T x = arr[k];
	int i = left;
	int j = right;
	do {
		while (i < right && x>arr[i])i++;
		while (j > left && arr[j] > x)j--;
		if (i <= j) {
			T h = arr[i];
			arr[i] = arr[j];
			arr[j] = h;
			i++;
			j--;
		}
	} while (i < j);

	if (left < j) qsort(arr, left, 1);
	if (right > i) qsort(arr, i, right);
}