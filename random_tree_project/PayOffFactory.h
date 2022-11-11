//
// Created by Nhat Pham on 5/5/2022.
//

#ifndef RANDOM_TREE_PROJECT_PAYOFFFACTORY_H
#define RANDOM_TREE_PROJECT_PAYOFFFACTORY_H


#include "PayOff3.h"

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

#include "ArgList.h"
#include <map>
#include <string>
#include <vector>

class PayOffFactory
{
public:
    typedef PayOff*  (*CreatePayOffFunction)(ArgumentList& args);

    static PayOffFactory& Instance();
    void RegisterPayOff(std::string, CreatePayOffFunction);
    // allows the possibility of returning a null pointer if the identity string was not found
    PayOff* CreatePayOff(std::string PayOffID, ArgumentList& args);
    ~PayOffFactory(){};

private:
    std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
    PayOffFactory(){}
    PayOffFactory(const PayOffFactory&){}
    PayOffFactory& operator = (const PayOffFactory&){return *this;}
};


#endif //RANDOM_TREE_PROJECT_PAYOFFFACTORY_H
