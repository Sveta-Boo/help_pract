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