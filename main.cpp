#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;


class personne
{
  protected:

  string nom;
  int age;

  public:

  virtual void afficher() = 0;
  virtual string obtenir_role() = 0;
};


class cours
{
   private:

   string id_cours;
   string nom_cours;

   public:

   string& get_id_cours()
   {
     return id_cours;
   }

   string& get_nom()
   {
     return nom_cours;
   }

   
};


class note
{
   private:
   float grade = 0;
   
   public:

   note(float grade)
   {
      this->grade = grade;
   }
   float& get_grade()
   {
     return grade;
   }
};


class etudiant : public personne
{
   private:

   string id_etudiant;
   vector <cours> etudiant_cours;
   vector <note> etudiant_notes;


   public:

   etudiant(string nom,int age,string id_etudiant)
   {
     this->id_etudiant = id_etudiant;
     this->nom = nom;
     this->age = age;

   }

   etudiant(string nom,int age)
   {
     this->nom = nom;
     this->age = age;

   }

   void afficher()
   {
     cout << "Id de l'etudiant est : "<<id_etudiant<<endl;
     cout << "Le nom de l'etudiant est : "<<nom<<endl;
     cout << "L'age de l'etudiant est : "<<age<<endl;
     for(int i = 0;i < etudiant_cours.size();i++)
     {
        // to modify this when overleading <<
        cout << "L'id de cours est : "<<etudiant_cours[i].get_id_cours()<<endl; 
        cout << "Le nom du cours est : "<<etudiant_notes[i].get_grade()<<endl;
     }
   }

   string obtenir_role()
   {
      return "Etudiant";
   }


   void inscrire_cours(cours user_cours)
   {
      for(int i = 0;i < etudiant_cours.size();i++)
      {
         if(etudiant_cours[i].get_id_cours() == user_cours.get_id_cours())
         {
             cout << "Etudiant cours deja existe"<<endl;
             return;
         }
      }

       etudiant_cours.push_back(user_cours);
       
   }


   void desinscrire_cours(cours user_cours)
{
    for (int i = 0; i < etudiant_cours.size(); i++) {
        if (etudiant_cours[i].get_id_cours() == user_cours.get_id_cours()) {
            etudiant_cours.erase(etudiant_cours.begin() + i);
            return;
        }
    }
    cout << "Ce cours n'existe pas" << endl;
}


   void ajouter_note(float user_note, cours user_cours)
{
    for (int i = 0; i < etudiant_cours.size(); i++) {
        if (etudiant_cours[i].get_id_cours() == user_cours.get_id_cours()) 
        {
            if (etudiant_notes[i].get_grade() == 0) 
            {  
                etudiant_notes[i].get_grade() = user_note;
            } else 
            {
                cout << "Le cours " << etudiant_cours[i].get_nom() << " a deja une note" << endl;
            }
            return;
        }
    }
    cout << "Ce cours n'existe pas" << endl;
}


   void ajouter_cours(cours user_cours)
   {
       etudiant_cours.push_back(user_cours);
   }

   string& get_id_etudiant()
   {
     return id_etudiant;
   }

   vector <cours>& get_etudiant_cours()
   {
      return etudiant_cours;
   }

   vector <note>& get_etudiant_notes()
   {
     return etudiant_notes;
   }

};


class enseignant : public personne
{
   private:

   string id_enseignant;
   vector <string> sujets;

   public:

   enseignant(string nom,int age,string id_enseigant)
   {
     this->nom = nom;
     this->age = age;
     this->id_enseignant = id_enseigant;
   }

   void afficher()
   {
     cout << "L'id de l'enseigant est : "<<id_enseignant<<endl;
     for(int i = 0;i < sujets.size();i++)
     {
       cout <<sujets[i]<<" | "<<endl;
     }

     cout << "Le nom de l'enseigant est : "<<nom<<endl;
     cout << "L'age de l'enseignant est : "<<age<<endl;

   }

   string obtenir_role()
   {
     return "Enseignant";
   }

   void ajouter_sujet(string user_sujet)
   {
     

      auto pos = find(sujets.begin(),sujets.end(),user_sujet);

         if(pos != sujets.end())
         {
            cout << "Suject deja existe"<<endl;
            return;
         }

           sujets.push_back(user_sujet);
   }

   void retirer_sujet(string user_sujet)
   {

     int i;

      auto pos = find(sujets.begin(),sujets.end(),user_sujet);

        if(pos == sujets.end())
        {
           cout << "ce sujet n'existe pas"<<endl;
           return; 
        }

        else

         {
            for(i = 0;i < sujets.size();i++)
              {
                 if(sujets[i] == user_sujet)
                 {
                      break;
                 }
              }

                sujets.erase(sujets.begin()+i);
         }
   }   


