/*
Γράψτε ένα πρόγραμμα που να υλοποιεί την κλάση μιγαδικός αριθμός (Complex) και να παρέχει την ακόλουθη λειτουργικότητα.

* Επιστροφή συζυγούς (conjugate) μιγαδικού (συνάρτηση μέλος conj)
* Επιστροφή του μέτρου (magnitude) μιγαδικού (συνάρτηση μέλος abs)
* Yπερφόρτωση του τελεστή +-
* Υπερφόρτωση του τελεστή -
* Υπερφόρτωση του τελεστή *
* Υπερφόρτωση του τελεστή /
* Υπερφόρτωση του τελεστή ==-
* Υπερφόρτωση του τελεστή !=-
* Υπερφόρτωση του τελεστή <<
* Ύψωση μιγαδικού σε ακέραια δύναμη-
* Κατασκευαστής αντιγραφής-

Πληροφορίες για τους μιγαδικούς και τις πράξεις με αυτούς μπορείτε να βρείτε στο διαδίκτυο.
*/
#include <iostream>
#include <utility>
#include <cmath>

using namespace std;
using namespace std::rel_ops;

class Complex
{
   private:
     double real,imaginary;
   public:
     Complex(double r=0.0,double im=0.0):real(r),imaginary(im) {}
     Complex(const Complex &c):real(c.real),imaginary(c.imaginary) {}
     //* Υπερφόρτωση του τελεστή ==
     bool operator==(const Complex &c)const{
         return this->real==c.real && this->imaginary==c.imaginary;
     }
    /* * Υπερφόρτωση του τελεστή !=
    bool operator!=(const Complex &c)const{
         return this->real!=c.real && this->imaginary!=c.imaginary;
     }*/
     //Yπερφόρτωση του τελεστή +
     Complex operator+(const Complex &c)const{
       Complex newcomplex;
       newcomplex.real=this->real+c.real;
       newcomplex.imaginary=this->imaginary+c.imaginary;
       return newcomplex;
     }
     //Ύψωση μιγαδικού σε ακέραια δύναμη
     void Pow(int pr)
     {
       //-->4+3i->48+27i
       double tempreal=this->real;//4
       double tempimaginary=this->imaginary;//3
       for(int i=0;i<pr;i++)//3
       {
          this->real*=tempreal;//4*4=16*4--->this->real=this->real*tempreal-->48
          this->imaginary*=tempimaginary;//27
       }
       //real=48  imaginary=27

       //Εναλλακτικός τρόπος
       //this->real=pow(this->real,pr);
       //this->imaginary=pow(this->imaginary,pr);
     }
};

int main()
{
    Complex c(8.9,9.8);
    Complex c1;
    Complex c2(c1);
    c2.Pow(3);
}