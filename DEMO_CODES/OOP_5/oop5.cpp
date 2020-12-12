/*
  Δημιουργήστε δύο κλάσεις οrder (παραγγελία) και line_item (αντικείμενο παραγγελίας).
  Η κλάση order να έχει ως πεδία μέλη: number (αριθμό παραγγελίας), ordered (ημερομηνία παραγγελίας), shipped (ημερομηνία παράδοσης)
  και ship_to (τοποθεσία παράδοσης).
  Η κλάση line_item να έχει ως πεδία μέλη: product (ονομασία προϊόντος), quantity (ποσότητα) και price (τιμή).
  Η κλάση order να διατηρεί ένα std::vector με τα line_items που αντιστοιχούν σε κάθε παραγγελία.
  Υπερφορτώστε τον operator<< τόσο για τα αντικείμενα order όσο και για τα αντικείμενα line_item.
  Γράψτε πρόγραμμα οδηγό (main1.cpp) που να δημιουργεί μια παραγγελία με 3 συσχετιζόμενα αντικείμενα παραγγελίας και 
  μια ακόμη παραγγελία με 1 συσχετιζόμενο αντικείμενο παραγγελίας. Προσθέστε τις παραγγελίες σε ένα std::vector.
  Διανύστε το vector και εμφανίστε τα αποτελέσματα στην οθόνη.
  Γράψτε νέο πρόγραμμα οδηγό (main2.cpp) που να δημιουργεί μια Βάση Δεδομένων στην SQLite3
  η οποία να μπορεί να δεχθεί δεδομένα αντικειμένων των παραπάνω κλάσεων.
  Για το σκοπό αυτό δημιουργήστε τους πίνακες ORDERS και LINE_ITEMS.
  Εισάγετε δεδομένα στους πίνακες έτσι ώστε να υπάρχουν 3 παραγγελίες με κάποια αντικείμενα παραγγελίας για κάθε παραγγελία.
  Συμπληρώστε κώδικα στο πρόγραμμα οδηγό έτσι ώστε να ανακαλεί τα δεδομένα από τη Βάση Δεδομένων,
  να τα εισάγει σε αντικείμενα και να τα εμφανίζει.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

class line_item
{
    private:
      std::string product;
      int quantity;
      double price;
   public:
      line_item(std::string pr,int q,double p):product(pr),quantity(q),price(p) {}
      std::string getproduct() {return this->product;}
      int getquantity() {return this->quantity;}
      double getprice() {return this->price;}
      friend std::ostream &operator<<(std::ostream &os,line_item &it)
      {
          os<<it.product<<"--"<<it.quantity<<"--"<<it.price;
          return os;
      }
};

class order
{
    private:
      std::string number;
      std::string ordered;
      std::string shipped;
      std::string ship_to;
     std::vector <line_item> items;
    public:
      order(std::string n,std::string ord,std::string sh,std::string sht):number(n),ordered(ord),shipped(sh),ship_to(sht) {}
      void add_item(line_item aitem) {items.push_back(aitem);}
      friend std::ostream &operator<<(std::ostream &os,order &ord)
      {
          os<<ord.number<<"--"<<ord.ordered<<"--"<<ord.ship_to<<"--"<<ord.shipped<<std::endl;
          for(line_item &x:ord.items)
          {
              os<<x<<std::endl;
          }
          return os;
      }
};

int main()
{
    order o1("0001","2020-01-05 10:07:07","2020-01-07 12:01:01","Athens");
    line_item it1("TV",1,550.0);
    line_item it2("A4 PAPER",5,10.5);
    o1.add_item(it1);
    o1.add_item(it2);
    line_item it3("Microphone",2,50.5);
    o1.add_item(it3);
    order o2("0002","2020-02-07 12:20:01","2020-02-17 19:30:20","Ioannina");
    line_item it4("CAMERA",1,230.0);
    line_item it5("WIFI",1,55.9);
    line_item it6("SSD",1,90.5);
    o2.add_item(it4);
    o2.add_item(it5);
    order o3("0003","2020-02-08 10:20:11","2020-02-15 12:35:22","Arta");
    o3.add_item(it6);
    std::vector <order> orders;
    orders.push_back(o1);
    orders.push_back(o2);
    orders.push_back(o3);
    std::cout<<"############## Products List ######################"<<std::endl;
    for(auto &x:orders)
    {
        std::cout<<x<<std::endl;
    }
    std::cout<<"####################################################"<<std::endl;
}