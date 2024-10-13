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
    root.addChildren(brakervec);
    root.addChildren(rootschildren);
    root.addChildren(brakervec);
    root.addChildren(secondBorn);
    root.addChildren(brakervec);
    root.addChildren(thirdBorn);
    root.addChildren(brakervec);


    node secondRoot('k',"none",0);
    secondRoot.hasChild=true;

    std::vector<node> secRootChildren;
    node sm1('m',"secondRoot",1);
    secRootChildren.push_back(sm1);

    node sk1('k',"secondRoot",2);
    sk1.hasChild=true;
    secRootChildren.push_back(sk1);

    node sk2('k',"secondRoot",3);
    sk2.hasChild=true;
    secRootChildren.push_back(sk2);

    std::vector<node> secRootSecondChildren;
    node sk3('k',"sk1",4);
    secRootSecondChildren.push_back(sk3);

    std::vector<node> secRootThirdChildren;
    node sm2('m',"sk2",5);
    secRootThirdChildren.push_back(sm2);
    node si1('i',"sk2",6);
    secRootThirdChildren.push_back(si1);

    secondRoot.addChildren(brakervec);
    secondRoot.addChildren(brakervec);
    secondRoot.addChildren(secRootChildren);
    secondRoot.addChildren(brakervec);
    secondRoot.addChildren(secRootSecondChildren);
    secondRoot.addChildren(brakervec);
    secondRoot.addChildren(secRootThirdChildren);
    secondRoot.addChildren(brakervec);



    //root.print();

    atter firstStructure;
    atter secondStructure;
    firstStructure.mainChildVec.push_back(root.childVec);
    secondStructure.mainChildVec.push_back(secondRoot.childVec);

    for (auto children :firstStructure.mainChildVec) {
        for (auto child: children) {
            if(child.type=='n'){std::cout<<"-------------------------------";}
            std::cout<<child.type<< " " << child.nodenumber<<" parent is: "<<child.hasParent<<std::endl;
        }
    }
    for (auto children :secondStructure.mainChildVec) {
        for (auto child: children) {
            if(child.type=='n'){std::cout<<"-------------------------------";}
            std::cout<<child.type<< " " << child.nodenumber<<" parent is: "<<child.hasParent<<std::endl;
        }
    }
    return 0;
}
