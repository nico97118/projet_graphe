//
//  graphe.cpp
//  projet_graphe
//
//  Created by Nicolas Loridon on 06/01/14.
//  Copyright (c) 2014 Nicolas Loridon. All rights reserved.
//

#include "graphe.h"
#include <vector>

int max(vector<int> valeurs)
{
    int max = 0;
    for(vector<int>::iterator it(valeurs.begin());it != valeurs.end();it++)
        if(*it >= max)
            max = *it;
    return max;
}

Graphe::Graphe(int nsommet):_nsommet(nsommet+2)
{
    _MAdj = new bool*[_nsommet];
    _MVal = new int*[_nsommet];
    _duree = new int[_nsommet];
    _dpt = new int[_nsommet];
    _dpta = new int[_nsommet];
    for(int i(0);i<_nsommet;i++)
    {
        _MAdj[i] = new bool[_nsommet];
        _MVal[i] = new int[_nsommet];
    }
    
    for(int i(0);i<_nsommet;i++)
        for(int j(0);j<_nsommet;j++)
        {
            _MAdj[i][j] = false;
            _MVal[i][j] = 0;
        }
    
}

Graphe::Graphe(ifstream *source)
{
    *source>>_nsommet;
    _nsommet+= 2;
    
    _MAdj = new bool*[_nsommet];
    _MVal = new int*[_nsommet];
    _duree = new int[_nsommet];
    _dpt = new int[_nsommet];
    _dpta = new int [_nsommet];
    
    for(int i(0);i<_nsommet;i++)
    {
        _duree[i] = 0;
        _dpt[i] = -1;
        _dpta[i] = -1;
        
        _MAdj[i] = new bool[_nsommet];
        _MVal[i] = new int[_nsommet];
    }
    
    _dpt[0]=0;
    
    for(int i(0);i<_nsommet;i++)
        for(int j(0);j<_nsommet;j++)
        {
            _MAdj[i][j] = false;
            _MVal[i][j] = 0;
        }
    
    int sommet,contrainte;
    
    *source>>sommet;
    while(sommet != -1)
    {
        *source>>_duree[sommet];
        
        *source>>contrainte;
        if (contrainte == -1)
        {
            _MAdj[0][sommet] = true;
            _MVal[0][sommet] = 0;
        }
        else{
            
        
        while(contrainte != -1)
        {
            _MAdj[contrainte][sommet] = true;
            //std::cout<<"("<<sommet<<" -> "<<contrainte<<" = "<<_duree[sommet]<<" : "<<_MVal[sommet][contrainte]<<" : "<<_MAdj[sommet][contrainte]<<" )"<<std::endl;
            *source>>contrainte;
        }
        }
        *source>>sommet;
    }
        //on remplit MVal avec les durées
        for (int i(0);i<_nsommet;i++)
            for(int j(0);j<_nsommet;j++)
            {
                _MVal[i][j] = _duree[i];
            }
    
    
    for(int i(0);i<_nsommet-1;i++)
    {
        bool final = true;
        for( int j(0);j<_nsommet;j++)
        {
            if(_MAdj[i][j] == true)
                final = false;
   
        }
        if(final == true)
            _MAdj[i][_nsommet-1] = true;
    }
    
}

bool Graphe::detectCircuit() const {
    int i,x,y,z;
    bool circuit = false;
    bool Mc [_nsommet][_nsommet]; //matrice de fermture transitive.
    
    for(int i(0);i<_nsommet;i++)
        for(int j(0);j<_nsommet;j++)
            Mc[i][j] = false;       //init. de la matrice a false;
    
    for(x=0;x<this->_nsommet;x++)
    {
        for(y=0;y<this->_nsommet;y++)
        {
            for(z=0;z<this->_nsommet;z++)
            {
                //std::cout << "-> " << x << ", " << y << ", " << z << std::endl;
               // std::cout << "{" <<this->_MAdj[x][y]<<" , " << this->_MAdj[y][z] << "}" << std::endl;
                
                if (this->_MAdj[x][y]==1 && this->_MAdj[y][z]==1)       // si x->y existe et y->z existe
                {
                    Mc[x][z] = true;                //alors x->z existe
                }
            }
        }
    }
    
    for(i=0;i<this->_nsommet;i++)
    {
        if (Mc[i][i] == true)       //après avoir fait la fermeture transitive on regarde la diago
            circuit = true;     // si il y'a un true sur la diago (MAdj) alors il y'a un circuit.
    }
    
    // if(circuit==true)
      //  std::cout<< "Circuit" << std::endl;
   // else
       // std::cout << "PAS DE CIRCUIT" << std::endl;
    
    return circuit;             // on retourne le booléen (circuit or not)
}

void Graphe::print_graph(){
	for(int i(0);i<_nsommet;i++)
    {
        for(int j(0);j<_nsommet;j++)
        {
            if(_MAdj[i][j])
                std::cout<<_MVal[i][j]<<" ";
            else
                std::cout<<"X ";
        }
        std::cout<<std::endl;
        
    }
}

void Graphe::addConstraint(int sommet, int constraint)
{
    _MAdj[constraint][sommet] = true;
}

void Graphe::removeConstraint(int sommet, int constraint)
{
    _MAdj[constraint][sommet] = false;
}

int Graphe::earlyDate(int tache)
{
    if (!detectCircuit())
    {
    vector<int> dates;
    for(int i(0);i<_nsommet;i++)
    {
        if(_MAdj[i][tache] == true && _dpt[i] != -1)
            dates.push_back(_MVal[i][tache] +_dpt[i]);
        else if(_MAdj[i][tache] == true && _dpt[i] == -1)
        {
            this->earlyDate(i);
            dates.push_back(_MVal[i][tache] +_dpt[i]);
        }
        else
        {}
        
    }
    _dpt[tache] = max(dates);
    return _dpt[tache];
    }
    else
    {
        std::cerr<<"il y'a un circuit."<<std::endl;
        return -1;
    }
}

