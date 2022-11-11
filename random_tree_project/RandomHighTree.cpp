//
// Created by Nhat Pham on 5/5/2022.
//

#include "RandomHighTree.h"
#include "Arrays.h"
#include <cmath>

// the basic math functions should be in namespace std but aren't in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

RandomHighTree::RandomHighTree(double Spot_,
                               double r_,
                               double d_,
                               double Volatility_,
                               unsigned long Steps_,
                               double Time_,
                               double b_,
                               unsigned long NumberOfPaths_)
                               :Spot(Spot_),
                               r(r_),
                               d(d_),
                               Volatility(Volatility_),
                               Steps(Steps_),
                               Time(Time_),
                               b(b_),
                               NumberOfPaths(NumberOfPaths_){
    TreeBuilt=false;
}

void RandomHighTree::BuildTree() {
    TreeBuilt = true;
    TheTree.resize(Steps+1);
    TheTree[0].resize(1);
    TheTree[0][0].first = Spot;

    double delta_t = Time / Steps;

    for (unsigned long i=1; i <=Steps; i++){

        TheTree[i].resize(pow(b,i));

        for (unsigned long j = 0; j < pow(b,i); j++ ){
            unsigned long index = j / static_cast<unsigned long>(b);
            TheTree[i][j].first = GetGBMNextPrice(TheTree[i-1][index].first,r,d,Volatility,delta_t);
        }
    }
}

double RandomHighTree::GetThePrice(const TreeProducts &TheProduct) {

    double runningSum = 0;

    for (unsigned long i = 0; i < NumberOfPaths; ++i) {
        if (!TreeBuilt)
            BuildTree();

        if (TheProduct.GetFinalTime() != Time)
            throw("mismatched product in SimpleTrinomialTree");

        if (b != 3)
            throw("b must equal to 3");

        for (unsigned long j = 0; j < pow(b,Steps); ++j) {
            TheTree[Steps][j].second = TheProduct.FinalPayOff(TheTree[Steps][j].first);
        }

        for (unsigned long j = 1; j <= Steps ; ++j) {
            unsigned long index = Steps-j;
            double ThisTime = index*Time/Steps;

            for (unsigned long k = 0; k < pow(b,index); k++ ){
                double Spot = TheTree[index][k].first;
                double Average =
                        (TheTree[index+1][3*k].second
                        + TheTree[index+1][3*k+1].second
                        + TheTree[index+1][3*k+2].second)/3;
                TheTree[index][k].second = TheProduct.PreFinalValue(Spot,ThisTime,Average);
            }
        }
        runningSum += TheTree[0][0].second;
        TreeBuilt = false;
    }
    return runningSum/NumberOfPaths;
}