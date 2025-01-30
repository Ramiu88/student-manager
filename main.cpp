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
   
   void set_nom(string user_nom)
   {
      this->nom_cours = user_nom;
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
    vector<etudiant> etudiants;
    vector<enseignant> enseignants;
    vector<cours> cours;
    gestionnaire_etudiants gestion;  

    int choix;
    do {
        cout << "Menu:" << endl;
        cout << "1. Ajouter un étudiant" << endl;
        cout << "2. Supprimer un étudiant" << endl;
        cout << "3. Afficher les étudiants" << endl;
        cout << "4. Ajouter un enseignant" << endl;
        cout << "5. Supprimer un enseignant" << endl;
        cout << "6. Afficher les enseignants" << endl;
        cout << "7. Ajouter un cours" << endl;
        cout << "8. Supprimer un cours" << endl;
        cout << "9. Afficher les cours" << endl;
        cout << "10. Ajouter une note à un étudiant" << endl;
        cout << "11. Afficher les notes d'un étudiant" << endl;
        cout << "12. Inscrire un étudiant à un cours" << endl;
        cout << "13. Désinscrire un étudiant d'un cours" << endl;
        cout << "14. Afficher les étudiants inscrits à un cours" << endl;
        cout << "15. Quitter" << endl;
        cout << "Entrez votre choix: ";
        cin >> choix;

        switch (choix) 
        {
            case 1: 
            {
                string nom, id;
                int age;
                cout << "Nom de l'étudiant: ";
                cin >> nom;
                cout << "Age de l'étudiant: ";
                cin >> age;
                cout << "ID de l'étudiant: ";
                cin >> id;
                etudiants.push_back(etudiant(nom, age, id));
                break;
            }
            case 2: 
            {
                string id;
                cout << "ID de l'étudiant à supprimer: ";
                cin >> id;
                for (int i = 0; i < etudiants.size(); ++i) 
                {
                    if (etudiants[i].get_id_etudiant() == id) 
                    {
                        etudiants.erase(etudiants.begin() + i);
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                for (int i = 0; i < etudiants.size(); ++i) 
                {
                    etudiants[i].afficher();
                }
                break;
            }
            case 4: 
            {
                string nom, id_enseignant;
                int age;
                cout << "Nom de l'enseignant: ";
                cin >> nom;
                cout << "Age de l'enseignant: ";
                cin >> age;
                cout << "ID de l'enseignant: ";
                cin >> id_enseignant;
                enseignants.push_back(enseignant(nom, age, id_enseignant));
                break;
            }
            case 5: 
            {
                string nom;
                cout << "Nom de l'enseignant à supprimer: ";
                cin >> nom;
                for (int i = 0; i < enseignants.size(); ++i) 
                {
                    if (enseignants[i].get_id_enseignant() == nom) 
                    {
                        enseignants.erase(enseignants.begin() + i);
                        break;
                    }
                }
                break;
            }
            case 6:
            {
                for (int i = 0; i < enseignants.size(); ++i) 
                {
                    enseignants[i].afficher();
                }
                break;
            }
            case 7:
                  {
                  string nom;
                  cout << "Nom du cours: ";
                  cin >> nom;

    
                  cours ne_cours;
                  ne_cours.set_nom(nom);

    
                  cours.push_back(ne_cours);
                  break;
                  }

            case 8: 
            {
                string nom;
                cout << "Nom du cours à supprimer: ";
                cin >> nom;
                for (int i = 0; i < cours.size(); ++i) 
                {
                    if (cours[i].get_nom() == nom) 
                    {
                        cours.erase(cours.begin() + i);
                        break;
                    }
                }
                break;
            }
            case 9: 
            {
                for (int i = 0; i < cours.size(); ++i) 
                {
                    cout << cours[i].get_nom() << endl;
                }
                break;
            }
            case 10: 
            {
                string id_etudiant;
                float grade;
                string nom_cours;
                cout << "ID de l'étudiant: ";
                cin >> id_etudiant;
                cout << "Nom du cours: ";
                cin >> nom_cours;
                cout << "Note à ajouter: ";
                cin >> grade;
                for (int i = 0; i < etudiants.size(); ++i) 
                {
                    if (etudiants[i].get_id_etudiant() == id_etudiant) 
                    {
                        for (int j = 0; j < cours.size(); ++j) 
                        {
                            if (cours[j].get_nom() == nom_cours) 
                            {
                                etudiants[i].ajouter_note(grade, cours[j]);
                            }
                        }
                    }
                }
                break;
            }
            case 11: 
            {
                string id_etudiant;
                cout << "ID de l'étudiant: ";
                cin >> id_etudiant;
                for (int i = 0; i < etudiants.size(); ++i) 
                {
                    if (etudiants[i].get_id_etudiant() == id_etudiant) 
                    {
                        for (int j = 0; j < etudiants[i].get_etudiant_notes().size(); ++j) 
                        {
                            cout << "Note: " << etudiants[i].get_etudiant_notes()[j].get_grade() << endl;
                        }
                    }
                }
                break;
            }
            case 12: 
            {
                string id_etudiant, nom_cours;
                cout << "ID de l'étudiant: ";
                cin >> id_etudiant;
                cout << "Nom du cours: ";
                cin >> nom_cours;
                for (int i = 0; i < etudiants.size(); ++i) 
                {
                    if (etudiants[i].get_id_etudiant() == id_etudiant) 
                    {
                        for (int j = 0; j < cours.size(); ++j) 
                        {
                            if (cours[j].get_nom() == nom_cours) 
                            {
                                etudiants[i].inscrire_cours(cours[j]);
                            }
                        }
                    }
                }
                break;
            }
            case 13: 
            {
                string id_etudiant, nom_cours;
                cout << "ID de l'étudiant: ";
                cin >> id_etudiant;
                cout << "Nom du cours: ";
                cin >> nom_cours;
                for (int i = 0; i < etudiants.size(); ++i) 
                {
                    if (etudiants[i].get_id_etudiant() == id_etudiant) 
                    {
                        for (int j = 0; j < cours.size(); ++j) 
                        {
                            if (cours[j].get_nom() == nom_cours) 
                            {
                                etudiants[i].desinscrire_cours(cours[j]);
                            }
                        }
                    }
                }
                break;
            }
            case 14: 
            {
                string nom_cours;
                cout << "Nom du cours: ";
                cin >> nom_cours;
                for (int i = 0; i < cours.size(); ++i) 
                {
                    if (cours[i].get_nom() == nom_cours) 
                    {
                        for (int j = 0; j < etudiants.size(); ++j) 
                        {
                            for (int k = 0; k < etudiants[j].get_etudiant_cours().size(); ++k) 
                            {
                                if (etudiants[j].get_etudiant_cours()[k].get_nom() == nom_cours) 
                                {
                                    cout << etudiants[j].get_id_etudiant() << " est inscrit à ce cours." << endl;
                                }
                            }
                        }
                    }
                }
                break;
            }
            case 15:
                cout << "Quitter le programme." << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
                break;
        }
    } while (choix != 15);

    return 0;
}
