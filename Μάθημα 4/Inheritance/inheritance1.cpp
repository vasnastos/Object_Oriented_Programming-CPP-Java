#include <iostream>

class frame
{
    private:
      std::string text;
    public:
      frame(std::string title):text(title) {}
      void setText(std::string t) {this->text=t;}
      std::string getText()const {return this->text;}
};

class designf:public frame
{
    public:
      designf(std::string name):frame(name) {}
      void show()
      {
          std::string out="***********************************";
          std::cout<<out<<std::endl;
          std::cout<<"*      "<<this->getText();
          const int rest=out.length()-(this->getText().length()+7);
          for(int i=0;i<rest-1;i++)
          {
              std::cout<<" ";
          }
          std::cout<<"*"<<std::endl;
          std::cout<<out<<std::endl;
      }
};

int main()
{
    std::string s;
    std::cout<<"Display Label demo"<<std::endl;
    std::cout<<"Give Display Text:";
    std::cin>>s;
    std::cout<<std::endl<<std::endl;
    designf *d=new designf(s);
    d->show();
    delete d;
    return 0;
}