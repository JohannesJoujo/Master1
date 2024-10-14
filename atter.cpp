//
// Created by Johannes Joujo on 2024-10-09.
//

#include "atter.h"

#include <iostream>
void node::addChildren(std::vector<node> children) {
    for (auto child: children) {
        childVec.push_back(child);
    }
}

bool atter::ChecStructure(std::vector<atter>&allStructures) {
    std::vector<std::vector<node>>vec1;
    std::vector<std::vector<node>>vec2;
    for(int i=0;i<allStructures.size();i++) {
        //kommer att fungera för udda antal strukturer i vectorn
        if(allStructures[i+1].mainChildVec.empty()) {
            continue;
        }
        vec1=allStructures[i].mainChildVec;
        vec2=allStructures[i+1].mainChildVec;
        //bace case on de har olika storlek så är de olika.
        if(vec1[0].size()!=vec2[0].size()) {
            return false;
        }
        //kollar om de har samma struktur
        for(int k=0;k<vec1.size();k++) {
            for(int j=0;j<vec1[i].size();j++) {
                if(vec1[k][j].type!=vec2[k][j].type) {
                    return false;
                }
                if(vec1[k][j].nodenumber!=vec2[k][j].nodenumber) {
                    return false;
                }
                if(vec1[k][j].hasParent!=vec2[k][j].hasParent) {
                    return false;
                }
            }
        }
    }
    return true;
}
