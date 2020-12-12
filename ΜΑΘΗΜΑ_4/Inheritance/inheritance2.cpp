/*
A. Κατασκευάστε την ακόλουθη ιεραρχία. Την υπερκλάση person (άτομο) με πεδίο
δεδομένων age (ηλικία) και τις υποκλάσεις της person: teacher (καθηγητής) με πεδίο
δεδομένων profession (εξειδίκευση) και footballer (ποδοσφαιριστής) με πεδίο δεδομένων
team (ομάδα).
B. Δημιουργήστε από έναν κατασκευαστή σε κάθε κλάση και έναν virtual καταστροφέα στην
κλάση person.
Γ. Προσθέστε τις κατάλληλες μεθόδους έτσι ώστε να μπορεί να κληθεί η συνάρτηση
compute_earnings (υπολογισμός εσόδων) και να επιστρέφει την τιμή 1000.0 για τα
αντικείμενα teacher και 100000.0 για τα αντικείμενα footballer.
Δ. Προσθέστε στην κλάση person στατική μεταβλητή με όνομα number_of_instances που
θα καταμετρά το πλήθος των αντικειμένων τύπου person (ή των υποτύπων της) που θα
δημιουργούνται. Εμφανίστε το πλήθος στη main.
Ε. Στη main, δημιουργήστε έναν πίνακα 5 θέσεων που ο χρήστης θα γεμίζει με δείκτες προς
αντικείμενα teacher ή footballer πραγματοποιώντας εισαγωγή τιμών από το πληκτρολόγιο.
ΣΤ. Στη main, καλέστε τη συνάρτηση compute_earnings για κάθε στοιχείο του πίνακα και
εμφανίστε τα αποτελέσματα.
*/

#include <iostream>
#include <ctime>
#include <random>

class person
{
    protected:
      int age;
    public:
      person(int a):age(a) {}
      virtual ~person() {}
      virtual void show()
      {
          std::cout<<"Age:"<<this->age<<std::endl;
      }
};

class teacher:public person
{
   private:
     std::string profession;
   public:
     teacher(int a,std::string p):person(a),profession(p) {}
     ~teacher() {}
      double compute_earnings()
      {
          return 1000.0;
      }
      void show()
      {
          std::cout<<"Age:"<<this->age<<"\t"<<"Profession:"<<this->profession<<"\tEarnings:"<<this->compute_earnings()<<std::endl;
      }
};

class footballer:public person{
   private:
     std::string team;
   public:
     footballer(int a,std::string t):person(a),team(t) {}
     ~footballer() {}
     double compute_earnings()
     {
         return 100000.0;
     }
     void show()
      {
          std::cout<<"Age:"<<this->age<<"\t"<<"Team:"<<this->team<<"\tEarnings:"<<this->compute_earnings()<<std::endl;
      }
};

int main()
{
    person *p[5];
    int age;
    std::string t,prof;
    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution <int> choice(0,1);
    for(int i=0;i<5;i++)
    {
        if(choice(mt)==0)
        {
            std::cout<<"Give age of teacher:";
            std::cin>>age;
            std::cout<<"Give profession of teacher:";
            std::cin>>prof;
            p[i]=new teacher(age,prof);
        }
        else
        {
           std::cout<<"Give age of footaballer:";
            std::cin>>age;
            std::cout<<"Give team of footballer:";
            std::cin>>t;
            p[i]=new footballer(age,t);
        }
      std::cout<<std::endl<<std::endl;  
    }
    for(int i=0;i<5;i++)
    {
       p[i]->show();
    }
    return 0;
}