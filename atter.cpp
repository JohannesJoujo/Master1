//
// Created by Johannes Joujo on 2024-10-09.
//

#include "atter.h"

#include <iostream>
void node::addChildren(std::vector<node> children) {
    for (auto child: children) {
        childVec.push_back(child);
        if(child.hasChild==true) {
            childrenOfChild.push_back(child);
        }
    }
}

bool atter::ChecStructure(std::vector<std::vector<node> > &vec1, std::vector<std::vector<node> > &vec2) {
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
