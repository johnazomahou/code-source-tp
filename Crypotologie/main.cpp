#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string clee;
    string element_a_crypte;
    string tab{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string resultat;


        cout<<"Entrer La clee de cryptologie"<<endl;
        cin>>clee;
        cout<<"Entrer l'element a crypte"<<endl;
        cin>>element_a_crypte;






     int nombre_char_clee(clee.length());
     int nombre_char_element_crypte(element_a_crypte.length());

     int tab_code_ascci[nombre_char_clee];



     for(int i=0;i<nombre_char_clee;i++){
        tab_code_ascci[i]=int(toupper(clee[i]));
       // cout<<tab_code_ascci[i]<<endl;
     }
         //je recupere le code ascci des charactere dans mon tableau

         /*================== Pre -Traitement===============*/

         char table_valeur_disponible[26][nombre_char_clee];

        /*==================Remplissage des valeurs disponibles===============*/


   for(int i=0;i<26;i++){
       cout<<tab[i];
   }
   cout<<" "<<endl;
   for(int i=0;i<nombre_char_clee;i++){

       /*================== j'initialise le premier element avec le premier code ascii===============*/

       table_valeur_disponible[0][i]=char(tab_code_ascci[i]);

       cout<<endl;
       cout<< table_valeur_disponible[0][i];
        for(int j=1;j<26;j++){

            if(table_valeur_disponible[j-1][i]==90){
                table_valeur_disponible[j][i]=65;


            }else{
                table_valeur_disponible[j][i]= table_valeur_disponible[j-1][i]+1;
                cout<<table_valeur_disponible[j][i];
            }


      }
   }

/*================== Traitement ===============*/

    int index(0);

    //index  prend la ligne ou on est et quand on fini la ligne il reprend à 0
      for(int i=0;i<nombre_char_element_crypte;i++){

            if(element_a_crypte[i]==' '){
                resultat=resultat+' ';
            }
            else{
                resultat=resultat+table_valeur_disponible[tab.find(element_a_crypte[i])][index];
            }
          // remettre a zéro l'indice de la ligne si on atteint la fin de la ligne
        if(index==nombre_char_clee-1){
            index=0;
        }else{
          index=index+1;
        }
   }
cout<<""<<endl;
cout<<"Resultat:"<<resultat<<endl;
}








