#include<iostream>
#include"Sort.h"
#include"../utils.h"
/* Quick Sort Implementaion */
template<typename T>
void Sort<T>::QuickSort(T Arr[], uint32_t size, SortingType_t SortingType )
{
    Helper_QuickSort(Arr , 0 , size-1 , SortingType );
}
template<typename T>
void Sort<T>:: Helper_QuickSort(T Arr[] , int32_t Fisrt_Idx , int32_t Last_Idx , SortingType_t SortingType)
{
    // Base case
    if(Fisrt_Idx >= Last_Idx ){
        return;
    }

    uint32_t Pivot_Idx = Helper_Partition(Arr ,  Fisrt_Idx ,  Last_Idx ,  SortingType);
    Helper_QuickSort(Arr , Fisrt_Idx , Pivot_Idx-1 , SortingType);
    Helper_QuickSort(Arr , Pivot_Idx+1 , Last_Idx , SortingType);
}
template<typename T>
 uint32_t Sort<T>:: Helper_Partition(T Arr[] ,  int32_t Fisrt_Idx , int32_t Last_Idx , SortingType_t SortingType)
{
    T Pivot = Arr[Last_Idx];
    int32_t _1stIterator = (Fisrt_Idx-1);
    int32_t _2ndtIterator;
    for(_2ndtIterator = Fisrt_Idx ; _2ndtIterator < Last_Idx ; _2ndtIterator++ ){
        if(SortingType == SortingType_t::ASCENDING){
            if(Arr[_2ndtIterator] <= Pivot){
                _1stIterator++;
                Swap(& Arr[_1stIterator], &Arr[_2ndtIterator]);
            }
        }else if(SortingType == SortingType_t::DESCENDING){
            if(Arr[_2ndtIterator] >= Pivot){
                _1stIterator++;
                Swap(& Arr[_1stIterator], &Arr[_2ndtIterator]);
            }
        }
    }
    Swap(&Arr[_1stIterator+1],&Arr[Last_Idx]);
    //return Pivot index 
    return (_1stIterator+1);
}

