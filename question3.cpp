//
// Created by ammar on 21/3/2023.
//

#include <iostream>
#include "common.h"
#include "question3.h"

namespace question3 {
    /**
     * Prints a line for menu separation purposes.
     */
    void printDivider() {
        std::cout << "-----------------------------------------------" << std::endl;
    }

    /**
     * Prints membership options and let user pick which membership applies to the customer.
     * @return Membership enum variant
     */
    Membership getMembership() {
        Membership membership;
        printDivider();
        std::cout << "WHAT IS THE MEMBERSHIP STATUS OF THE CUSTOMER?" << std::endl;
        std::cout << "0.\tNO MEMBERSHIP" << std::endl;
        std::cout << "1.\tBASIC MEMBERSHIP" << std::endl;
        std::cout << "2.\tPREMIUM MEMBERSHIP" << std::endl;
        printDivider();

        membership = common::getEnumInput<Membership>("SELECT CUSTOMER'S MEMBERSHIP", MEMBERSHIP_MIN, MEMBERSHIP_MAX);
        return membership;
    }

    TypeOfCar getTypeOfCar() {
        TypeOfCar typeOfCar;
        printDivider();
        std::cout << "WHAT IS THE CUSTOMER'S TYPE OF CAR?" << std::endl;
        std::cout << "0.\tCOMPACT CAR" << std::endl;
        std::cout << "1.\tSEDAN CAR" << std::endl;
        std::cout << "2.\tMPV CAR" << std::endl;
        std::cout << "3.\tPickup Truck" << std::endl;
        printDivider();

        typeOfCar = common::getEnumInput<TypeOfCar>("SELECT CUSTOMER'S CAR TYPE", TYPE_OF_CAR_MIN, TYPE_OF_CAR_MAX);
        return typeOfCar;
    }
}

/**
 * Make Membership enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership Membership enum variant
 * @return Membership enum variant format for printing / debugging
 */
std::ostream &operator<<(std::ostream &out, question3::Membership membership) {
    const char *res;
    switch (membership) {
        case question3::Membership::None:
            res = "No Membership";
            break;
        case question3::Membership::Basic:
            res = "Basic Membership";
            break;
        case question3::Membership::Premium:
            res = "Premium Membership";
            break;
        default:
            res = "Undefined Membership";
    }

    return out << res;
}

/**
 * Make TypeOfCar enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership TypeOfCar enum variant
 * @return TypeOfCar enum variant format for printing / debugging
 */
std::ostream &operator<<(std::ostream &out, question3::TypeOfCar typeOfCar) {
    const char *res;
    switch (typeOfCar) {
        case question3::TypeOfCar::Compact:
            res = "Compact Car";
            break;
        case question3::TypeOfCar::Sedan:
            res = "Sedan Car";
            break;
        case question3::TypeOfCar::Mpv:
            res = "MPV Car";
            break;
        case question3::TypeOfCar::Pickup:
            res = "Pickup Truck";
            break;
        default:
            res = "Undefined Type of Car";
    }

    return out << res;
}
