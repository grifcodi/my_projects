#include <iostream>

int* sieve (int n, int& ammount) {
        int* arr = new int[n-1];

        for (int i = 0; i < n-1; i++) {
                arr[i] = i+2;
        }

        for (int i = 0; i < n-1; i++) {
                if (arr[i] != 0) {
                        for (int j = (arr[i]*2)-2; j < n; j += arr[i]) arr[j] = 0;
                }
        }

        ammount = 0;
        for (int i = 0; i < n-1; i++) {
                if (arr[i] != 0) {
                        ammount++;
                }
        }

        int* comp_arr = new int[ammount];
        int j = 0;
        for (int i = 0; i < n-1; i++) {
                if (arr[i] != 0) {
                        comp_arr[j++] = arr[i];
                }
        }

        delete[] arr;
        return comp_arr;
}

