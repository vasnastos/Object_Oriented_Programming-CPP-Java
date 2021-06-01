#include "Surfer.hpp"

Surfer::Surfer(int pages) : matrix(pages, pages) {}

Surfer::~Surfer() {}

//     1  2 3 4 5
//   1 0  1 0 0 1

std::string Surfer::Surfing(int visitors,double DAMPING_FACTOR)
{
    std::string res="";
    this->reset_visits();
    //long seed=123456789
    std::mt19937 mt(std::chrono::high_resolution_clock().now().time_since_epoch().count());
    std::uniform_int_distribution<int> go(0, this->rows - 1); //0-4
    std::uniform_real_distribution<double> ran(0.0, 1.0);
    //<=0.15-->Τυχαία ιστοσελίδα.
    //>0.15-->Γειτονική ιστοσελίδα.
    //Damping_Factor--><=0.85-->Γειτονική ιστοσελίδα.
    //Damping_Factor-->>0.85-->Τυχαία ιστοσελίδα.
    int *startingpoints = new int[visitors];
    for (int i = 0; i < visitors; i++)
    {
        startingpoints[i] = go(mt);
        std::cout << "Visitor " << i + 1 << " is placed in Web Page " << startingpoints[i] << std::endl;
        res+="Visitor "+std::to_string(i+1)+" is placed in Web Page "+std::to_string(startingpoints[i])+"\n";
        this->visits[startingpoints[i]]++;
    }
    std::cout << std::endl;
    res+="\n";
    std::vector<int> nbs;
    int nextpage;
    for (int i = 0; i < 10; i++)//-->Εναλλακτική Συνθήκη
    {
        for (int j = 0; j < visitors; j++)
        {
            if (ran(mt) <= DAMPING_FACTOR)
            {
                nbs = this->neiborghs(startingpoints[j]);
                if (nbs.empty())
                {
                    std::cout << "DeadEnd!!-- ";
                    res+="DeadEnd!!-- ";
                    nextpage = go(mt);
                    while (nextpage == startingpoints[j])
                    {
                        nextpage = go(mt);
                    }
                }
                else
                    nextpage = nbs[go(mt) % nbs.size()]; //2%2=0---- 3%2=1  4%2=0
            }
            else
            {
                nextpage = go(mt);
                while (nextpage == startingpoints[j])
                {
                    nextpage = go(mt);
                }
            }
            this->visits[nextpage]++;
            std::cout << "Visitor " << j + 1 << " goes from Web Page " << startingpoints[j] << " to Web Page " << nextpage << std::endl;
            res+="Visitor"+std::to_string(j+1)+ " goes from Web Page "+std::to_string(startingpoints[j])+" to Web Page "+std::to_string(nextpage)+"\n";
            startingpoints[j] = nextpage;
        }
        std::cout << std::endl;
        res+="\n";
    }
    this->find_ranking();
    return res;
}