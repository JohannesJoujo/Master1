#include <iostream>
#include "atter.h"
int main() {
    node k1('k',"root",1);
    k1.hasChild=true;
    std::vector<node> rootschildren;
    rootschildren.push_back(k1);
    node m('m',"root",2);
    rootschildren.push_back(m);
    node k2('k',"root",3);
    k2.hasChild=true;
    rootschildren.push_back(k2);

    node i1('i',"k1",4);
    node m2('m',"k1",5);
    std::vector<node> secondBorn;
    secondBorn.push_back(i1);
    secondBorn.push_back(m2);

    std::vector<node> thirdBorn;
    node k3('k',"k2",6);
    thirdBorn.push_back(k3);

    node braker('n',"none",70);
    std::vector<node> brakervec;
    brakervec.push_back(braker);

    node root('k',"none",0);
    root.hasChild=true;
    root.addChildren(rootschildren);
    root.addChildren(brakervec);
    root.addChildren(secondBorn);
    root.addChildren(brakervec);
    root.addChildren(thirdBorn);

    //root.print();

    atter firstStructure;
    firstStructure.mainChildVec.push_back(root.childVec);

    for (auto children :firstStructure.mainChildVec) {
        for (auto child: children) {
            if(child.type=='n'){std::cout<<"-------------------------------";}
            std::cout<<child.type<< " " << child.nodenumber<<" parent is: "<<child.hasParent<<std::endl;
        }
    }
    return 0;
}
