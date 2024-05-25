class Solution {
public:
    void bubbleSort(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n; i += 1) {
            bool swapped = false;
            for (int j = 0; j < n - 1; j += 1) {
                if (v[j] > v[j + 1]) {
                    swap(v[j], v[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }

    void selectionSort(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n - 1; i += 1) {
            int min_idx = i;
            for (int j = i + 1; j < n; j += 1) {
                if (v[min_idx] > v[j]) {
                    min_idx = j;
                }
            }
            swap(v[i], v[min_idx]);
        }
    }

    void insertionSort(vector<int>& v) {
        for (int i = 1; i < v.size(); i += 1) {
            int key = v[i];
            int j = i - 1;
            while (v[j] > key && j >= 0) {
                v[j + 1] = v[j];
                j -= 1;
            }
            v[j + 1] = key;
        }
    }

    void merge(vector<int>& v, int left, int mid, int right) {
        int l = mid - left + 1;
        int r = right - mid;

        vector<int> le(l), re(r);

        for (int i = 0; i < l; i += 1) {
            le[i] = v[left + i];
        }
        for (int j = 0; j < r; j += 1) {
            re[j] = v[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < l && j < r) {
            if (le[i] <= re[j]) {
                v[k] = le[i];
                i += 1;
            } else {
                v[k] = re[j];
                j += 1;
            }
            k += 1;
        }

        while (i < l) {
            v[k] = le[i];
            i += 1;
            k += 1;
        }
        while (j < r) {
            v[k] = re[j];
            j += 1;
            k += 1;
        }
    }
    void mergeSort(vector<int>& v, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(v, left, mid);
            mergeSort(v, mid + 1, right);

            merge(v, left, mid, right);
        }
    }

    int partition(vector<int>& v, int left, int right) {
        int pivot = v[right];
        int i = left - 1;
        for (int j = left; j < right; j += 1) {
            if (v[j] < pivot) {
                i += 1;
                swap(v[i], v[j]);
            }
        }

        swap(v[i + 1], v[right]);

        return i + 1;
    }
    void quickSort(vector<int>& v, int left, int right) {
        if (left < right) {
            int pivot = partition(v, left, right);

            quickSort(v, left, pivot - 1);
            quickSort(v, pivot + 1, right);
        }
    }

    void countingSort(vector<int>& v) {
        int maxele = v[0];
        for (int i = 1; i < v.size(); i += 1) {
            maxele = max(maxele, v[i]);
        }
        vector<int> output(maxele + 1), count(maxele + 1);

        for (int i = 0; i < v.size(); i += 1) {
            count[v[i]] += 1;
        }

        for (int i = 1; i < count.size(); i += 1) {
            count[i] = count[i] + count[i - 1];
        }

        for (int i = 0; i <v.size() ; i+=1) {
            output[count[v[i]] - 1] = v[i];
            count[v[i]]-=1;
        }

        for (int i = 0; i < v.size(); i += 1) {
            v[i] = output[i];
        }
    }



    vector<int> sortArray(vector<int>& nums) {
        // 1. Bubble Sort
        //  bubbleSort(nums);

        // 2. Selection Sort
        //  selectionSort(nums);

        // 3. Insertion Sort
        //  insertionSort(nums);

        // 4. Merge Sort
        mergeSort(nums, 0, nums.size()-1);

        // 5. Quick Sort
        //   quickSort(nums, 0, nums.size()-1);

        // 6. Counting Sort
        //  countingSort(nums);

        //7. Heap Sort
        return nums;
    }
};