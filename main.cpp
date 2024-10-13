#include <iostream>
#include "atter.h"
void testTwoStructures(atter& first, atter& second);
void printVec(atter &atten);
int main() {
    //creating the nodes for the first structure
    node root('k',"none",0);
    node k1('k',"root",1);
    node m('m',"root",2);
    node k2('k',"root",3);

    node i1('i',"k1",4);
    node m2('m',"k1",5);

    node k3('k',"k2",6);
    //deciding the children of the nodes
    k1.hasChild=true;
    root.hasChild=true;
    k2.hasChild=true;

    //adding all direct children of root to one node vector
    std::vector<node> rootschildren;
    rootschildren.push_back(k1);
    rootschildren.push_back(m);
    rootschildren.push_back(k2);

    //adding all direct children of k1 to one node vector
    std::vector<node> secondBorn;
    secondBorn.push_back(i1);
    secondBorn.push_back(m2);

    //adding all direct children of k2 to one node vector
    std::vector<node> thirdBorn;
    thirdBorn.push_back(k3);
    std::vector<node>rootvec;
    rootvec.push_back(root);
    root.addChildren(rootvec);

    //adding all the children to the root node
    root.addChildren(rootschildren);
    root.addChildren(secondBorn);
    root.addChildren(thirdBorn);

    //creating the nodes for the second structure
    node secondRoot('k',"none",0);
    node sm1('m',"root",1);
    node sk1('k',"root",2);
    node sk2('k',"root",3);

    node sk3('k',"sk1",4);

    node sm2('m',"sk2",5);
    node si1('i',"sk2",6);
    //de
    secondRoot.hasChild=true;
    sk1.hasChild=true;
    sk2.hasChild=true;

    //adding the children of root to one node vector
    std::vector<node> secRootChildren;
    secRootChildren.push_back(sm1);
    secRootChildren.push_back(sk1);
    secRootChildren.push_back(sk2);

    //adding the children of sk1 to one node vector
    std::vector<node> secRootSecondChildren;
    secRootSecondChildren.push_back(sk3);

    //adding the children of sk2 to one node vector
    std::vector<node> secRootThirdChildren;
    secRootThirdChildren.push_back(sm2);
    secRootThirdChildren.push_back(si1);

    //adding the root node to a vector
    std::vector<node>secRootVec;
    secRootVec.push_back(secondRoot);
    //adding the rest of the children the same vector
    secondRoot.addChildren(secRootVec);
    secondRoot.addChildren(secRootChildren);
    secondRoot.addChildren(secRootSecondChildren);
    secondRoot.addChildren(secRootThirdChildren);


    atter firstStructure;
    atter secondStructure;
    atter thirdStructure;
    //lägger till den uppbygda strukturen till atters mainChildVec
    firstStructure.mainChildVec.push_back(root.childVec);
    thirdStructure.mainChildVec.push_back(root.childVec);
    secondStructure.mainChildVec.push_back(secondRoot.childVec);

    //skriver ut alla noder i första strukturen
    printVec(firstStructure);
    std::cout<<std::endl;
    std::cout<<std::endl;

    //skriver ut alla noder i tredje strukturen
    printVec(thirdStructure);
    std::cout<<std::endl;
    std::cout<<std::endl;

    //skriver ut alla noder i andra strukturen
    printVec(secondStructure);
    std::cout<<std::endl;
    std::cout<<std::endl;

    //kör testet för att se om strukturerna är lika
    testTwoStructures(firstStructure,secondStructure);
    testTwoStructures(firstStructure,thirdStructure);
    return 0;
}
void printVec(atter& atten) {
    for (auto children :atten.mainChildVec) {
        for (auto child: children) {
            if(child.type=='n'){std::cout<<"-------------------------------";}
            std::cout<<child.type<< " " << child.nodenumber<<" parent is: "<<child.hasParent<<std::endl;
        }
    }
}
void testTwoStructures(atter& first, atter& second) {
    if(first.ChecStructure(first.mainChildVec,second.mainChildVec)) {
        std::cout<<"The structures are the same"<<std::endl;
    } else {
        std::cout<<"The structures are not the same"<<std::endl;
    }
}