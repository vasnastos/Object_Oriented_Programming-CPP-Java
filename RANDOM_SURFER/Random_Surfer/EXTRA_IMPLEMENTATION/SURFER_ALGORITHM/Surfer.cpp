#include "Surfer.hpp"
#include <string>
#include <fstream>
#define DAMPING_FACTOR 0.85 //Παράγοντας που θα καθορίζει το πως θα επιλέγεται η επόμενη σελίδα

std::mt19937 eng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
std::uniform_real_distribution<double> ran(0, 1);

std::string Surfer::info="";

Surfer::Surfer(int a) : matrix(a) {}

Surfer::~Surfer() {}

//Surfer::info-->Κατασκευή στατικής μεταβλητής για ανάπτυξη στατικού html κώδικα.

void Surfer::Random_Surfing(int visitors, int iters)
{
    Surfer::info="<html><body style=\"background-color:cyan;\"><center><h3>Random Surfing Information</h3><hr><table border=\"3\" style=\"color:#82071b; text-align:center; font-weight:bold; font-family:calibri; background-color:#dbdb7d; font-size:18px; width:60%\">";
    Surfer::info+="<tr style=\"background-color:#70b58b; color:#060529;\"><th>VISTOR</th><th>FROM</th><th>TO</th></tr>";
    srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //Θα υπολογιστούν τα αποτελέσματα του αλγόριθμου random Surfing
    int *startingpoints = new int[visitors]; //ο πίνακας θα έχει όσες θέσεις όσες είναι και οι visitors.
    std::uniform_int_distribution<int> v(0, this->rows - 1);
    for (int i = 0; i < visitors; i++)
    {
        //Θα υπολογιστούν οι αρχικές σελίδες που θα βρίσκονται οι επισκέπτες
        //με τυχαιότητα.
        startingpoints[i] = v(eng);
    }
    int nextpage;
    std::cout << "\t\tRandom Surfing" << std::endl;
    std::cout << "*****************************************************************" << std::endl;
    for (int i = 0; i < iters; i++)
    {
        //Θα εκτελεστούν επαναλήψεις με βάση το όρισμα iters που θα δεχθεί η συνάρτηση.
        for (int j = 0; j < visitors; j++)
        {
            std::vector<int> n = this->getNeibourghs(startingpoints[j]);
            if (ran(eng) <= 1 - DAMPING_FACTOR)
            {
                //Εαν η τυχαία δεκαδική τιμή στο διάστημα 0.0-1.0
                //είναι μικρότερη του 1-0.85 τότε ο επισκέπτης πηγαίνει σε μία τυχαία
                //σελίδα.
                nextpage = v(eng);
                while (nextpage == startingpoints[j])
                {
                    nextpage = v(eng);
                }
            }
            else
            {
                //αλλιώς βρίσκει τους γείτονες της κορυφής
                //και αν η κορυφή(Σελίδα) συνδέεται με άλλες κορυφές(Σελίδες)
                //τότε πηγαίνει σε μία από τις συνδεόμενες σελίδες.
                //Αν δεν έχει γείτονες μία κορυφή(δεν συνδέεται μία σελίδα με άλλες σελίδες)
                //τότε επιλέγεται τυχαία μία από τις διαθέσιμες κορυφές(συνδεδεμένες σελίδες).
                if (n.empty())
                {
                    nextpage= v(eng);
                    while (nextpage == startingpoints[j])
                    {
                        nextpage = v(eng);
                    }
                }
                nextpage=n.at(rand()%n.size());
            }
            //Για κάθε επισκέπτη βρίσκει την επόμενη σελίδα που θα μεταβεί
            //και την θέτει σαν επόμενη αρχική σελίδα για περιηγηθεί ο αλγόριθμος.
            Surfer::info+="<tr><td>Visitor "+std::to_string(j+1)+"</td><td>Web Page "+std::to_string(startingpoints[j])+"</td><td>Web Page "+std::to_string(nextpage)+"</td></tr>";
            std::cout << "Visitor " << j + 1 << " goes from Web Page " << startingpoints[j] << " to Web Page " << nextpage << std::endl;
            startingpoints[j] = nextpage;
        }
        Surfer::info+="<tr style=\"background-color:black;\"><td> </td><td> </td><td> </td></tr>";
        std::cout << std::endl;
    }
    Surfer::info+="</table></center></body></html>";
    delete[] startingpoints;
}

void Surfer::save_to_file()
{
    std::ofstream out;
    out.open("Surfingpage.html");
    out<<Surfer::info;
    out.close();
}