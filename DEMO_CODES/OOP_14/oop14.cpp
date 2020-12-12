/*
Δημιουργήστε μια κλάση sphere (σφαίρα) που:
A. Να έχει ως ιδιωτικό μέλος το πεδίο radius (ακτίνα σφαίρας).
B. Να έχει έναν constructor που να ορίζει τo radius.
C. Να διαθέτει getters και setters για το πεδίο radius.
D. Να διαθέτει μια συνάρτηση get_volume που να επιστρέφει τον όγκο της σφαίρας με βάση τον τύπο
𝐸 =4/3*𝜋𝑟^3, όπου r η ακτίνα της σφαίρας.
E. Υπερφορτώστε τον τελεστή << έτσι ώστε να επιστρέφει τα στοιχεία της σφαίρας ως εξής «RADIUS=XXX.XX»
F. Στη main, γράψτε κώδικα που επαναληπτικά να δέχεται από το χρήστη τα στοιχεία 10 σφαιρών, να εμφανίζει
κάθε σφαίρα με τον τελεστή << και τερματίζοντας να εμφανίζει το μέσο όρο όγκων από όλες τις σφαίρες.
*/

#include <iostream>
#include <random>
#include <sstream>
#include <fstream>
#define p 3.1415;
#define SIZE 10

double Pow(double x,int s)
{
    double res=1.0;
    for(int i=0;i<s;i++)
    {
      res*=x;
    }
    return res;
}

int seed()
{
    std::string time=__TIME__;
    std::stringstream ss(time);
    std::string word;
    while(std::getline(ss,word,':'));
    return std::stoi(word);
}

class sphere
{
    double radius;
    public:
      sphere(double r):radius(r) {}
      void set_radius(double r) {this->radius=r;}
      double get_radius()const {return this->radius;}
      double get_volume()
      {
          return (4.0/3.0)*3.1415*Pow(this->radius,3);
      }
      friend std::ostream &operator<<(std::ostream &os,sphere &s)
      {
          os<<"RADIUS:"<<s.radius<<":::"<<"VOLUME:"<<s.get_volume();
          return os;
      }
};

int main()
{
   std::mt19937 mt(seed());
   std::uniform_real_distribution <double> rad(0,50);
   std::ofstream out;
   out.open("results.out");
   out.precision(5);
   for(int i=0;i<SIZE;i++)
   {
      sphere s(rad(mt));
      out<<s<<std::endl;
   }  
   out.close();
   return 0;
}