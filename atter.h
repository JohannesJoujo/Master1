//
// Created by Johannes Joujo on 2024-10-09.
//

#ifndef ATTER_H
#define ATTER_H

#include <iostream>
#include <queue>
#include <vector>
struct node {
    node(char type,std::string hasParent ,int nodenumber):type(type),hasParent(hasParent),nodenumber(nodenumber){}
    int nodenumber;
    char type;
    std::string hasParent;
    bool hasChild=false;
    std::vector<node> childVec;
    void addChildren(std::vector<node>children);
};
class atter {
public:
std::vector<std::vector<node>>mainChildVec;
    bool ChecStructure(std::vector<atter>&allStructures);
};



#endif //ATTER_H
