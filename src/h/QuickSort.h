#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

class QuickSort {
    public: 
        std::vector<int> sort(std::vector<int>& arr, int low, int high);
    
    private:
        int partition(std::vector<int>& arr, int low, int high);
};

#endif // QUICK_SORT_H