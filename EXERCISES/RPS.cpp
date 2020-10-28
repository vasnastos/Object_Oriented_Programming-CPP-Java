#include <iostream>
#include <ctime>
#include <random>

enum class choice
{
    ROCK,
    PAPER,
    SCISSORS
};

std::string choices[]={"ROCK","SCISSORS","PAPER"};

class game
{
  private:
    choice playerschoice;
    int computerschoice;
    int countrounds;
    int countplayers,countcomputer;
    int playerinput()
    {
        int c;
        std::cout<<"         Move Selection"<<std::endl;
        std::cout<<"0-ROCK"<<std::endl;
        std::cout<<"1-SCISSORS"<<std::endl;
        std::cout<<"2-PAPER"<<std::endl;
        std::cout<<"Select move:";
        std::cin>>c;
        std::cout<<std::endl;
        return c;
    }
    void computerinput()
    {
        computerschoice=rand()%3;
    }
    void checkedMove()
    {
      int input=playerinput();
      switch(input)
      {
          case 0:
            playerschoice=choice::ROCK;
            break;
          case 1:
            playerschoice=choice::PAPER;
            break;
          case 2:
            playerschoice=choice::SCISSORS;
          default:
            checkedMove();   
       }
    }
    void show_results()
    {
        std::cout<<"***************************"<<std::endl;
        std::cout<<"  Player:"<<countplayers<<std::endl;
        std::cout<<"  Computer:"<<countcomputer<<std::endl;
        std::cout<<"***************************"<<std::endl<<std::endl;
    }
    bool stopgame(int rnds)
    {
        return (rnds-this->countrounds<this->countplayers-this->countcomputer) || (rnds-this->countrounds<this->countcomputer-this->countplayers);
    }
    void showstats()
    {
        if(this->countplayers>this->countcomputer)
        {
            std::cout<<"***************************"<<std::endl;
        std::cout<<"  Player:"<<countplayers<<std::endl;
        std::cout<<"  Computer:"<<countcomputer<<std::endl;
        std::cout<<"Outcome:Player Wins"<<std::endl;
        std::cout<<"***************************"<<std::endl<<std::endl;
        }
        else if(this->countplayers<this->countcomputer)
        {
            std::cout<<"***************************"<<std::endl;
        std::cout<<"  Player:"<<countplayers<<std::endl;
        std::cout<<"  Computer:"<<countcomputer<<std::endl;
        std::cout<<"Outcome:Computer Wins"<<std::endl;
        std::cout<<"***************************"<<std::endl<<std::endl;
        }
        else
        {
            std::cout<<"***************************"<<std::endl;
        std::cout<<"  Player:"<<countplayers<<std::endl;
        std::cout<<"  Computer:"<<countcomputer<<std::endl;
        std::cout<<"Outcome:Tie Game"<<std::endl;
        std::cout<<"***************************"<<std::endl<<std::endl;
        }
    }
  public:
    game():countplayers(0),countcomputer(0),countrounds(0) {}
    void round()
    {
        this->checkedMove();
        this->computerinput();
      switch(playerschoice)
      {
          case choice::ROCK:
             if(computerschoice==1)
             {
                 std::cout<<"Computer Wins"<<std::endl;
                 this->countcomputer++;
             }
             else if(computerschoice==2)
             {
                 std::cout<<"User Wins"<<std::endl;
                 this->countplayers++;
             }
             else
             {
                 std::cout<<"Tie Game"<<std::endl;
             }
             break;
          case choice::PAPER:
            if(computerschoice==0)
            {
                std::cout<<"Player Wins"<<std::endl;
                this->countplayers++;
            }
            else if(computerschoice==2)
            {
                std::cout<<"Computer Wins"<<std::endl;
                this->countcomputer++;
            }
            else
            {
               std::cout<<"Tie Game"<<std::endl;
            }
            break;
           case choice::SCISSORS:
             if(computerschoice==0)
             {
                 std::cout<<"Computer Wins"<<std::endl;
                 this->countcomputer++;
             }
             else if(computerschoice==1)
             {
                 std::cout<<"Player Wins"<<std::endl;
                 this->countplayers++;
             }
             else
             {
                 std::cout<<"Tie Game"<<std::endl;
             }
             break;
            default:
              break;             
      }
      this->show_results();
      this->countrounds++;     
    }
    void start(int rounds)
    {
       for(int i=0;i<rounds;i++)
       {
           this->round();
       }
       std::cout<<std::endl<<std::endl;
       std::cout<<"#####################################################"<<std::endl;
       this->showstats();
    }  
};

int main(int argc,char **argv)
{
    game g;
    g.start(7);
    return 0;
}