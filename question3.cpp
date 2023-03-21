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
        std::cout << "0.\tNO MEMBERSHIP" << std::endl;
        std::cout << "1.\tBASIC MEMBERSHIP" << std::endl;
        std::cout << "2.\tPREMIUM MEMBERSHIP" << std::endl;
        printDivider();

        membership = common::getEnumInput<Membership>("SELECT CUSTOMER'S MEMBERSHIP", MEMBERSHIP_MIN, MEMBERSHIP_MAX);
        return membership;
    }
}

/**
 * Make Membership enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership Membership enum variant
 * @return Membership enum variant format for printing / debugging
 */
std::ostream& operator<<(std::ostream& out, question3::Membership membership) {
    const char* res;
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
