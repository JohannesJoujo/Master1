//
// Created by Johannes Joujo on 2024-10-09.
//

#ifndef ATTER_H
#define ATTER_H

#include <set>
#include <vector>
struct node {
    node(char type) {
        this->type=type;
        this->hasChild=hasChild;
    }
    char type;
    bool hasChild=false;
    std::vector<node> childVec;
    void addChildren(std::vector<node>children) {
        for (auto child: children) {
            childVec.push_back(child);
        }
    }
};
class atter {
public:
std::vector<std::vector<node>>mainChildVec;



};



#endif //ATTER_H
