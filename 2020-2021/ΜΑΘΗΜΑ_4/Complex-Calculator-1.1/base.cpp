#include "base.h"
#define Button_Clicked 40//define a flag

std::string operatorsfunctionability[4]={"+","-","*","/"};

enum class OPERATION
{
   ADD,
   SUB,
   MUL,
   DIV
};

OPERATION get_choice(int choice)
{
    switch(choice)
    {
        case 0:
         return OPERATION::ADD;
        case 1:
        return OPERATION::SUB;
        case 2:
         return OPERATION::MUL;
        case 3:
         return OPERATION::DIV;
    }
}

std::complex <double> calculate_result(std::string op,std::complex <double> &c1,std::complex <double> &c2)
{
   int choice=-1;
   for(int i=0;i<sizeof(operatorsfunctionability)/sizeof(std::string);i++)
   {
       if(operatorsfunctionability[i]==op)
       {
           choice=i;
           break;
       }
   }
   double real=0.0,imaginary=0.0;
   OPERATION an_operand=get_choice(choice);
   switch(an_operand)
   {
      case OPERATION::ADD:
        real=c1.real()+c2.real();
        imaginary=c1.imag()+c2.imag();
         break;
      case OPERATION::SUB:
         real=c1.real()-c2.real();
         imaginary=c1.imag()-c2.imag();
         break;
      case OPERATION::MUL:
          real=c1.real()*c2.real();
          imaginary=c1.imag()*c2.imag();
         break;
      case OPERATION::DIV:
         if(c2.real()==0 || c2.imag()==0)
         {
           real=imaginary=0;
           break;
          }
         real=c1.real()/c2.real();
         imaginary=c1.imag()/c2.imag();
         break; 
   }
   return std::complex<double>(real,imaginary);
}

Frame::Frame():wxFrame(NULL,wxID_ANY,"")
{
    this->SetSize(600,300);
    this->SetTitle("Complex Calculator");
    this->mainsizer=new wxGridSizer(0,1,5,10);
    wxStaticText *stat=new wxStaticText(this,wxID_ANY,"COMPLEX CALCULATOR--Version 1.1");
    const int width=0.98*this->GetMaxWidth();
    const int height=0.26*this->GetMaxHeight();
    wxColor xc("#6e0d24");
    stat->SetForegroundColour(xc);
    stat->SetSize(wxSize(width,height));
    stat->Wrap(5);
    //this->mainsizer->AddSpacer(10);
    this->mainsizer->Add(stat,0,wxALIGN_CENTER_HORIZONTAL);
    this->panel1();
    this->panel2();
    this->panel3();
    this->SetSizer(this->mainsizer);
}

void Frame::panel1()
{
    std::cout<<"Panel 1 created and attached to mainsizer"<<std::endl;
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    wxGridSizer *sizer=new wxGridSizer(0,3,3,3);
    wxStaticText *st=new wxStaticText(panel,wxTEXT_ALIGNMENT_CENTER,"1ST COMPLEX NUMBER INSERTION",wxDefaultPosition, wxSize(200,20));
    this->input1=new wxTextCtrl(panel,wxID_ANY,"Insert 1st real",wxDefaultPosition, wxSize(100,20));
    this->input2=new wxTextCtrl(panel,wxID_ANY,"Insert 1st imaginary",wxDefaultPosition, wxSize(100,20)); 
    sizer->Add(st);
    sizer->Add(input1);
    sizer->Add(input2);
    panel->SetSizer(sizer);
    this->mainsizer->Add(panel);
}

void Frame::panel2()
{
    std::cout<<"Panel 2 created and attached to mainsizer"<<std::endl;
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    wxGridSizer *sizer=new wxGridSizer(0,3,3,3);
    wxStaticText *st=new wxStaticText(panel,wxID_ANY,"2ND COMPLEX NUMBER INSERTION",wxDefaultPosition,wxSize(200,20));
    this->input3=new wxTextCtrl(panel,wxID_ANY,"Insert 2nd real",wxDefaultPosition,wxSize(100,20));
    this->input4=new wxTextCtrl(panel,wxID_ANY,"Insert 2nd imaginary",wxDefaultPosition,wxSize(100,20));
    sizer->Add(st);
    sizer->Add(this->input3);
    sizer->Add(this->input4);
    panel->SetSizer(sizer);
    this->mainsizer->Add(panel);
}

void Frame::panel3()
{
    std::cout<<"Panel 3 created and attached to mainsizer"<<std::endl;
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    wxGridSizer *sizer=new wxGridSizer(0,4,3,3);
    wxStaticText *st=new wxStaticText(panel,wxID_ANY,"CALCULATION FIELD",wxDefaultPosition,wxSize(150,20));
    this->operations=new wxComboBox(panel,wxID_ANY);
    this->operations->SetSize(wxSize(50,20));
    std::vector <wxString> ops={"+","-","*","/"};
    this->operations->Insert(ops,0);
    this->cal=new wxButton(panel,Button_Clicked,"CALCULATE",wxDefaultPosition,wxSize(80,20));
    this->result=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition, wxSize(80,20));
    this->result->SetEditable(false);
    this->cal->Bind(wxEVT_BUTTON,&Frame::calculate,this);
    //Εναλλακτικός τρόπος σύνδεσης ενός γεγονότος με ένα οπτικό συστατικό
    //Connect(Button_Clicked,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(Frame::calculate))
    sizer->Add(st);
    sizer->Add(this->operations);
    sizer->Add(this->cal);
    sizer->Add(result);
    panel->SetSizer(sizer);
    this->mainsizer->Add(panel);
}

void Frame::calculate(wxCommandEvent &WXUNUSED(ev))
{
    std::cout<<"Button Event Detected:"<<Button_Clicked<<"--Event handler Calculate initiate"<<std::endl;
    std::string real1=std::string(this->input1->GetLineText(0));
    std::string real2=std::string(this->input3->GetLineText(0));
    std::string imaginary1=std::string(this->input2->GetLineText(0));
    std::string imaginary2=std::string(this->input4->GetLineText(0));
    if(real1.length()==0 || real2.length()==0 || imaginary1.length()==0 || imaginary2.length()==0)
    {
        wxMessageBox("Fill all the blanks");
        std::cout<<"FailSafe Empty fields detected.There a/some Empty fields!!"<<std::endl;
        return;
    }
    std::complex <double> c1(std::stod(real1),std::stod(imaginary1));
    std::complex <double> c2(std::stod(real2),std::stod(imaginary2));
    std::string _operator=std::string(this->operations->GetStringSelection());
    if(_operator.length()==0)
    {
        wxMessageBox("No operator choosed!!!");
        std::cout<<"Failsafe operator enabled.No operator is inserted"<<std::endl;
        return;
    }
    std::complex <double> resultcomplex=calculate_result(_operator,c1,c2);
    std::string res="";
    if(resultcomplex.imag()<0)
    {
        res=std::to_string(resultcomplex.real())+std::to_string(resultcomplex.imag())+"i";
    }
    else
    {
        res=std::to_string(resultcomplex.real())+"+"+std::to_string(resultcomplex.imag())+"i";
    }
    //Εμφάνιση στην γραμμή εντολών
    std::cout<<"Calculation made:"<<res<<std::endl;
    /*
       Εμφάνιση και σε παράθρο διαλόγου
       wxMessageBox("Result:"+res);
    */
    this->result->SetValue(res);   
}