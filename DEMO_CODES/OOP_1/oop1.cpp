/*
Κατασκευάστε μια κλάση με όνομα cargo (φορτίο) με μέλη δεδομένων τα ακόλουθα:
   •id (αναγνωριστικός αριθμός φορτίου) τύπου int.
   •destination (προορισμός) τύπου string.
   •weight (βάρος) τύπου double.
   •fragile (εύθραυστο) τύπου bool.
•Δημιουργήστε προκαθορισμένο κατασκευαστή που να δίνει τις εξής τιμές: 0, "Undefined", 0, false.
•Δημιουργήστε έναν κατασκευαστή που να θέτει όλα τα μέλη δεδομένων σε τιμές που θα δέχεται ως παραμέτρους.
•Δημιουργήστε getters και setters μόνο το πεδίο weight.
•Δημιουργήστε μια συνάρτηση show() που να εμφανίζει τις τιμές όλων των πεδίων του αντικειμένου.
•Δημιουργήστε μια συνάρτηση μέλος make_safe() που εφόσον ένα φορτίο δεν είναι fragile να το κάνει και να αυξάνει το βάρος του κατά 5 κιλά (για υλικά συσκευασίας).
Στη main:
  •Εισάγετε σε ένα vector τα στοιχεία από το αρχείο cargos.txt
  •Ταξινομίστε τα στοιχεία με βάση την τιμή.
  •Με μια επανάληψη πραγματοποιήστε κλήση της make_safe για όλα τα αντικείμενα.
  •Εμφανίστε όλα τα αντικείμενα.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

class cargo
{
   private:
     int id;
     std::string destination;
     double weight;
     bool fragile;
     double price;
   public:
     cargo(int i=0,std::string dest="Undefiened",double w=0.0,bool f=false,double p=0.0):id(i),destination(dest),weight(w),fragile(f),price(p) {}
     void set_weight(double w) {this->weight=w;}
     double get_weight()const {return this->weight;}
     double get_price() {return this->price;}
     void show()
     {
         std::cout<<this->id<<"--"<<this->destination<<"--"<<this->weight<<"--";
         if(fragile)
         {
             std::cout<<"Fragile";
         }
         else
         {
             std::cout<<"Not Fragile";
         }
         std::cout<<"--"<<this->price<<std::endl;
     }
     void make_safe()
     {
         if(!fragile)
         {
             fragile=true;
             this->weight+=5.0;
         }
     }
};

int main()
{
    std::vector <cargo> cargos;
    std::ifstream fin;
    std::string line,word;
    std::vector <std::string> data;
    fin.open("cargos.txt",std::ios::in);
    while(std::getline(fin,line))
    {
        data.clear();
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
            data.push_back(word);
        }
        bool res;
        if(data[3]=="true")
        {
            res=true;
        }
        else
        {
            res=false;
        }
        
        cargo c(std::stoi(data[0]),data[1],std::stod(data[2]),res,std::stod(data[4]));
        cargos.push_back(c);
    }
    fin.close();
    for(auto &k:cargos)
    {
        k.show();
    }
    std::cout<<std::endl;
    for(auto &y:cargos)
    {
        y.make_safe();
        y.show();
    }
    std::cout<<std::endl;
    sort(cargos.begin(),cargos.end(),[](cargo &c1,cargo &c2) {return c1.get_price()<c2.get_price();});
    for(auto &x:cargos)
    {
        x.show();
    }
}