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
    std::vector<node>childrenOfChild;
    int nodenumber;
    char type;
    std::string hasParent;
    bool hasChild=false;
    std::vector<node> childVec;
    void addChildren(std::vector<node>children) {
        for (auto child: children) {
            childVec.push_back(child);
            if(child.hasChild==true) {
                childrenOfChild.push_back(child);
            }
        }
        //std::cout<<"hej"<<std::endl;
    }
    void print() {
        for(int i=0;i<childrenOfChild.size();i++) {
            std::cout<<childrenOfChild[i].type<< childrenOfChild[i].nodenumber<<std::endl;
        }
    }
};
class atter {
public:
std::vector<std::vector<node>>mainChildVec;

    bool ChecStructure(std::vector<std::vector<node>>& vec1, std::vector<std::vector<node>>& vec2) {
        if(vec1[0].size()!=vec2[0].size()) {
            return false;
        }
        for(int i=0;i<vec1.size();i++) {
            for(int j=0;j<vec1[i].size();j++) {
                if(vec1[i][j].type!=vec2[i][j].type) {
                    return false;
                }
                if(vec1[i][j].nodenumber!=vec2[i][j].nodenumber) {
                    std::cout<<j<<std::endl;
                    return false;
                }
                if(vec1[i][j].hasParent!=vec2[i][j].hasParent) {
                    std::cout<<j<<std::endl;
                    return false;
                }
            }
        }
        return true;
    }


};



#endif //ATTER_H
