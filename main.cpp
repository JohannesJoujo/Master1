#include <iostream>
#include "atter.h"
int main() {
    node k1('k');
    k1.hasChild=true;
    std::vector<node> rootschildren;
    rootschildren.push_back(k1);
    node k2('m');
    rootschildren.push_back(k2);
    node k3('k');
    k3.hasChild=true;
    rootschildren.push_back(k3);

    node k4('i');
    node k5('k');
    std::vector<node> secondBorn;
    secondBorn.push_back(k4);
    secondBorn.push_back(k5);

    std::vector<node> thirdBorn;
    node k6('k');
    secondBorn.push_back(k6);

    node root('k');
    root.hasChild=true;
    root.addChildren(rootschildren);
    root.addChildren(secondBorn);
    root.addChildren(thirdBorn);


    atter firstStructure;
    firstStructure.mainChildVec.push_back(root.childVec);
    for (auto children :firstStructure.mainChildVec) {
        for (auto child: children) {
            std::cout<<child.type<< " ";
            if(child.hasChild) {
                std::cout<<"has child"<<std::endl;
            }else {
                std::cout<<std::endl;
            }
        }
    }
    return 0;
}
