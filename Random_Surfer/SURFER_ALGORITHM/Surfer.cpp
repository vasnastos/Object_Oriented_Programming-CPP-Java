#include "Surfer.hpp"
#include <fstream>
#define DAMPING_FACTOR 0.85 //Παράγοντας που θα καθορίζει το πως θα επιλέγεται η επόμενη σελίδα

std::mt19937 eng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
std::uniform_real_distribution<double> ran(0, 1);

Surfer::Surfer(int a) : matrix(a) {}

Surfer::~Surfer() {}

void Surfer::Random_Surfing(int visitors, int iters)
{
    srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> go(0, this->rows - 1);
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
        //Θα εκτελεστούν επαναλήψης με βάση το όρισμα iters που θα δεχθεί η συνάρτηση.
        for (int j = 0; j < visitors; j++)
        {
            std::vector<int> n = this->getNeibourghs(startingpoints[j]);
            if (ran(eng) <= 1 - DAMPING_FACTOR)
            {
                //Εαν η τυχαία δεκαδική τιμή στο διάστημα 0.0-1.0
                //είναι μικρότερη του 1-0.85 τότε ο επισκέπτης πηγαίνει σε μία τυχαία
                //σελίδα.
                nextpage = go(eng);
                while (nextpage == startingpoints[j])
                {
                    nextpage = go(eng);
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
            std::cout << "Visitor " << j + 1 << " goes from Web Page " << startingpoints[j] << " to Web Page " << nextpage << std::endl;
            startingpoints[j] = nextpage;
        }
        std::cout << std::endl;
    }
    delete[] startingpoints;
}
