#ifndef VE281P1_SORT_HPP
#define VE281P1_SORT_HPP

#include <vector>
#include <stdlib.h>
#include <functional>

template<typename T, typename Compare>
void bubble_sort(std::vector<T> &vector, Compare comp = std::less<T>()) {
    // TODO: implement
    for (int i=(int)vector.size()-2; i>=0; i--) {
        for (int j=0; j<=i; j++) {
            if (comp(vector[j+1],vector[j])) {
                T temp = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = temp;
            }
        }
    }
}

template<typename T, typename Compare>
void insertion_sort(std::vector<T> &vector, Compare comp = std::less<T>()) {
    // TODO: implement
    for (int i=1; i<(int)vector.size(); i++) {
        T temp = vector[i];
        int j = i-1;
        while (comp(temp,vector[j])) {
            vector[j+1] = vector[j];
            j--;
            if (j<0) break;
        }
        vector[j+1] = temp;
    }
}

template<typename T, typename Compare>
void selection_sort(std::vector<T> &vector, Compare comp = std::less<T>()) {
    // TODO: implement
    for (int i=0; i<(int)vector.size()-1; i++) {
        T min = vector[i];
        int min_index = i;
        for (int j=i; j<(int)vector.size(); j++) {
            if (comp(vector[j],min)) {
                min = vector[j];
                min_index = j;
            }
        }
        vector[min_index] = vector[i];
        vector[i] = min;
    }
}

template<typename T, typename Compare>
void merge(std::vector<T> &vector, int left, int mid, int right, Compare comp = std::less<T>()) {
    std::vector<T> temp = vector;
    int i = left; 
    int j = mid + 1;
    int k = left;
    while (i<=mid && j<=right) {
        if (!comp(vector[j], vector[i])) temp[k++] = vector[i++];
        else temp[k++] = vector[j++];
    }
    if (i>mid) {
        while (j<=right) {
            temp[k++] = vector[j++];
        }
    } else {
        while (i<=mid) {
            temp[k++] = vector[i++];
        }
    }
    vector = temp;
}

template<typename T, typename Compare>
void merge_helper(std::vector<T> &vector, int left, int right, Compare comp = std::less<T>()) {
    if (left>=right) return;
    int mid = (left+right)/2;
    merge_helper<T>(vector, left, mid, comp);
    merge_helper<T>(vector, mid+1, right, comp);
    merge<T>(vector, left, mid, right, comp);
}

template<typename T, typename Compare>
void merge_sort(std::vector<T> &vector, Compare comp = std::less<T>()) {
    // TODO: implement
    merge_helper<T>(vector, 0, (int)vector.size()-1, comp);
}

template<typename T, typename Compare>
int partition_extra(std::vector<T> &vector, int left, int right, Compare comp = std::less<T>()) {
    std::vector<T> temp = vector;
    int i = left, j = right;
    for (int k=left+1; k<=right; k++) {
        if (comp(vector[k],vector[left])) {
            temp[i++] = vector[k];
        } else {
            temp[j--] = vector[k];
        }
    }
    temp[i] = vector[left];
    vector = temp;
    return i;
}

template<typename T, typename Compare>
int partition_in_place(std::vector<T> &vector, int left, int right, Compare comp = std::less<T>()) {
    int i = left + 1, j = right;
    while (true) {
        while (comp(vector[i], vector[left])&&i<right) {
            i++;
        }
        while ((!comp(vector[j], vector[left]))&&j>left) {
            j--;
        }
        if (i<j) {
            T temp = vector[i];
            vector[i] = vector[j];
            vector[j] = temp;
        } else break;
    }
    T temp = vector[left];
    vector[left] = vector[j];
    vector[j] = temp;
    return j;
}

template<typename T, typename Compare>
void quick_sort_helper(std::vector<T> &vector, int left, int right, int (*partition)(std::vector<T> &vector, int left, int right, Compare comp), Compare comp = std::less<T>()) {
    int pivotat;
    if (left>=right) return;
    pivotat = partition(vector, left, right, comp);
    quick_sort_helper(vector, left, pivotat-1, partition, comp);
    quick_sort_helper(vector, pivotat+1, right, partition, comp);
}

template<typename T, typename Compare>
void quick_sort_extra(std::vector<T> &vector, Compare comp = std::less<T>()) {
    // TODO: implement
    quick_sort_helper<T>(vector, 0, (int)vector.size()-1, partition_extra<T>, comp);
}
template<typename T, typename Compare>
void quick_sort_inplace(std::vector<T> &vector, Compare comp = std::less<T>()) {
    // TODO: implement
    quick_sort_helper<T>(vector, 0, (int)vector.size()-1, partition_in_place<T>, comp);
}

#endif //VE281P1_SORT_HPP