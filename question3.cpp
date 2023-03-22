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

    /**
     * Prints type of car options, let user pick which car type applies to the customer (using int),
     * and returns the respective TypeOfCar enum variant for the int.
     * @return TypeOfCar enum variant
     */
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

    /**
     * Prints type of wash options, let user pick which wash type the customer requests (using int),
     * and returns the respective TypeOfWash enum variant for the int.
     * @return TypeOfWash enum variant
     */
    TypeOfWash getTypeOfWash() {
        TypeOfWash typeOfWash;
        printDivider();
        std::cout << "WHAT IS THE TYPE OF WASH THE CUSTOMER DESIRES?" << std::endl;
        std::cout << "0.\tQUICK WASH" << std::endl;
        std::cout << "1.\tNORMAL WASH" << std::endl;
        std::cout << "2.\tTHOROUGH WASH" << std::endl;
        printDivider();

        typeOfWash = common::getEnumInput<TypeOfWash>("SELECT DESIRED CAR WASH", TYPE_OF_WASH_MIN, TYPE_OF_WASH_MAX);
        return typeOfWash;
    }

    /**
     * Prints additional service options, let user pick additional service the customer requests (using int),
     * and returns the respective AdditionalService enum variant for the int.
     * @return AdditionalService enum variant
     */
    AdditionalService getAdditionalService() {
        AdditionalService additionalService;
        printDivider();
        std::cout << "WHAT IS THE ADDITIONAL SERVICE THE CUSTOMER DESIRES?" << std::endl;
        std::cout << "0.\tNONE" << std::endl;
        std::cout << "1.\tWAX" << std::endl;
        std::cout << "2.\tPOLISH" << std::endl;
        std::cout << "3.\tWAX AND POLISH" << std::endl;
        printDivider();

        additionalService = common::getEnumInput<AdditionalService>("SELECT DESIRED ADDITIONAL SERVICE",
                                                                    ADDITIONAL_SERVICE_MIN, ADDITIONAL_SERVICE_MAX);
        return additionalService;
    }

    /**
     * Calculates the total price for the car wash by checking the type of wash, type of car, additional services,
     * and membership status/tier.
     * For breakdown of the prices, check out the docs for each type in its respective enum.
     * @param customerData struct containing Membership, TypeOfCar, TypeOfWash, AdditionalService
     * @return total price of the car wash including the additional services
     */
    float calculateTotalPrice(CustomerData &customerData) {
        float total = 0.0f;

        switch (customerData.typeOfWash) {
            case TypeOfWash::Quick:
                total += 10.0f;
                break;
            case TypeOfWash::Normal:
                total += 15.0f;
                break;
            case TypeOfWash::Thorough:
                total += 20.0f;
        }

        switch (customerData.typeOfCar) {
            case TypeOfCar::Compact:
                total -= 5.0f;
                break;
            case TypeOfCar::Sedan:
                total += 0.0f;
                break;
            case TypeOfCar::Mpv:
                total += 5.0f;
                break;
            case TypeOfCar::Pickup:
                total += 10.0f;
        }

        switch (customerData.additionalService) {
            case AdditionalService::None:
                total += 0.0f;
                break;
            case AdditionalService::Wax:
                if (customerData.typeOfCar == TypeOfCar::Compact || customerData.typeOfCar == TypeOfCar::Sedan) {
                    total += 2.0f;
                } else {
                    total += 5.0f;
                }
                break;
            case AdditionalService::Polish:
                if (customerData.typeOfCar == TypeOfCar::Compact || customerData.typeOfCar == TypeOfCar::Sedan) {
                    total += 3.0f;
                } else {
                    total += 6.0f;
                }
                break;
            case AdditionalService::WaxAndPolish:
                if (customerData.typeOfCar == TypeOfCar::Compact || customerData.typeOfCar == TypeOfCar::Sedan) {
                    total += 5.0f;
                } else {
                    total += 8.0f;
                }
        }

        switch (customerData.membership) {
            case Membership::None:
                total *= 1.0f;
                break;
            case Membership::Basic:
                total *= (1.0f - 0.05f);
                break;
            case Membership::Premium:
                total *= (1.0f - 0.1f);
                break;
        }

        return total;
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
            res = "None";
            break;
        case question3::Membership::Basic:
            res = "Basic";
            break;
        case question3::Membership::Premium:
            res = "Premium";
            break;
        default:
            res = "Undefined";
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
            res = "Compact";
            break;
        case question3::TypeOfCar::Sedan:
            res = "Sedan";
            break;
        case question3::TypeOfCar::Mpv:
            res = "MPV";
            break;
        case question3::TypeOfCar::Pickup:
            res = "Pickup";
            break;
        default:
            res = "Undefined";
    }

    return out << res;
}

/**
 * Make TypeOfWash enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership TypeOfWash enum variant
 * @return TypeOfWash enum variant format for printing / debugging
 */
std::ostream &operator<<(std::ostream &out, question3::TypeOfWash typeOfWash) {
    const char *res;
    switch (typeOfWash) {
        case question3::TypeOfWash::Quick:
            res = "Quick";
            break;
        case question3::TypeOfWash::Normal:
            res = "Normal";
            break;
        case question3::TypeOfWash::Thorough:
            res = "Thorough";
            break;
        default:
            res = "Undefined";
    }

    return out << res;
}

/**
 * Make AdditionalService enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership AdditionalService enum variant
 * @return AdditionalService enum variant format for printing / debugging
 */
std::ostream &operator<<(std::ostream &out, question3::AdditionalService additionalService) {
    const char *res;
    switch (additionalService) {
        case question3::AdditionalService::None:
            res = "None";
            break;
        case question3::AdditionalService::Wax:
            res = "Wax";
            break;
        case question3::AdditionalService::Polish:
            res = "Polish";
            break;
        case question3::AdditionalService::WaxAndPolish:
            res = "Wax and Polish";
            break;
        default:
            res = "Undefined";
    }

    return out << res;
}
