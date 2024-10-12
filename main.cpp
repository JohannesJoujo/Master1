#include <iostream>
#include "atter.h"
int main() {
    std::vector<char> rootschildren;
    rootschildren.push_back('k');

    rootschildren.push_back('m');
    rootschildren.push_back('k');

    std::vector<char> secondBorn;
    secondBorn.push_back('i');
    secondBorn.push_back('m');


    node root;
    root.type='k';
    root.hasChild=true;
    root.addChildren(rootschildren);
    root.addChildren(secondBorn);

    atter firstStructure;
    firstStructure.mainChildVec.push_back(root.childVec);
    for (auto children :firstStructure.mainChildVec) {
        for (auto child: children) {
            std::cout<<child<<std::endl;
        }
    }
    return 0;
}
