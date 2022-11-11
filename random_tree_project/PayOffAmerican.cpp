//
// Created by Nhat Pham on 5/5/2022.
//

#include "PayOffAmerican.h"

PayOffBNCall::PayOffBNCall(ArgumentList &args) {
    Expiry = args.GetDoubleArgumentValue("expiry");
    Strike = args.GetDoubleArgumentValue("strike");
    Vol = args.GetDoubleArgumentValue("vol");
    r = args.GetDoubleArgumentValue("r");
    d = args.GetDoubleArgumentValue("d");
    Steps = args.GetULArgumentValue("steps");
}

double PayOffBNCall::operator()(double Spot) const {
    PayOffCall thePayOffCall(Strike);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    TreeAmerican TreeAmerCall(Expiry, thePayOffCall);
    SimpleBinomialTree BinomTree(Spot,rParam,dParam,Vol,Steps, Expiry);

    return BinomTree.GetThePrice(TreeAmerCall);
}

PayOff* PayOffBNCall::clone() const {
    return new PayOffBNCall(*this);
}

PayOffBNPut::PayOffBNPut(ArgumentList &args) {
    Expiry = args.GetDoubleArgumentValue("expiry");
    Strike = args.GetDoubleArgumentValue("strike");
    Vol = args.GetDoubleArgumentValue("vol");
    r = args.GetDoubleArgumentValue("r");
    d = args.GetDoubleArgumentValue("d");
    Steps = args.GetULArgumentValue("steps");
}

double PayOffBNPut::operator()(double Spot) const {
    PayOffPut thePayOffPut(Strike);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    TreeAmerican TreeAmerPut(Expiry, thePayOffPut);
    SimpleBinomialTree BinomTree(Spot,rParam,dParam,Vol,Steps, Expiry);

    return BinomTree.GetThePrice(TreeAmerPut);
}

PayOff* PayOffBNPut::clone() const {
    return new PayOffBNPut(*this);
}

PayOffRTCallH::PayOffRTCallH(ArgumentList &args) {
    Expiry = args.GetDoubleArgumentValue("expiry");
    Strike = args.GetDoubleArgumentValue("strike");
    Vol = args.GetDoubleArgumentValue("vol");
    r = args.GetDoubleArgumentValue("r");
    d = args.GetDoubleArgumentValue("d");
    Steps = args.GetULArgumentValue("steps");
    b = args.GetDoubleArgumentValue("b");
    NumberOfPaths = args.GetULArgumentValue("number_of_paths");
}

double PayOffRTCallH::operator()(double Spot) const {
    PayOffCall thePayOffCall(Strike);
    TreeAmerican TreeAmerCall(Expiry, thePayOffCall);
    RandomHighTree RandHighTree(Spot,r,d,Vol,Steps, Expiry,b,NumberOfPaths);

    return RandHighTree.GetThePrice(TreeAmerCall);
}

PayOff* PayOffRTCallH::clone() const {
    return new PayOffRTCallH(*this);
}

PayOffRTPutH::PayOffRTPutH(ArgumentList &args) {
    Expiry = args.GetDoubleArgumentValue("expiry");
    Strike = args.GetDoubleArgumentValue("strike");
    Vol = args.GetDoubleArgumentValue("vol");
    r = args.GetDoubleArgumentValue("r");
    d = args.GetDoubleArgumentValue("d");
    Steps = args.GetULArgumentValue("steps");
    b = args.GetDoubleArgumentValue("b");
    NumberOfPaths = args.GetULArgumentValue("number_of_paths");
}

double PayOffRTPutH::operator()(double Spot) const {
    PayOffPut thePayOffPut(Strike);
    TreeAmerican TreeAmerPut(Expiry, thePayOffPut);
    RandomHighTree RandHighTree(Spot,r,d,Vol,Steps, Expiry,b,NumberOfPaths);

    return RandHighTree.GetThePrice(TreeAmerPut);
}

PayOff* PayOffRTPutH::clone() const {
    return new PayOffRTPutH(*this);
}

PayOffRTCallL::PayOffRTCallL(ArgumentList &args) {
    Expiry = args.GetDoubleArgumentValue("expiry");
    Strike = args.GetDoubleArgumentValue("strike");
    Vol = args.GetDoubleArgumentValue("vol");
    r = args.GetDoubleArgumentValue("r");
    d = args.GetDoubleArgumentValue("d");
    Steps = args.GetULArgumentValue("steps");
    b = args.GetDoubleArgumentValue("b");
    NumberOfPaths = args.GetULArgumentValue("number_of_paths");
}

double PayOffRTCallL::operator()(double Spot) const {
    PayOffCall thePayOffCall(Strike);
    TreeAmerican TreeAmerCall(Expiry, thePayOffCall);
    RandomLowTree RandLowTree(Spot,r,d,Vol,Steps, Expiry,b,NumberOfPaths);

    return RandLowTree.GetThePrice(TreeAmerCall);
}

PayOff* PayOffRTCallL::clone() const {
    return new PayOffRTCallL(*this);
}

PayOffRTPutL::PayOffRTPutL(ArgumentList &args) {
    Expiry = args.GetDoubleArgumentValue("expiry");
    Strike = args.GetDoubleArgumentValue("strike");
    Vol = args.GetDoubleArgumentValue("vol");
    r = args.GetDoubleArgumentValue("r");
    d = args.GetDoubleArgumentValue("d");
    Steps = args.GetULArgumentValue("steps");
    b = args.GetDoubleArgumentValue("b");
    NumberOfPaths = args.GetULArgumentValue("number_of_paths");
}

double PayOffRTPutL::operator()(double Spot) const {
    PayOffPut thePayOffPut(Strike);
    TreeAmerican TreeAmerPut(Expiry, thePayOffPut);
    RandomLowTree RandLowTree(Spot,r,d,Vol,Steps, Expiry,b,NumberOfPaths);

    return RandLowTree.GetThePrice(TreeAmerPut);
}

PayOff* PayOffRTPutL::clone() const {
    return new PayOffRTPutL(*this);
}