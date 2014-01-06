//
//  graphe.cpp
//  projet_graphe
//
//  Created by Nicolas Loridon on 06/01/14.
//  Copyright (c) 2014 Nicolas Loridon. All rights reserved.
//

#include "graphe.h"




bool Graphe::detectCircuit() const {
    int i,x,y,z;
    bool circuit = false;
    
    for(x=0;x<this->_nsommet;x++)
    {
        for(y=0;y<this->_nsommet;y++)
        {
            for(z=0;z<this->_nsommet;z++)
            {
                std::cout << "-> " << x << ", " << y << ", " << z << std::endl;
                std::cout << "{" <<this->_MAdj[x][y]<<" , " << this->_MAdj[y][z] << "}" << std::endl;
                
                if (this->_MAdj[x][y]==1 && this->_MAdj[y][z]==1)       // si x->y existe et y->z existe
                {
                    this->_MAdj[x][z] = true;                //alors x->z existe
                    this->_MVal[x][z] = this->_MVal[x][y] + this->_MVal[y][z];
                }
            }
        }
    }
    
    for(i=0;i<this->_nsommet;i++)
    {
        if (this->_MAdj[i][i])       //après avoir fait la fermeture transitive on regarde la diago
            circuit = true;     // si il y'a un true sur la diago (MAdj) alors il y'a un circuit.
    }
    
    if(circuit==true)
        std::cout<< " CIIIIIRCUIIIIIIIIT" << std::endl;
    else
        std::cout << "PAS DE CIRCUIT" << std::endl;
    
    return circuit;             // on retourne le booléen (circuit or not)
}

void Graphe::print_graph(){
	int i,j;
	for(i=0;i<this->_nsommet;i++)  //affichage du graphe pour verifier qu'il est bien en mémoire.
    {
        for(j=0;j<this->_nsommet;j++)
            
        {
			if(this->_MAdj[i][j] == true) {
                std::cout<<" "<<this->_MVal[i][j]<<" ";
            }
			else {
                std::cout<<" X ";

            }
        }
        std::cout<<std::endl;
    }
}
