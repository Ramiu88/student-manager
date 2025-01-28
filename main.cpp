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


class etudiant : public personne
{
   private:

   string id_etudiant;
   vector <cours> etudiant_cours;


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
        cout << "L'id de cours est : "<<etudiant_cours[i].get_id_cours()<<endl;
        cout << "Le nom du cours est : "<<etudiant_cours[i].get_nom()<<endl;
     }
   }

   string obtenir_role()
   {
      return "Etudiant";
   }


   void inscrire_cours(cours user_cours)
   {
      auto pos = find(etudiant_cours.begin(),etudiant_cours.end(),user_cours);

          if(pos != etudiant_cours.end())
          {
              cout << "Etudiant cours deja existe" << endl;
              return;
          }

           etudiant_cours.push_back(user_cours);
       
   }


   void desinscrire_cours(cours user_cours)
   {
     int i;
      auto pos = find(etudiant_cours.begin(),etudiant_cours.end(),user_cours);

          if(pos == etudiant_cours.end())
          {
              cout << "Ce cours n'existe pas" << endl;
              return;
          }


           else
           {

              for(i = 0;i < etudiant_cours.size();i++)
              {
                 if(etudiant_cours[i].get_id_cours() == user_cours.get_id_cours())
                 {
                      break;
                 }
              }

                etudiant_cours.erase(etudiant_cours.begin()+i);

           }    
   }

   string& get_id_etudiant()
   {
     return id_etudiant;
   }

   void set_nom(string nom)
   {
     this->nom = nom;
   }

   void set_age(int age)
   {
     this->age  = age;
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
};


class gestionnaire_etudiants
{
   private:

   vector <etudiant> etudiants;
   vector <enseignant> enseignants;

   public:

   void ajouter_etudiant(etudiant user_etudiant)
   {
       auto pos = find(etudiants.begin(),etudiants.end(),user_etudiant);

        if(pos != etudiants.end())
        {
             cout << "Etudiant deja exist"<<endl;
             return;
        }

          etudiants.push_back(user_etudiant);
   }

   void ajouter_enseignant(enseignant user_enseignant)
   {
       auto pos = find(enseignants.begin(),enseignants.end(),user_enseignant);

        if(pos != etudiants.end())
        {
             cout << "Enseignant deja exist"<<endl;
             return;
        }

          enseignants.push_back(user_enseignant);
   }

   etudiant trouver_etudiant(string user_id_etudiant)
   {

    int i;

      for(i = 0;i < etudiants.size();i++)
      {
         if(etudiants[i].get_id_etudiant() == user_id_etudiant)
         {
            break;
         }
      }

          return etudiants[i];
   }

   void afficher_tous_etudiants()
   {
       for(int i = 0;i < etudiants.size();i++)
       {
          
       }
   }

   void afficher_tous_enseignants()
   {
     for(int i = 0;i < enseignants.size();i++)
     {
       
     }
   }

};





int main()

{



  return 0;
}












