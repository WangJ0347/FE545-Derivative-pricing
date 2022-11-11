//
// Created by Nhat Pham on 5/5/2022.
//

#ifndef RANDOM_TREE_PROJECT_PAYOFFCONSTRUCTIBLE_H
#define RANDOM_TREE_PROJECT_PAYOFFCONSTRUCTIBLE_H


#include <iostream>
#include "ArgList.h"
#include "PayOff3.h"
#include "PayOffFactory.h"
#include "PayOffAmerican.h"
#include <string>
#include <vector>

template <class T>
class PayOffHelper
{
public:
    PayOffHelper(std::string);
    static PayOff* Create(ArgumentList& args);
};

template <class T>
PayOff* PayOffHelper<T>::Create(ArgumentList& args)
{
    return new T(args);
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
    PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
    thePayOffFactory.RegisterPayOff(id,PayOffHelper<T>::Create);
}


#endif //RANDOM_TREE_PROJECT_PAYOFFCONSTRUCTIBLE_H
