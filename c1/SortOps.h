#ifndef SORTOPS_H
#define SORTOPS_H

#include <cstdint>
#include <vector>

class SortOps
{
    // Data
    private:
    public:
    // Methods
    private:
        void swap(int* a, int* b);
        uint64_t Partition(int* arr, uint64_t low, uint64_t high);
    public:
        ~SortOps();
        void  quickSort(int* arr, uint64_t low, uint64_t high);
};

#endif