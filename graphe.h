//
//  graphe.h
//  projet_graphe
//
//  Created by Nicolas Loridon on 06/01/14.
//  Copyright (c) 2014 Nicolas Loridon. All rights reserved.
//

#ifndef __projet_graphe__graphe__
#define __projet_graphe__graphe__

#include <iostream>
#include <fstream>

using namespace std;

class Graphe{
protected:
    int _nsommet;
    int * _duree;
    bool ** _MAdj;
    int ** _MVal;
    int * _dpt;
    int * _dpta;
    
public:
    Graphe(int nsom);
    Graphe(ifstream *source);
    
    void addConstraint(int sommet, int constraint);
    void removeConstraint(int sommet, int constraint);
    bool verifyConstraint(int sommet, int constraint)
    { return _MAdj[sommet][constraint]; }
    
    bool detectCircuit() const;

    void print_graph();

    int earlyDate(int tache);
    int latestDate(int tache);
    void print_dpt();
    void print_dpta();
};

#endif /* defined(__projet_graphe__graphe__) */
