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

class Graphe{
protected:
    int _nsommet;
    int * _duree;
    bool ** _MAdj;
    bool ** _MVal;
    
public:
    Graphe();
    
    bool detectCircuit() const;
    void print_graph();
};

#endif /* defined(__projet_graphe__graphe__) */
