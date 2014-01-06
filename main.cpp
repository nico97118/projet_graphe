//
//  main.cpp
//  projet_graphe
//
//  Created by Nicolas Loridon on 06/01/14.
//  Copyright (c) 2014 Nicolas Loridon. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "graphe.h"


using namespace std;
int main(int argc, const char * argv[])
{
    
    
    ifstream source("donnees.txt", ios::in);
    
    Graphe ordo(&source);
    ordo.detectCircuit();
    ordo.print_graph();
    cout<<ordo.earlyDate(4);

    
    return 0;
}

