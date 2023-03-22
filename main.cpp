#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include "common.h"
#include "question3.h"

int main() {
    int numOfCustomers;
    question3::Membership membership;
    question3::TypeOfCar typeOfCar;
    question3::TypeOfWash typeOfWash;
    question3::AdditionalService additionalService;

    std::ofstream outputFile;

    numOfCustomers = common::getNumInput<int>("Enter the number of customers for the day",
                                              [](int input) { return input >= 0; });

    if (numOfCustomers > 0) {
        // without C++20, formatting string is difficult.
        // Hence, C-style is used.
        char filename[23];
        time_t now = time(nullptr);
        tm *localTime = localtime(&now);
        strftime(filename, 23, "%Y-%m-%d-carwash.csv", localTime);

        outputFile.open(filename, std::ios::app);
        if (outputFile.fail()) {
            std::cerr << "[-] Failed to open " << filename << " file." << std::endl;
            return -1;
        }
        std::cout << "[+] File \"" << filename << "\" successfully opened."
                  << std::endl;
    }

    question3::CustomerData database[(unsigned int) numOfCustomers];

    for (int i = 0; i < numOfCustomers; i++) {
        common::printDivider();
        std::cout << "\t\tCUSTOMER " << i << std::endl;
        common::printDivider();

        membership = question3::getMembership();
        typeOfCar = question3::getTypeOfCar();
        typeOfWash = question3::getTypeOfWash();
        additionalService = question3::getAdditionalService();

        database[i] = question3::CustomerData{
                membership, typeOfCar, typeOfWash, additionalService
        };

        std::cout << "Customer " << i << "'s membership: " << membership << std::endl;
        std::cout << "Customer " << i << "'s car type: " << typeOfCar << std::endl;
        std::cout << "Customer " << i << "'s car wash: " << typeOfWash << std::endl;
        std::cout << "Customer " << i << "'s additional service: " << additionalService << std::endl;
    }

    for (question3::CustomerData &customerData: database) {
        float total = question3::calculateTotalPrice(customerData);
        outputFile << std::fixed << std::setprecision(2) << customerData.membership << ',' << customerData.typeOfCar
                   << ',' << customerData.typeOfWash << ',' << customerData.additionalService << ',' << total
                   << std::endl;
    }

    outputFile.close();
    std::cout << "[+] Customers' data is saved and file is closed." << std::endl;

    return 0;
}
