#ifndef _SORT_H_
#define _SORT_H_

enum SortingType_t{
  ASCENDING,
  DESCENDING
};
template<typename T>
struct MergSortSubArrays{
    T *_pLeftArr;
    T *_pRightdArr;
    uint32_t _1stArrSize;
    uint32_t _2ndArrSize;
}; 

#define PIVOT_AT_RIGHT 1
#define PIVOT_AT_LEFT  2
template<typename T>
class Sort 
{
public:
static void QuickSort(T arr[], uint32_t size,
                        SortingType_t SortingType = SortingType_t::ASCENDING); 
static void MergSort(T Arr[] , uint32_t size , 
                        SortingType_t SortingType = SortingType_t::ASCENDING);                          

private:
static void Helper_QuickSort(T Array[] , uint32_t Fisrt_Idx , uint32_t Last_Idx , SortingType_t SortingType);
static void Helper_MergSort (MergSortSubArrays<T> SubArrays  , T SortedArr[] , uint32_t size ,SortingType_t SortingType );
static void Swap(T& First,T& Second);
};






#endif /* _SORT_H_ */