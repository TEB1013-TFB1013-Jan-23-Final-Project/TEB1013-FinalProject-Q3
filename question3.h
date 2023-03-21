//
// Created by ammar on 21/3/2023.
//

#ifndef TEB1013_FINALPROJECT_Q3_QUESTION3_H
#define TEB1013_FINALPROJECT_Q3_QUESTION3_H

#define MEMBERSHIP_MAX 2
#define MEMBERSHIP_MIN 0

namespace question3 {
    /**
     * Possible Membership options (enum variant).
     * 0 = None (0% discount)
     * 1 = Basic (5% discount)
     * 2 = Premium (10% discount)
     */
    enum Membership {
        None = 0,
        Basic = 1,
        Premium = 2
    };

    /**
     * Prints membership options, let user pick which membership applies to the customer (using int),
     * and returns the respective Membership enum variant for the int.
     * @return Membership enum variant
     */
    Membership getMembership();
}

/**
 * Make Membership enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership Membership enum variant
 * @return Membership enum variant format for printing / debugging
 */
std::ostream& operator<<(std::ostream& out, question3::Membership membership);

#endif //TEB1013_FINALPROJECT_Q3_QUESTION3_H
