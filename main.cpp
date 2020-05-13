#include <iostream>
#include "DynamicArray.hpp"
#include "List.hpp"


#define info(msg) std::cout << (#msg) << " = " << (msg) <<  std::endl;


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
    List<int> list2(ptr, 4);
    info(list2.head_->data_);
    info(list2.head_->next_->data_);

    info(list2.head_->next_->next_->data_);
    info(list2.head_->next_->next_->next_->data_);
    //info(list2.head_->next_->next_->next_->next_->data_);

    List<int> list3 = list2;
    info(list3.head_->data_);
    info(list3.head_->next_->data_);

    info(list3.head_->next_->next_->data_);
    info(list3.head_->next_->next_->next_->data_);
    //info(list3.head_->next_->next_->next_->next_->data_);
    return 0;
}
