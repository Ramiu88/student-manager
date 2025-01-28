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
      
   }


};












int main()

{




  return 0;
}