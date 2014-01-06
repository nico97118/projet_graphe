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
    cout<<"date au plus tot de fin de projet :"<<ordo.earlyDate(4)<<endl;
    cout<<"date au plus tard : "<<ordo.latestDate(1);
    
    
    return 0;
}