template<typename T>
void Sort<T>::MergSort(T Arr[] , uint32_t size , SortingType_t SortingType)
{
    if(size<=1){
        return;
    }
    MergSortSubArrays<T> LocSubArrys;
    uint32_t Mid = size/2 ; 
    uint32_t _1stIrerator=0 ;
    uint32_t _2ndIrerator=0 ;

    LocSubArrys._pRightdArr = new T[Mid];
    LocSubArrys._pLeftArr   = new T[size - Mid];

    for(_1stIrerator=0 ; _1stIrerator < size-Mid ;  _1stIrerator++){
        LocSubArrys._pLeftArr[_1stIrerator] = Arr[_2ndIrerator++];
    }
    for(_1stIrerator=0 ; _1stIrerator < Mid ;  _1stIrerator++){
        LocSubArrys._pRightdArr[_1stIrerator] = Arr[_2ndIrerator++];
    }

    LocSubArrys._1stArrSize = size - Mid ; 
    LocSubArrys._2ndArrSize = Mid ; 

    MergSort(LocSubArrys._pLeftArr   , size-Mid , SortingType);
    MergSort(LocSubArrys._pRightdArr , Mid      , SortingType);

    Helper_MergSort(LocSubArrys , Arr, size , SortingType);
    delete []LocSubArrys._pRightdArr;
    delete []LocSubArrys._pLeftArr;
} 
template<typename  T>
void Sort<T>:: Helper_MergSort (MergSortSubArrays<T> SubArrays ,  T SortedArr[] ,  uint32_t size , SortingType_t SortingType)
{
    uint32_t _1stIrerator=0 ;
    uint32_t _2ndIrerator=0 ; 
    uint32_t _3rdIrerator=0 ; 

    while (_1stIrerator < SubArrays._1stArrSize &&  _2ndIrerator < SubArrays._2ndArrSize)
    {
        if(SortingType == SortingType_t::ASCENDING){
            if(SubArrays._pLeftArr[_1stIrerator] > SubArrays._pRightdArr[_2ndIrerator] ){
                SortedArr[_3rdIrerator++]=SubArrays._pRightdArr[_2ndIrerator++];

            }else if(SubArrays._pLeftArr[_1stIrerator] <= SubArrays._pRightdArr[_2ndIrerator] ){
                SortedArr[_3rdIrerator++]=SubArrays._pLeftArr[_1stIrerator++];
            }
            
        }else if(SortingType == SortingType_t::DESCENDING){
            if(SubArrays._pLeftArr[_1stIrerator] < SubArrays._pRightdArr[_2ndIrerator] ){
                SortedArr[_3rdIrerator++]=SubArrays._pRightdArr[_2ndIrerator++];

            }else if(SubArrays._pLeftArr[_1stIrerator] >= SubArrays._pRightdArr[_2ndIrerator] ){
                SortedArr[_3rdIrerator++]=SubArrays._pLeftArr[_1stIrerator++];
            }
        }
    }

    while(_1stIrerator < SubArrays._1stArrSize){
        SortedArr[_3rdIrerator++]=SubArrays._pLeftArr[_1stIrerator++];
    }

    while(_2ndIrerator < SubArrays._2ndArrSize){
        SortedArr[_3rdIrerator++]=SubArrays._pRightdArr[_2ndIrerator++];
    }
}
/* QuickSort Old Version */
template<typename T>
void Sort<T>::QuickSort_v1(T Arr[], uint32_t size, SortingType_t SortingType )
{
    Helper_QuickSort_v1(Arr ,  0 , size-1 , SortingType);
}
template<typename T>
void Sort<T>::Helper_QuickSort_v1(T Arr[] , int32_t Fisrt_Idx , int32_t Last_Idx , SortingType_t SortingType)
{

    int32_t Pivot_idx    = Fisrt_Idx ;
    int32_t Iterator     = 0 ;
    int32_t Start_Idx    = Fisrt_Idx ;
    int32_t End_Idx      = Last_Idx ; 
    uint8_t  Pivot_State  = PIVOT_AT_LEFT ; 

    /* Base case for recursion :
      --> Arr has one element  
    */
    if(Fisrt_Idx >= Last_Idx ){
      return ;
    }

    for(Iterator=Fisrt_Idx ; Iterator <Last_Idx ; Iterator++){

        if(SortingType == SortingType_t::ASCENDING){

            if(Pivot_State  == PIVOT_AT_LEFT && Arr[Pivot_idx]>Arr[End_Idx] ){
                Swap(&Arr[Pivot_idx],& Arr[End_Idx]);
                Start_Idx++ ; 
                Pivot_idx = End_Idx ; 
                Pivot_State  = PIVOT_AT_RIGHT;

            }else if(Pivot_State  == PIVOT_AT_RIGHT && Arr[Start_Idx]>Arr[Pivot_idx] ){
                Swap(&Arr[Start_Idx],&Arr[End_Idx]);
                End_Idx-- ; 
                Pivot_idx = Start_Idx ; 
                Pivot_State  = PIVOT_AT_LEFT;

            }else{
              if(Pivot_State  == PIVOT_AT_LEFT ){
                End_Idx-- ; 
              }else if(Pivot_State  == PIVOT_AT_RIGHT ){
                Start_Idx++ ; 
              }
            }
        }else if(SortingType == SortingType_t::DESCENDING){
            
            if(Pivot_State  == PIVOT_AT_LEFT && Arr[Pivot_idx] < Arr[End_Idx] ){
                Swap(&Arr[Pivot_idx], &Arr[End_Idx]);
                Start_Idx++ ; 
                Pivot_idx = End_Idx ; 
                Pivot_State  = PIVOT_AT_RIGHT;

            }else if(Pivot_State  == PIVOT_AT_RIGHT && Arr[Start_Idx] < Arr[Pivot_idx] ){
                Swap(&Arr[Start_Idx],&Arr[End_Idx]);
                End_Idx-- ; 
                Pivot_idx = Start_Idx ; 
                Pivot_State  = PIVOT_AT_LEFT;

            }else{
              if(Pivot_State  == PIVOT_AT_LEFT ){
                End_Idx-- ; 
              }else if(Pivot_State  == PIVOT_AT_RIGHT ){
                Start_Idx++ ; 
              }
            }
        }

    }
    Helper_QuickSort_v1(Arr , Fisrt_Idx   , Pivot_idx-1 , SortingType);    //Pass Left  Sup Arr of Pivot to Quick Sort fun
    Helper_QuickSort_v1(Arr , Pivot_idx+1 , Last_Idx    , SortingType );   //Pass Right Sup Arr of Pivot  to Quick Sort fun
}
template<typename T>
void Sort<T>:: Swap(T *a, T *b) {
  T t = *a;
  *a = *b;
  *b = t;
}
INSTANTIATE_CLASS_TEMPLATES(Sort);

