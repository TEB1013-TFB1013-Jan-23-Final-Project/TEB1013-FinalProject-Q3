//
// Created by ammar on 21/3/2023.
//

#ifndef TEB1013_FINALPROJECT_Q3_QUESTION3_H
#define TEB1013_FINALPROJECT_Q3_QUESTION3_H

#define MEMBERSHIP_MAX 2
#define MEMBERSHIP_MIN 0

#define TYPE_OF_CAR_MAX 3
#define TYPE_OF_CAR_MIN 0

#define TYPE_OF_WASH_MAX 2
#define TYPE_OF_WASH_MIN 0

#define ADDITIONAL_SERVICE_MAX 3
#define ADDITIONAL_SERVICE_MIN 0

namespace question3 {
    /**
     * Possible Membership options (enum variant).
     * 0 = None (0% discount)
     * 1 = Basic (5% discount)
     * 2 = Premium (10% discount)
     */
    enum class Membership {
        None = 0,
        Basic = 1,
        Premium = 2
    };

    /**
     * Possible TypeOfCar options (enum variant).
     * 0 = Compact (- RM5.00)
     * 1 = Sedan (+ RM0.00)
     * 2 = MPV (+ RM5.00)
     * 3 = Pickup Truck (+ RM10.00)
     */
    enum class TypeOfCar {
        Compact = 0,
        Sedan = 1,
        Mpv = 2,
        Pickup = 3
    };

    /**
     * Possible TypeOfWash options (enum variant).
     * 0 = Quick (RM10.00)
     * 1 = Normal (RM15.00)
     * 2 = Thorough (RM20.00)
     */
    enum class TypeOfWash {
        Quick = 0,
        Normal = 1,
        Thorough = 2
    };

    /**
     * Possible AdditionalService options (enum variant).
     * 0 = None (+ RM0.00)
     * 1 = Wax (+ RM2.00-RM5.00)
     * 2 = Polish (+ RM3.00-RM6.00)
     * 3 = WaxAndPolish (+ RM5.00-RM8.00)
     */
    enum class AdditionalService {
        None = 0,
        Wax = 1,
        Polish = 2,
        WaxAndPolish = 3
    };

    struct CustomerData {
        Membership membership;
        TypeOfCar typeOfCar;
        TypeOfWash typeOfWash;
        AdditionalService additionalService;
    };

    /**
     * Prints membership options, let user pick which membership applies to the customer (using int),
     * and returns the respective Membership enum variant for the int.
     * @return Membership enum variant
     */
    Membership getMembership();

    /**
     * Prints type of car options, let user pick which car type applies to the customer (using int),
     * and returns the respective TypeOfCar enum variant for the int.
     * @return TypeOfCar enum variant
     */
    TypeOfCar getTypeOfCar();

    /**
     * Prints type of wash options, let user pick which wash type the customer requests (using int),
     * and returns the respective TypeOfWash enum variant for the int.
     * @return TypeOfWash enum variant
     */
     TypeOfWash getTypeOfWash();

    /**
     * Prints additional service options, let user pick additional service the customer requests (using int),
     * and returns the respective AdditionalService enum variant for the int.
     * @return AdditionalService enum variant
     */
    AdditionalService getAdditionalService();

    /**
     * Calculates the total price for the car wash by checking the type of wash, type of car, additional services,
     * and membership status/tier.
     * For breakdown of the prices, check out the docs for each type in its respective enum.
     * @param customerData struct containing Membership, TypeOfCar, TypeOfWash, AdditionalService
     * @return total price of the car wash including the additional services
     */
    float calculateTotalPrice(CustomerData &customerData);
}

/**
 * Make Membership enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership Membership enum variant
 * @return Membership enum variant format for printing / debugging
 */
std::ostream& operator<<(std::ostream& out, question3::Membership membership);

/**
 * Make TypeOfCar enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership TypeOfCar enum variant
 * @return TypeOfCar enum variant format for printing / debugging
 */
std::ostream &operator<<(std::ostream &out, question3::TypeOfCar typeOfCar);

/**
 * Make TypeOfWash enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership TypeOfWash enum variant
 * @return TypeOfWash enum variant format for printing / debugging
 */
std::ostream &operator<<(std::ostream &out, question3::TypeOfWash typeOfWash);

/**
 * Make AdditionalService enum work with << operator. This is meant for printing and debugging purposes.
 * @param out ostream reference
 * @param membership AdditionalService enum variant
 * @return AdditionalService enum variant format for printing / debugging
 */
std::ostream &operator<<(std::ostream &out, question3::AdditionalService additionalService);

#endif //TEB1013_FINALPROJECT_Q3_QUESTION3_H
