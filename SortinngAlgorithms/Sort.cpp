#include<iostream>
#include"Sort.h"
#include"../utils.h"


template<typename T>
void Sort<T>::QuickSort(T arr[], uint32_t size, SortingType_t SortingType )
{
    Helper_QuickSort(arr ,  0 , size-1 , SortingType);
}
template<typename T>
void Sort<T>::Helper_QuickSort(T Array[] , uint32_t Fisrt_Idx , uint32_t Last_Idx , SortingType_t SortingType)
{

    uint32_t Pivot_idx    = Fisrt_Idx ;
    uint32_t Iterator     = 0 ;
    uint32_t Start_Idx    = Fisrt_Idx ;
    uint32_t End_Idx      = Last_Idx ; 
    uint8_t  Pivot_State  = PIVOT_AT_LEFT ; 

    /* Base case for recursion :
      --> Array has one element  
    */
    if(Fisrt_Idx >= Last_Idx ){
      return ;
    }

    for(Iterator=Fisrt_Idx ; Iterator <Last_Idx ; Iterator++){

        if(SortingType == SortingType_t::ASCENDING){

            if(Pivot_State  == PIVOT_AT_LEFT && Array[Pivot_idx]>Array[End_Idx] ){
                Swap(Array[Pivot_idx], Array[End_Idx]);
                Start_Idx++ ; 
                Pivot_idx = End_Idx ; 
                Pivot_State  = PIVOT_AT_RIGHT;

            }else if(Pivot_State  == PIVOT_AT_RIGHT && Array[Start_Idx]>Array[Pivot_idx] ){
                Swap(Array[Start_Idx],Array[End_Idx]);
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
            
            if(Pivot_State  == PIVOT_AT_LEFT && Array[Pivot_idx] < Array[End_Idx] ){
                Swap(Array[Pivot_idx], Array[End_Idx]);
                Start_Idx++ ; 
                Pivot_idx = End_Idx ; 
                Pivot_State  = PIVOT_AT_RIGHT;

            }else if(Pivot_State  == PIVOT_AT_RIGHT && Array[Start_Idx] < Array[Pivot_idx] ){
                Swap(Array[Start_Idx],Array[End_Idx]);
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
    Helper_QuickSort(Array , Fisrt_Idx   , Pivot_idx-1 , SortingType);    //Pass Left  Sup Array of Pivot to Quick Sort fun
    Helper_QuickSort(Array , Pivot_idx+1 , Last_Idx    , SortingType );   //Pass Right Sup Array of Pivot  to Quick Sort fun
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
template<typename T>
void Sort<T>::Swap(T& First,T& Second)
{
    First  = First + Second;
    Second = First - Second;
    First  = First - Second;
}

INSTANTIATE_CLASS_TEMPLATES(Sort);