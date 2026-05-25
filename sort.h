#pragma once

template <class T>
void boobleSort(T* a, int n) {
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] > a[i]) {
				T k = a[i];
				a[i] = a[i - 1];
				a[i - 1] = k;
				flag = 1;
			}
		}
	}
}
template <class T>
void qsort(T* arr, int left, int right) {
	int k = (left + right) / 2;
	T x = arr[k];
	int i = left;
	int j = right;
	do {
		while (i < right && x>arr[i] )i++;
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
template <class T>
void insert(T* arr, int n) {
	T t;
	for (int i = 1; i < n; i++) {
		t = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > t; j--) {
			arr[j+1] = arr[j];
		}
		arr[j + 1] = t;
	}
}
template <class T>
void select(T* arr, int n) {
	T t;
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		T t = arr[i];
		arr[i] = arr[min];
		arr[min] = t;
	}
}
template <class T>
void shell(T* a, int n) {
	int steps[5] = { 121,40,13,4,1 };
	int j;
	T t;
	for (int k = 0; k < 5; k++) {
		int step = steps[k];
		for (int i = step; i < n; i++) {
			t = a[i];
			for (j = i - step; j >= 0 && t < a[j]; j -= step)a[j + step] = a[j];
			a[j + step] = t;
		}
	}

}
