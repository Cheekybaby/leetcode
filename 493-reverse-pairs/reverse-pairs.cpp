class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size() - 1, count);
        for (auto it : nums) {
            cout << it << " ";
        }
        return count;
    }

private:
    void countPairs(vector<int>& nums, int left, int mid, int right, int& count) {
        int st = mid + 1;
        for (int i = left; i < mid + 1; i += 1) {
            while (st <= right && nums[i] > 2 * (long long)nums[st]) {
                st += 1;
            }
            count += (st - (mid + 1));
        }
    }
    void merge(vector<int>& nums, int left, int mid, int right, int& count) {
        int lsize = mid - left + 1;
        int rsize = right - mid;

        vector<int> l(lsize, 0);
        vector<int> r(rsize, 0);

        for (int i = 0; i < lsize; i += 1) {
            l[i] = nums[left + i];
        }
        for (int i = 0; i < rsize; i += 1) {
            r[i] = nums[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;

        while (i < lsize && j < rsize) {
            if (l[i] <= r[j]) {
                nums[k] = l[i];
                i += 1;
            } else {
                nums[k] = r[j];
                j += 1;
            }
            k += 1;
        }
        while (i < lsize) {
            nums[k] = l[i];
            i += 1;
            k += 1;
        }
        while (j < rsize) {
            nums[k] = r[j];
            j += 1;
            k += 1;
        }
    }
    void mergeSort(vector<int>& nums, int left, int right, int& count) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid, count);
        mergeSort(nums, mid + 1, right, count);

        countPairs(nums, left, mid, right, count);

        merge(nums, left, mid, right, count);
    }
};