   string &get_id_enseignant()
   {
      return id_enseignant;
   }
};


class gestionnaire_etudiants
{
   private:

   vector <etudiant> etudiants;
   vector <enseignant> enseignants;

   public:

   void ajouter_etudiant(etudiant user_etudiant)
{
    for (int i = 0; i < etudiants.size(); i++) {
        if (etudiants[i].get_id_etudiant() == user_etudiant.get_id_etudiant()) {
            cout << "Etudiant deja existe" << endl;
            return;
        }
    }
    etudiants.push_back(user_etudiant);
}

   void ajouter_enseignant(enseignant user_enseignant)
{
    for (int i = 0; i < enseignants.size(); i++) 
    {
        if (enseignants[i].get_id_enseignant() == user_enseignant.get_id_enseignant()) 
        {
            cout << "Enseignant deja existe" << endl;
            return;
        }
    }
    enseignants.push_back(user_enseignant);
}


   etudiant trouver_etudiant(string user_id_etudiant)
{
    for (int i = 0; i < etudiants.size(); i++) 
    {
        if (etudiants[i].get_id_etudiant() == user_id_etudiant) 
        {
            return etudiants[i];
        }
    }
    cout << "Etudiant no trouve" << endl;
}

enseignant trouver_enseignant(string user_id_enseigant)
{
    for (int i = 0; i < enseignants.size(); i++) 
    {
        if (enseignants[i].get_id_enseignant() == user_id_enseigant) 
        {
            return enseignants[i];
        }
    }
    cout << "Etudiant no trouve" << endl;
}


   void afficher_tous_etudiants()
   {
       for(int i = 0;i < etudiants.size();i++)
       {
          etudiants[i].afficher();
       }
   }

   void afficher_tous_enseignants()
   {
     for(int i = 0;i < enseignants.size();i++)
     {
        enseignants[i].afficher();
     }
   }

   void supprimer_etudiant(string user_id_etudiant)
{
    for (int i = 0; i < etudiants.size(); i++)
     {
        if (etudiants[i].get_id_etudiant() == user_id_etudiant) 
        {
            etudiants.erase(etudiants.begin() + i);
            return;
        }
    }
    cout << "Etudiant n'existe pas" << endl;
}


   void mettre_a_jour_notes_etudiant(string user_id_etudiant,string user_id_cours,float user_grade)
   {
      bool b = false;

      for(int i = 0;i < etudiants.size();i++)
      {
          if(etudiants[i].get_id_etudiant() == user_id_etudiant)
          {

          
         for(int j = 0;j < etudiants[i].get_etudiant_cours().size();j++)
         {
            if(etudiants[i].get_etudiant_cours()[j].get_id_cours() == user_id_cours)
            {
               etudiants[i].get_etudiant_notes()[j].get_grade() = user_grade;
               cout << "Note mise a jour pour l'etudiant" << user_id_etudiant << "dans le cours " << user_id_cours << endl;
               b = true;
               break;
            }
         }

          if(b == false)
          {
            cout << "le cours " << user_id_cours << "n'est pas trouve "<< "pour l'etudiant" << user_id_etudiant<<endl;
          }
      }
       else
       {
           cout << "L'étudiant avec l'ID " << user_id_etudiant << " n'a pas été trouvé." << endl;
       }
   }

   }
};



