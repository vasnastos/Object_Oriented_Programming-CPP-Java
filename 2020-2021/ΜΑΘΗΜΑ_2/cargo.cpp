/*
Κατασκευάστε μια κλάση με όνομα cargo (φορτίο) με μέλη δεδομένων τα ακόλουθα:
id (αναγνωριστικός αριθμός φορτίου) τύπου int.
destination (προορισμός) τύπου string.
weight (βάρος) τύπου double.
fragile (εύθραυστο) τύπου bool.
Δημιουργήστε προκαθορισμένο κατασκευαστή που να δίνει τις εξής τιμές: 0, “Undefined”, 0, false.
Δημιουργήστε έναν κατασκευαστή που να θέτει όλα τα μέλη δεδομένων εκτος του id(autoincrement) σε τιμές που θα δέχεται ως παραμέτρους.
Υπερφορτώστε τον τελεστή + ώστε να προσθέτει μαζί 2 προιόντα,αν έχουν τον ίδιο προορισμό.
Δημιουργήστε getters και setters μόνο το πεδίο weight.
Δημιουργήστε μια συνάρτηση show() που να εμφανίζει τις τιμές όλων των πεδίων του αντικειμένου.
Δημιουργήστε μια συνάρτηση μέλος make_safe() που εφόσον ένα φορτίο δεν είναι fragile να το κάνει και να αυξάνει το βάρος του κατά 5 κιλά (για υλικά συσκευασίας).
Στη main:
Εισάγετε σε έναν πίνακα 5 θέσεων αντικείμενα cargo ως εξής:
1, Patras, 1000, false
2, Athens, 200, true
3, Kalamata, 2000, false
4, Patras, 1500, true
5, Athens, 1100, false
Με μια επανάληψη πραγματοποιήστε κλήση της make_safe για όλα τα αντικείμενα.
Εμφανίστε όλα τα αντικείμενα.
*/

#include <iostream>
#include <sstream>
#include <random>

int seed()
{
  std::string time=__TIME__;
  std::string word;
  std::stringstream ss(time);
  std::vector <std::string> data;
  while(std::getline(ss,word,':')) {data.push_back(word);}
  return 3600*std::stoi(data[0])+60*std::stoi(data[1])+std::stoi(data[2]);
}

class cargo
{
    std::string id;
    std::string destination;
    double weight;
    bool fragile;
    public:
    static int counter;
    cargo():id("0"),destination("undefinied"),weight(0.0),fragile(false) {counter++;}
     cargo(std::string d,double p,bool f):id(std::to_string(counter)),destination(d),weight(p),fragile(f)
     {
        counter++;
     }
     ~cargo() {}
    cargo operator+(cargo &p)
    {
        this->id+="-"+p.id;
        this->weight+=p.weight;
        return *this;
    }
    void set_weight(double w)
    {
        this->weight=w;
    }
    double get_weight() {return this->weight;}
    cargo &operator=(const cargo &c)
    {
        this->id=c.id;
        this->destination=c.destination;
        this->weight=c.weight;
        this->fragile=c.fragile;
        return *this;
    }
    void show()
    {
        std::cout<<this->id<<"-"<<this->destination<<"-"<<this->weight<<"-";
        if(this->fragile)
        {
            std::cout<<"Fragile"<<std::endl;
        }
        else
        {
            std::cout<<"Not Fragile"<<std::endl;
        } 
    }
    void make_safe()
    {
        if(!this->fragile)
        {
            this->fragile=true;
            this->weight+=5.0;
        }
    }
};

int cargo::counter=1;

int main()
{
    std::string cities[5]={"Yaounde","Madrid","Rio_de_Janeiro","Athens","Paris"};
    std::mt19937 mt(seed());
    std::uniform_int_distribution <int> cts(0,4);
    std::uniform_real_distribution <double> weight(200,70000);
    std::uniform_int_distribution <int> frag(0,1); 
    cargo *cargos=new cargo[20];
    for(int i=0;i<20;i++)
    {
        bool fr;
        if(frag(mt)==0)
        {
           fr=true;  
        }
        else
        {
            fr=false;
        }
        cargo temp(cities[cts(mt)],weight(mt),fr);
        cargos[i]=temp;
    }
    for(int i=0;i<20;i++)
    {
        cargos[i].show();
    }
    for(int i=0;i<20;i++)
    {
        cargos[i].make_safe();
    }
    std::cout<<std::endl<<std::endl<<"After safe Fuction enable"<<std::endl;
    for(int i=0;i<20;i++)
    {
        cargos[i].show();
    }
    delete[] cargos;
    return 0;
}