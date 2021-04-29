#include "deterministic.hpp"

enum
{
    csv,
    cls
};

Frame::~Frame()
{
    delete this->s;
    exit(EXIT_SUCCESS);
}

void Frame::make_menu()
{
    wxMenuBar *bar=new wxMenuBar();
    wxMenu *men=new wxMenu();
    men->Append(csv,"ITERATE");
    men->Append(cls,"CLOSE");
    Connect(csv,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::Export));
    Connect(cls,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::Close));
    bar->Append(men,"OPTIONS");
    this->SetMenuBar(bar);
}

Frame::Frame():wxFrame(nullptr,wxID_ANY,"Random Surfer",wxDefaultPosition,wxSize(350,500)),s(nullptr)
{
    this->gs=new wxBoxSizer(wxVERTICAL);
    this->gs->AddSpacer(3);
    std::string desc="Random Surfing Algorithm using Random visits per Page";
    wxStaticText *st=new wxStaticText(this,wxTEXT_ALIGNMENT_CENTER,desc,wxDefaultPosition,wxSize(340,30),wxCENTRE);
    st->SetForegroundColour(wxColor("#360c3d"));
    this->gs->Add(st);
    this->make_menu();
    this->panel1();
    this->panel2();
    this->panel3();
    this->panel4();
    this->results=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(340,270),wxTE_MULTILINE);
    //this->results->SetEditable(false);
    this->gs->Add(this->results);
    this->SetSizer(this->gs);
}

void Frame::panel1()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    panel->SetBackgroundColour(wxColor("#999aa3"));
    wxGridSizer *sizer=new wxGridSizer(0,2,4,4);
    wxStaticText *st=new wxStaticText(panel,wxID_ANY,"PAGES",wxDefaultPosition,wxSize(100,20));
    this->pages=new wxTextCtrl(panel,wxID_ANY,"10",wxDefaultPosition,wxSize(80,20));
    sizer->Add(st);
    sizer->Add(this->pages);
    panel->SetSizer(sizer);
    this->gs->Add(panel);
}

void Frame::panel2()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    panel->SetBackgroundColour(wxColor("#999aa3"));
    wxGridSizer *sizer=new wxGridSizer(0,2,4,4);
    wxStaticText *st=new wxStaticText(panel,wxID_ANY,"DAMPING FACTOR",wxDefaultPosition,wxSize(100,20));
    this->damping_factor=new wxTextCtrl(panel,wxID_ANY,"0.85",wxDefaultPosition,wxSize(80,20));
    sizer->Add(st);
    sizer->Add(this->damping_factor);
    panel->SetSizer(sizer);
    this->gs->Add(panel);
}

void Frame::panel3()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    panel->SetBackgroundColour(wxColor("#999aa3"));
    wxGridSizer *sizer=new wxGridSizer(0,2,4,4);
    wxStaticText *st=new wxStaticText(panel,wxID_ANY,"VISITORS",wxDefaultPosition,wxSize(100,20));
    this->visitors=new wxTextCtrl(panel,wxID_ANY,"3",wxDefaultPosition,wxSize(80,20));
    sizer->Add(st);
    sizer->Add(this->visitors);
    panel->SetSizer(sizer);
    this->gs->Add(panel);
}

void Frame::panel4()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    wxGridSizer *sizer=new wxGridSizer(0,2,4,4);
    panel->SetBackgroundColour(wxColor("#999aa3"));
    wxButton *b1=new wxButton(panel,wxID_ANY,"SURFING",wxDefaultPosition,wxSize(60,20));
    wxButton *b2=new wxButton(panel,wxID_ANY,"RANKING",wxDefaultPosition,wxSize(60,20));
    b1->Bind(wxEVT_BUTTON,&Frame::surfing,this);
    b2->Bind(wxEVT_BUTTON,&Frame::ranking,this);
    sizer->Add(b1);
    sizer->Add(b2);
    panel->SetSizer(sizer);
    this->gs->Add(panel);
}

void Frame::surfing(wxCommandEvent &ev)
{
    std::string number_of_pages=this->pages->GetValue().ToStdString();
    std::string number_of_visitors=this->visitors->GetValue().ToStdString();
    std::string number_of_dmp=this->damping_factor->GetValue().ToStdString();
    if(number_of_pages.empty() || number_of_visitors.empty() || number_of_dmp.empty())
    {
        wxMessageBox("Fill all the blanks");
        return;
    }
    int nop=std::stoi(number_of_pages);
    int nov=std::stoi(number_of_visitors);
    double nod=std::stod(number_of_dmp);
    this->s=new Surfer(nop);
    this->results->SetValue(this->s->Surfing(nov,nod));
}

void Frame::ranking(wxCommandEvent &ev)
{
    if(this->s==nullptr)
    {
        wxMessageBox("No Web Surfing made!!\nPlease make a web Surf");
        return;
    }
    std::string web_ranking=this->s->find_ranking();
    wxMessageBox(web_ranking,"Ranking");
}

void Frame::Export(wxCommandEvent &ev)
{
   wxTextEntryDialog wtex(nullptr,"Give number of visitors");
   if(wtex.ShowModal()==wxID_CANCEL)
   {
       return;
   }
   int N=std::stoi(wtex.GetValue().ToStdString());
   int lpage=10;
   int upage=1000;
   double ldamp=0.5;
   double udamp=0.99;
   wxFileDialog saveDialog(this,"Select Save File","","","Comma seperated Value *csv",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
   if(saveDialog.ShowModal()==wxID_CANCEL)
   {
       return;
   }
   std::string path=saveDialog.GetPath().ToStdString();
   std::ofstream ofs;
   ofs.open(path);
   for(double dp=ldamp;dp<=udamp;dp+=0.01)
   {
     ofs<<";"<<"DMP_"<<dp;
   }
   ofs<<std::endl;
   std::string top_elem;
   for(int i=lpage;i<upage;i+=5)
   {
       ofs<<i;
       for(double dp=ldamp;dp<=udamp;dp+=0.01)
       {
           Surfer srf(i);
           srf.Surfing(N,dp);
           srf.find_ranking();
           top_elem=std::to_string(srf.getTop());
           std::replace_if(top_elem.begin(),top_elem.end(),[](char &a) {return a=='.';},',');
           ofs<<";"<<top_elem;
       }
       ofs<<std::endl;
   }
   ofs.close();
}

void Frame::Close(wxCommandEvent &ev)
{
    exit(EXIT_SUCCESS);
}
