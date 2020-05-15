#include <iostream>
#include "DynamicArray.hpp"
#include "List.hpp"


#define info(msg) std::cout << (#msg) << " = " << (msg) <<  std::endl;
#define print(msg) std::cout << (#msg) << std::endl;


int main() {
    size_t size = 3;
    DynamicArray<int> darr(size);
    DynamicArray<int> darr2 = darr;
    DynamicArray<int> darr3(20);

    darr[0] = 184;
    darr[1] = 231;
    darr[2] = 334;

    //List<int> list1;
    int *ptr = new int[4];
    ptr[0] = 32;
    ptr[1] = 43;
    ptr[2] = 438;
    ptr[3] = 892;
    print(first);
    List<int> list1(ptr, 4);
    print(second);
    List<int> list2 = list1;
    print(third);
    info(list2.GetElementData(0));
    info(list2.GetElementData(1));
    info(list2.GetElementData(2));
    info(list2.GetElementData(3));

    print("*******");
    list2.InsertAt(1, 348);
    list2.Append(8920);
    list2.Prepend(-2323);

    info(list2.GetElementData(0));
    info(list2.GetElementData(1));
    info(list2.GetElementData(2));
    info(list2.GetElementData(3));
    info(list2.GetElementData(4));
    info(list2.GetElementData(5));
    info(list2.GetElementData(6));
    info(list2.GetSize());
    //info(list2.GetElementData(7));

//    List<int> *list3 = list2.GetSubList(2, 4);
//    info(list3->GetElementData(0));
//    info(list3->GetElementData(1));

    return 0;
}
