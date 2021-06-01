#include "Surfer.hpp"

Surfer::Surfer(int pages) : matrix(pages, pages) {}

Surfer::~Surfer() {}

std::string Surfer::Surfing(int visitors,double DAMPING_FACTOR)
{
    std::string res="";
    this->reset_visits();
    std::mt19937 mt(std::chrono::high_resolution_clock().now().time_since_epoch().count());
    std::uniform_int_distribution<int> go(0, this->rows - 1); //0-4
    std::uniform_real_distribution<double> ran(0.0, 1.0);
    int *startingpoints = new int[visitors];
    for (int i = 0; i < visitors; i++)
    {
        startingpoints[i] = go(mt);
        res+="Visitor "+std::to_string(i+1)+" is placed in Web Page "+std::to_string(startingpoints[i])+"\n";
        this->visits[startingpoints[i]]++;
    }
    res+="\n";
    std::vector<int> nbs;
    int nextpage;
    while(!this->difference())
    {
        for (int j = 0; j < visitors; j++)
        {
            if (ran(mt) <= DAMPING_FACTOR)
            {
                nbs = this->neiborghs(startingpoints[j]);
                if (nbs.empty())
                {
                    res+="DeadEnd!!-- ";
                    nextpage = go(mt);
                    while (nextpage == startingpoints[j])
                    {
                        nextpage = go(mt);
                    }
                }
                else
                    nextpage = nbs[go(mt) % nbs.size()];
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
            res+="Visitor"+std::to_string(j+1)+ " goes from Web Page "+std::to_string(startingpoints[j])+" to Web Page "+std::to_string(nextpage)+"\n";
            startingpoints[j] = nextpage;
        }
        res+="\n";
    }
    return res;
}

double Surfer::getTop()const{
    return this->rank.at(0).grade;
}