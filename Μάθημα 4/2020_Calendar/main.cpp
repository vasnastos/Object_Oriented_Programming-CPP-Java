#include "gui.cpp"

void App::Print()
{
    date d(4,5);
    date d1(21,11);
    date d2(8,9);
    date d3(7,10);

    std::cout<<"\t\tDefault Prices Tester"<<std::endl;
    std::string message="-->"+std::string(d)+"\n"
    +"-->"+std::string(d1)+"\n"
    +"-->"+std::string(d2)+"\n"
    +"-->"+std::string(d3)+"\n";
    wxMessageBox(message);
}

void App::CommandTester()
{
    int number;
    std::cout<<"**** Command Input Prices Tester *****"<<std::endl;
    std::cout<<"Give a number in order to search a date:";
    std::cin>>number;
    date d(number);
    wxMessageBox(std::string(d));
}

void App::Day_Month_Tester()
{
    int day,month;
    std::cout<<"**** Month and day Input Testers ****"<<std::endl<<std::endl;
    std::cout<<"Give day:";
    std::cin>>day;
    std::cout<<"Give month:";
    std::cin>>month;
    date d(day,month);
    wxMessageBox(std::string(d));
}

void App::Chooser()
{
    std::cout<<std::endl<<"Welcome to program tester"<<std::endl;\
    std::cout<<"\t#Available choices"<<std::endl;
    int choice;
    while(true)
    { 
      std::cout<<"1-Test the date Using Command Line"<<std::endl;
      std::cout<<"2-Test the date App by default Date"<<std::endl;
      std::cout<<"3-Test Input by give a month and a date"<<std::endl;
      std::cout<<"4-Initiate Gui"<<std::endl;
      std::cout<<"4-Exit"<<std::endl;
      std::cout<<"Select your choice:";
      std::cin>>choice;
      bool exit=false;
      Frame *f=nullptr;
      switch(choice)
      {
          case 1:
            this->CommandTester();
            break;
          case 2:
            this->Print();
            break;
          case 3:
            this->Day_Month_Tester();
            break;
          case 4:
            exit=true;
            break;
          default:
            std::cerr<<"Invallid choice try again!!!"<<std::endl;
            break;
      }
       if(exit)
       {
          return;
       }
    }
}

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    std::cout<<"\t\tDate App--Version 1.1 Initiated"<<std::endl;
    std::cout<<"##############################################"<<std::endl;
    int choice;
    while(1)
    {  
       std::cout<<std::endl<<"1-Tests"<<std::endl;
       std::cout<<"2-Proceed to App"<<std::endl;
       std::cout<<"3-Exit Program"<<std::endl;
       std::cout<<"Select a choice"<<std::endl;
       std::cin>>choice;
      if(choice==1)
         this->Chooser();
      else if(choice==2)
      {
        break;
      }
      else if(choice==3)
      {
        return true;
      }
      else 
      {
        std::cerr<<"Invallid choice please try again!!!"<<std::endl;
      }
    }
    Frame *f=new Frame("2020_CALENDAR");
    f->Show();
    return true;
}

/*int main()
{
  App myapp;
  myapp.OnInit();
  return 0;
}*/