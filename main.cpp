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
   string nom;

   public:

   
};


class etudiant : public personne
{
   private:

   string id_etudiant;
   vector <cours> etudiant_cours;


   public:


};












int main()

{




  return 0;
}