#include "Surfer.hpp"
#include <string>
#include <fstream>
#define DAMPING_FACTOR 0.85 //Παράγοντας που θα καθορίζει το πως θα επιλέγεται η επόμενη σελίδα
#define TERMINATE 0.15


bool Surfer::difference()
{
    if (this->rank.empty())
    {
        return false;
    }
    std::vector<pagerank> it;
    while (!this->rank.empty())
    {
        it.push_back(this->rank.top());
        this->rank.pop();
    }
    for (auto &x : it)
    {
        this->rank.push(x);
    }
    double lval=it.at(0).rank - it.at(it.size() - 1).rank;
    std::cout<<lval<<std::endl;
    return lval <= TERMINATE /*&& this->all_visited()*/;
}

Surfer::Surfer(int a) : matrix(a) {}

Surfer::~Surfer() {}

std::string Surfer::Random_Surfing(int visitors)
{
    std::string result="";
    std::mt19937 eng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> ran(0, 1);
    //Θα υπολογιστούν τα αποτελέσματα του αλγόριθμου random Surfing
    int *startingpoints = new int[visitors]; //ο πίνακας θα έχει όσες θέσεις όσες είναι και οι visitors.
    std::uniform_int_distribution<int> v(0, this->rows - 1);
    for (int i = 0; i < visitors; i++)
    {
        //Θα υπολογιστούν οι αρχικές σελίδες που θα βρίσκονται οι επισκέπτες
        //με τυχαιότητα.
        int page = v(eng);
        startingpoints[i] = page;
        //Σε αυτές της σελίδες εκκίνησης προσθέτω και μία επίσκεψη.
        this->add_visits(page);
    }
    int nextpage;
    std::cout << "\t\tRandom Surfing" << std::endl;
    std::cout << "*****************************************************************" << std::endl;
    int countreplays = 0;
    while (!this->difference())
    {
        countreplays++;
        //Θα εκτελεστούν επαναλήψης με βάση το όρισμα iters που θα δεχθεί η συνάρτηση.
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
                    nextpage = v(eng);
                    while (nextpage == startingpoints[j])
                    {
                        nextpage = v(eng);
                    }
                }
                nextpage = n.at(v(eng) % n.size());
            }
            this->add_visits(nextpage);
            //Για κάθε επισκέπτη βρίσκει την επόμενη σελίδα που θα μεταβεί
            //και την θέτει σαν επόμενη αρχική σελίδα για περιηγηθεί ο αλγόριθμος.
            std::cout << "Visitor " << j + 1 << " goes from Web Page " << startingpoints[j] << " to Web Page " << nextpage << std::endl;
            result+="Visitor "+std::to_string(j+1)+" goes from Web Page "+std::to_string(startingpoints[j])+" to Web Page "+std::to_string(nextpage)+"\n"; 
            startingpoints[j] = nextpage;
        }
        this->find_rank();
        std::cout << std::endl;
        result+="\n";
    }
    delete[] startingpoints;
    std::cout<<std::endl<<"\t\tPAGE RANKING"<<std::endl;
    this->print_ranking();
    return result;
}
