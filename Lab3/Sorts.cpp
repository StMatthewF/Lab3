#include <iostream>
//сортировка вставками
template<typename T, typename Compare>
void IS(T* arr, int low, int high, Compare comp) {
    for (int i = low + 1; i <= high; ++i) {
        T key = std::move(arr[i]);
        int j = i - 1;
        while (j >= low && comp(key, arr[j])) {
            arr[j + 1] = std::move(arr[j]);
            j--;
        }
        arr[j + 1] = std::move(key);
    }
}
//вызов сортировки согласно шаблону в условии ЛР
template<typename T, typename Compare>
void InsertionSort(T* first, T* last, Compare comp) {
    IS(first, 0, last - first - 1, comp);
}
//поиск опорного элемента как медианы трех элементов
template<typename T, typename Compare>
T FindPivot(T* arr, int low, int high, Compare comp) {
    int mid = low + (high - low) / 2;
    if (comp(arr[low], arr[mid])) {
        if (comp(arr[mid], arr[high])) return arr[mid];
        else if (comp(arr[low], arr[high])) return arr[high];
        else return arr[low];
    }
    else {
        if (comp(arr[low], arr[high])) return arr[low];
        else if (comp(arr[mid], arr[high])) return arr[high];
        else return arr[mid];
    }
}
//функция перегруппировки элементов массива по методу Хоара
template<typename T, typename Compare>
int Partition(T* arr, int low, int high, Compare comp) {
    int i = low - 1, j = high + 1;
    T pivot = FindPivot(arr, low, high, comp);
    while (true) {
        // Найти самый левый элемент, больший или равный опорному элементу
        do {
            i++;
        } while (comp(arr[i], pivot));

        // Найти самый правый элемент, меньший или равный опорному элементу
        do {
            j--;
        } while (comp(pivot, arr[j]));

        // Если встретились два указателя
        if (i >= j) return j;

        std::swap(arr[i], arr[j]);
    }
}
//быстрая сортировка
template<typename T, typename Compare>
void QS(T* arr, int low, int high, Compare comp) {
    while (low < high) {
        int pivot = Partition(arr, low, high, comp);
        if (pivot - low < high - pivot) {
            QS(arr, low, pivot, comp);
            low = pivot + 1;
        }
        else {
            QS(arr, pivot + 1, high, comp);
            high = pivot;
        }
    }
}
//вызов сортировки согласно шаблону в условии ЛР
template<typename T, typename Compare>
void QuickSort(T* first, T* last, Compare comp) {
    QS(first, 0, last - first - 1, comp);
}
//улучшенная быстрая сортровка
template<typename T, typename Compare>
void UpdatedQS(T* arr, int low, int high, Compare comp) {
    while (low < high) {
        if (high - low + 1 <= 270) {//пограничное значение (должно быть в пределах 32)
            IS(arr, low, high, comp);
            break;
        }
        else {
            int pivot = Partition(arr, low, high, comp);
            if (pivot - low < high - pivot) {
                QS(arr, low, pivot, comp);
                low = pivot + 1;
            }
            else {
                QS(arr, pivot + 1, high, comp);
                high = pivot;
            }
        }
    }
}
//вызов сортировки согласно шаблону в условии ЛР
template<typename T, typename Compare>
void sort(T* first, T* last, Compare comp) {
    UpdatedQS(first, 0, last - first - 1, comp);
}