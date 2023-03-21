#include <iostream>
#include "common.h"
#include "question3.h"

int main() {
    int numOfCustomers;
    question3::Membership membership;
    numOfCustomers = common::getNumInput<int>("Enter the number of customers for the day",
                                              [](int input) { return input >= 0; });

    for (int i = 0; i < numOfCustomers; i++) {
        membership = question3::getMembership();
        std::cout << "Customer " << i << "'s membership: " << membership << std::endl;
    }
    return 0;
}
