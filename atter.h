//
// Created by Johannes Joujo on 2024-10-09.
//

#ifndef ATTER_H
#define ATTER_H

#include <vector>
struct node {
    char type;
    bool hasChild=false;
    std::vector<char> childVec;
    void addChildren(std::vector<char>children) {
        for (auto child: children) {
            childVec.push_back(child);
        }
    }
};
class atter {
public:
std::vector<std::vector<char>>mainChildVec;



};



#endif //ATTER_H
