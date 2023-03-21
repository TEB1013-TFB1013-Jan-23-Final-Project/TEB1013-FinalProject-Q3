#include <iostream>
#include "common.h"
#include "question3.h"

int main() {
    int numOfCustomers;
    question3::Membership membership;
    question3::TypeOfCar typeOfCar;

    numOfCustomers = common::getNumInput<int>("Enter the number of customers for the day",
                                              [](int input) { return input >= 0; });

    for (int i = 0; i < numOfCustomers; i++) {
        common::printDivider();
        std::cout << "\t\tCUSTOMER " << i << std::endl;
        common::printDivider();

        membership = question3::getMembership();
        typeOfCar = question3::getTypeOfCar();

        std::cout << "Customer " << i << "'s membership: " << membership << std::endl;
        std::cout << "Customer " << i << "'s car type: " << typeOfCar << std::endl;
    }
    return 0;
}
