cmake_minimum_required(VERSION 3.22)
project(random_tree_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(random_tree_project
        Arrays.cpp
        Arrays.h
        BinomialTree.cpp
        BinomialTree.h
        BlackScholesFormulas.cpp
        BlackScholesFormulas.h
        Normals.cpp
        Normals.h
        Parameters.cpp
        Parameters.h
        PayOff3.cpp
        PayOff3.h
        PayOffBridge.cpp
        PayOffBridge.h
        Random.cpp
        Random.h
        TreeAmerican.cpp
        TreeAmerican.h
        TreeEuropean.cpp
        TreeEuropean.h
        TreeMain1.cpp
        TreeProducts.cpp
        TreeProducts.h
        TrinomialTree.cpp
        TrinomialTree.h PayOffFactory.cpp PayOffFactory.h ArgList.cpp ArgList.h PayOffConstructible.cpp PayOffConstructible.h PayOffAmerican.cpp PayOffAmerican.h RandomHighTree.cpp RandomHighTree.h RandomLowTree.cpp RandomLowTree.h)
