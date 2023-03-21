#include <iostream>
#include "common.h"

int main() {
    int numOfCustomers;
    numOfCustomers = common::getNumInput<int>("Enter the number of customers for the day",
                                              [](int input) { return input >= 0; });

    for (int i = 0; i < numOfCustomers; i++) {

    }
    return 0;
}
