/*
Δημιουργήστε την κλάση “Φοιτητής”. Η κλάση θα περιέχει τα ακόλουθα χαρακτηριστικά:
⚫ ΑΜ (string)
⚫ Ονοματεπώνυμο (string)
⚫ Τρέχον εξάμηνο ( int)
⚫ Αριθμός Περασμένων Μαθημάτων (int)
⚫ Πίνακας Βαθμών Περασμένων Μαθημάτων (vector <float>)
Η κλάση θα υποστηρίζει κατασκευή αντικειμένου με τους ακόλουθους τρόπους:
⚫ Ορίζοντας ΑΜ και Ονοματεπώνυμο . Σε αυτή την περίπτωση το τρέχον εξάμηνο
του φοιτητή θα είναι 1 και δεν θα έχει περάσει κάποιο μάθημα.
⚫ Ορίζοντας ΑΜ, Ονοματεπώνυμο και Εξάμηνο. Σε αυτή την περίπτωση ο φοιτητής
δεν θα έχει περάσει κάποιο μάθημα.
⚫ Ορίζοντας τιμές σε όλα τα χαρακτηριστικά.
⚫ Ορίζοντας σε όλα τα χαρακτηριστικά ως τιμές τις τιμές των χαρακτηριστικών ενός
άλλου “Φοιτητή”
Η κλάση θα παρέχει getters και setters για όλα τα χαρακτηριστικά της. Επιπλέον θα
μπορεί να εκτελέσει τις ακόλουθες λειτουργίες:
⚫ Εισαγωγή νέου βαθμού στον πίνακα βαθμών περασμένων μαθημάτων
⚫ Εκτύπωση των 3 πρώτων χαρακτηριστικών, σε μία γραμμή, σε οποιοδήποτε
κανάλι (οstream)
⚫ Εκτύπωση αναλυτικής βαθμολογίας σε κανάλι. Αντί για λεκτικό μαθήματος
χρησιμοποιήστε τις συμβολοσειρές “Μάθημα 1” , “Μάθημα 2”, κοκ. Η αναλυτική
βαθμολογία θα πρέπει να περιέχει και τον μέχρι στιγμής μέσο όρο του φοιτητή.
Στην main:
-εισάγεται σε ένα vector μαθητές της επιλογής σας,και βαθμολογίες της επιλογής σας
-Εμφάνιση αναλυτικής βαθμολογίας  
*/

#include <iostream>
#include <sstream>
#include <numeric>
#include <exception>
#include <thread>
#define SIZE 10
#include <random>

int seed()
{
    std::string time=__TIME__;
    std::stringstream ss(time);
    std::string word;
    while(std::getline(ss,word,':')) {}
    return std::stoi(word);
}

class undefiniedgrade:public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "Grade over number 10 or below number 0 detected please insert a valid number";
    }
}exc;

class student
{
    private:
      std::string am;
      std::string name;
      int semester;
      int pass;
      std::vector <float> grades;
    public:
      student(std::string id,std::string n,int s):am(id),name(n),semester(s) {if(s==1) {pass=0;}}
      student(std::string id,std::string n,int s,int p):am(id),name(n),semester(s),pass(p) {
          std::mt19937 mt(seed());
          std::uniform_real_distribution <float> grdsf(0.0,4.99);
          std::uniform_int_distribution <int>  fls(0,10);
          std::uniform_real_distribution <float> grds(5.0,10.0);
          int sz=fls(mt);
          for(int i=0;i<sz;i++)
          {
              grades.push_back(grdsf(mt));
          }
          for(int i=0;i<pass;i++)
          {
               grades.push_back(grds(mt));  
          }
      }
      //copy constructor
      student(const student &s):am(s.am),name(s.name),semester(s.semester),pass(s.pass),grades(s.grades) {}
      //εισαγωγή βαθμού στον πίνακα βαθμών ενός φοιτητή.
      void add_grade(float &gr) {
          try
          {
              if(gr>10.0 || gr<0.0) throw exc;
              grades.push_back(gr);
          }
          catch(const std::exception& e)
          {
              std::cerr << e.what() << '\n';
          }
     }
     double find_average()
     {
        return std::accumulate(this->grades.begin(),this->grades.end(),0.0)/this->grades.size();
     }
     friend std::ostream &operator<<(std::ostream &os,student &s)
     {
         os.precision(4);
         os<<"Id:"<<s.am<<"\t"<<"Name:"<<s.name<<"\t"<<"Semester:"<<s.semester<<std::endl;
         os<<"******************************************************************"<<std::endl;
         int i=1;
         for(auto &x:s.grades)
         {
             os<<"Lesson "<<i<<":"<<x<<std::endl;
             i++;
         }
         os<<"************************* Average:"<<s.find_average()<<"-Pass:"<<s.pass<<" *******************"<<std::endl;
         os<<std::endl;
         return os;
     }
};

void printstudents(std::vector <student> &stds)
{
    for(auto itr=stds.begin();itr!=stds.end();itr++)
    {
        std::cout<<*itr<<std::endl;
    }
}

int main()
{
   std::mt19937 mt(seed());
   std::uniform_int_distribution <int> ids(1000,9999);
   std::uniform_int_distribution <int> nms(0,26);
   std::uniform_int_distribution <int> pss(7,40);
   std::uniform_int_distribution <int> sem(1,16);
   std::vector <student> students;
   std::string id;
   std::string name;
   int semester;
   int pass;
   for(int i=0;i<SIZE;i++)
   {
      name="";
      int tempid=ids(mt);
      id=std::to_string(tempid);
      semester=sem(mt);
      pass=pss(mt);
      for(int i=0;i<7;i++)
      {
          name+='A'+nms(mt);
      }
      student s(id,name,semester,pass);
      students.push_back(s);
      std::this_thread::sleep_for(std::chrono::seconds(3));
      std::cout<<"student inserted"<<std::endl;
   }
   printstudents(students);
}