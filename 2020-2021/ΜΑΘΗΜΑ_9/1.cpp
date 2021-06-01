#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <random>
#include <ostream>

class document
{
   protected:
      std::string date;
      std::vector <std::string> authors;
   public:
      document(std::string adate):date(adate) {}
      std::vector <std::string> getAuthors()const {return this->authors;}
      std::string getDate()const {return this->date;}
      void addAuthor(std::string name) {this->authors.push_back(name);}
      virtual std::string info()=0;
};

class book:public document{
    private:
       std::string title;
    public:
       book(std::string a_date,std::string a_title):document(a_date),title(a_title)
       {}
       std::string getTitle()const {return this->title;}
       std::string info(){
          std::string msg="\t"+this->title+"--"+this->date+"\n";
          msg+="------------------------------------------------------\n";
          msg+="\t\tAuthors\n";
          for(auto &x:this->authors)
          {
              msg+="\t\t"+x+"\n";
          }
          msg+="\n\n";
          return msg;
       }
};

class email:public document{
    std::string sender;
    std::string subject;
    std::vector <std::string> reciepients;
    public:
      email(std::string a_date,std::string a_sender,std::string a_subject):document(a_date),sender(a_sender),subject(a_subject) {}
      std::string getSubject()const {return this->subject;}
      std::string getSender()const {return this->sender;}
      std::vector <std::string> getRecipients()const {return this->reciepients;}
      void addRecipient(std::string rec)
      {
          this->reciepients.push_back(rec);
      }
      std::string info()
      {
          std::string msg="\t"+this->sender+"--"+this->subject+"--"+this->date+"\n";
          msg+="--------------------------------------------------------\n";
          msg+="\t\tAuthor\n";
          for(auto &x:this->authors)
          msg+="\t\t  "+x+"\n\n";
          msg+="\t\tReripients\n";
          for(auto &y:this->reciepients)
          msg+="\t\t  "+y+"\n";
          msg+="\n\n";
          return msg;
      } 
};

int main()
{
    std::vector <document*> docs;
    std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution <int> dist(1,10);
    std::uniform_int_distribution <int> choice(1,2);
    const std::string d=__DATE__;
    for(int i=1;i<=10;i++)
    {
       int achoice=choice(mt);
       if(achoice==1) 
       {    
            book *b=new book(d,"title"+std::to_string(i));
            const int size=dist(mt);
            for(int j=1;j<=size;j++)
            {
               b->addAuthor("author"+std::to_string(j));
            }
            docs.push_back(b);
       }
        else if(achoice==2)
        {
            email *e=new email(d,"sender"+std::to_string(i),"subject"+std::to_string(i));
            const int size=dist(mt);
            const int res=dist(mt); 
            for(int j=1;j<=size;j++)
            {
                e->addAuthor("author"+std::to_string(j));
            }
            for(int j=1;j<=res;j++)
            {
                e->addRecipient("recipient"+std::to_string(j));
            }
            docs.push_back(e);
        }
    }
    for(auto &x:docs)
    {
        std::cout<<x->info()<<std::endl;
    }
    for(auto &r:docs)
    {
        delete r;
    }
    return 0;
}