int main()
{
    int option;

    cout << "------------------------------------------------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Gestion des Etudiants" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "1. Ajouter un etudiant" << endl;
    cout << "2. Ajouter un enseignant" << endl;
    cout << "3. Trouver un etudiant" << endl;
    cout << "4. Afficher tous les etudiants" << endl;
    cout << "5. Afficher tous les enseignants" << endl;
    cout << "6. Inscrire un etudiant a un cours" << endl;
    cout << "7. Desinscrire un etudiant d'un cours" << endl;
    cout << "8. Ajouter un sujet a un enseignant" << endl;
    cout << "9. Retirer un sujet d'un enseignant" << endl;
    cout << "10. Ajouter une note a un etudiant" << endl;
    cout << "11. Afficher les notes d'un etudiant" << endl;
    cout << "12. Supprimer un etudiant du systeme" << endl;
    cout << "14. Mettre a jour les notes d'un etudiant" << endl;
    cout << "15. Quitter" << endl;

    cout << "------------------------------------------------------" << endl;
    cout << "------------------------------------------------------" << endl;

    gestionnaire_etudiants gestionnaire;  // Create the main manager object

    do
    {
        cout << "Entrez votre choix : " << endl;
        cin >> option;

        switch (option)
        {
            case 1: {
                string nom, id_etudiant;
                int age;
                cout << "Entrez le nom de l'etudiant : ";
                cin >> nom;
                cout << "Entrez l'age de l'etudiant : ";
                cin >> age;
                cout << "Entrez l'id de l'etudiant : ";
                cin >> id_etudiant;

                etudiant new_etudiant(nom, age, id_etudiant);  // Create the student object
                gestionnaire.ajouter_etudiant(new_etudiant);    // Add the student to the manager
                break;
            }

            case 2: {
                string nom, id_enseignant;
                int age;
                cout << "Entrez le nom de l'enseignant : ";
                cin >> nom;
                cout << "Entrez l'age de l'enseignant : ";
                cin >> age;
                cout << "Entrez l'id de l'enseignant : ";
                cin >> id_enseignant;

                enseignant new_enseignant(nom, age, id_enseignant);  
                break;
            }

            case 3: {
                string id_etudiant;
                cout << "Entrez l'id de l'etudiant a trouver : ";
                cin >> id_etudiant;
                etudiant etu = gestionnaire.trouver_etudiant(id_etudiant);  
                etu.afficher();  
                break;
            }

            case 4:
                gestionnaire.afficher_tous_etudiants();  
                break;

            case 5:
                gestionnaire.afficher_tous_enseignants();  
                break;

            case 6: {
                string id_etudiant, id_cours;
                cout << "Entrez l'id de l'etudiant : ";
                cin >> id_etudiant;
                cout << "Entrez l'id du cours : ";
                cin >> id_cours;

                etudiant etu = gestionnaire.trouver_etudiant(id_etudiant);  
                cours new_cours; 
                etu.inscrire_cours(new_cours);
                break;
            }

            case 7: {
                string id_etudiant, id_cours;
                cout << "Entrez l'id de l'etudiant : ";
                cin >> id_etudiant;
                cout << "Entrez l'id du cours : ";
                cin >> id_cours;

                etudiant etu = gestionnaire.trouver_etudiant(id_etudiant); 
                cours cours_a_desinscrire;  
                etu.desinscrire_cours(cours_a_desinscrire);  
                break;
            }

            case 8: {
                string id_enseignant, sujet;
                cout << "Entrez l'id de l'enseignant : ";
                cin >> id_enseignant;
                cout << "Entrez le sujet a ajouter : ";
                cin >> sujet;

                enseignant ens = gestionnaire.trouver_enseignant(id_enseignant);  
                ens.ajouter_sujet(sujet);  
                break;
            }

            case 9: {
                string id_enseignant, sujet;
                cout << "Entrez l'id de l'enseignant : ";
                cin >> id_enseignant;
                cout << "Entrez le sujet a retirer : ";
                cin >> sujet;

                enseignant ens = gestionnaire.trouver_enseignant(id_enseignant); 
                ens.retirer_sujet(sujet);  
                break;
            }

            case 10: {
                string id_etudiant, id_cours;
                float grade;
                cout << "Entrez l'id de l'etudiant : ";
                cin >> id_etudiant;
                cout << "Entrez l'id du cours : ";
                cin >> id_cours;
                cout << "Entrez la note : ";
                cin >> grade;

                etudiant etu = gestionnaire.trouver_etudiant(id_etudiant); 
                cours new_cours;  
                etu.ajouter_note(grade, new_cours);  
                break;
            }

            case 11: {
                string id_etudiant;
                cout << "Entrez l'id de l'etudiant : ";
                cin >> id_etudiant;

                etudiant etu = gestionnaire.trouver_etudiant(id_etudiant);  
                etu.afficher();  
                break;
            }

            case 12: {
                string id_etudiant;
                cout << "Entrez l'id de l'etudiant a supprimer : ";
                cin >> id_etudiant;

                gestionnaire.supprimer_etudiant(id_etudiant);  
                break;
            }

            case 13: {
                string id_etudiant, id_cours;
                float grade;
                cout << "Entrez l'id de l'etudiant : ";
                cin >> id_etudiant;
                cout << "Entrez l'id du cours : ";
                cin >> id_cours;
                cout << "Entrez la nouvelle note : ";
                cin >> grade;

                gestionnaire.mettre_a_jour_notes_etudiant(id_etudiant, id_cours, grade);  
                break;
            }

            case 14:
                cout << "Au revoir!" << endl;
                break;

            default:
                cout << "Option invalide." << endl;
        }
    } while (option != 14);  

    return 0;
}




