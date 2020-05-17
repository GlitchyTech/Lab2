#include <iostream>
#include "DynamicArray.hpp"
#include "List.hpp"


int main() {
    size_t size = 3;
    DynamicArray<int> darr(size);
    DynamicArray<int> darr2 = darr;
    DynamicArray<int> darr3(20);
    List<int> list0;
    INFO(list0.GetSize());
    std::cin >> list0;
    INFO(list0.GetSize());
    std::cout << list0;

    darr[0] = 184;
    darr[1] = 231;
    darr[2] = 334;

    //List<int> list1;
    int *ptr = new int[4];
    ptr[0] = 32;
    ptr[1] = 43;
    ptr[2] = 438;
    ptr[3] = 892;
    PRINT("first");
    List<int> list1(ptr, 4);
    PRINT("second");
    List<int> list2 = list1;
    PRINT("third");
    std::cout << list2;

    PRINT("*******");
    list2.InsertAt(1, 348);
    list2.Append(8920);
    list2.Prepend(-2323);

    std::cout << list2;
    INFO(list2.GetSize());
    //info(list2.GetElementData(7));
    PRINT("\n");
    List<int> *list3 = list2.GetSubList(2, 4);
    INFO(list3->GetSize());
    std::cout << *list3;
    std::cout << '\n';
    std::cout << list3;
    std::cout << "\n";
    //INFO(list3->head_->next_->next_ == nullptr);
    //INFO(list3->head_->next_->data_);
    //INFO(list3->GetElementData(2));

    list3->GetElementData(0) = 92482;
    list3->GetElementData(1) = -203;

    PRINT("\n\n testing output of list\n");
    std::cout << list1 << list2 << *list3;

    std::cout << *(list1 + list2);

    return 0;
}
