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
    
    char action('0');

        cout<<"Ce programme vous permet de resoudre un probleme d'ordonancement (calendrier)."<<endl;
    cout<<"Vous pouvez ouvrir un fichier texte contenant votre liste de contrainte."<<endl<<endl;
                string adr;
                cout<<"entrez l'adresse du fichier txt : ";
                cin>>adr;
                 ifstream source(adr, ios::in);
                Graphe calendar(&source);
         
        
    do{
    
        while(action != 'c'){
            
        calendar.print_graph();
        cout<<endl;
        if(calendar.detectCircuit() == true)
        {
            cout<<"/!\\ ATTENTION : il y'a un circuit."<<endl;
        }
        cout<<"souhaitez vous modifier le graphe ? ('a' pour ajouter une contrainte, 'r' pour retirer une contrainte 'c' pour continuer";
        cin>>action;
        int tache,contrainte;
        switch (action) {
            case 'a':
                
                cout<<"ajouter une contrainte (tache contrainte): ";
                cin>>tache>>contrainte;
                calendar.addConstraint(tache, contrainte);
                break;
            case 'r' :
                cout<<"retirer une contrainte (tache contrainte): ";
                cin>>tache>>contrainte;
                calendar.removeConstraint(tache, contrainte);
                break;
            case 'c' :
                action = 'c';
                break;
                
            default:
                break;
        }
    }
        
    calendar.print_dpt();
    cout<<endl;
    calendar.print_dpta();
    cout<<"'r'ecommencer ou 'q'uitter ?";
    cin>>action;
    }while(action != 'q' && action != 'Q');
    
    cout<<"fin du programme.";
    
    
    return 0;
}

