//
// Created by Nhat Pham on 5/5/2022.
//

#include "PayOffConstructible.h"

namespace {
    PayOffHelper<PayOffBNCall> RegisterBNCall("BNCall");
    PayOffHelper<PayOffBNPut> RegisterBNPut("BNPut");
    PayOffHelper<PayOffRTCallH> RegisterRTCallH("RTCallH");
    PayOffHelper<PayOffRTPutH> RegisterRTPutH("RTPutH");
    PayOffHelper<PayOffRTCallL> RegisterRTCallL("RTCallL");
    PayOffHelper<PayOffRTPutL> RegisterPayOffRTPutL("RTPutL");
}

