#include "wx/wx.h"
#include <wx/listctrl.h>
#include "surf.hpp"
#include <string>

class Frame : public wxFrame
{
private:
    wxTextCtrl *visitors, *pages, *iterations;
    wxBoxSizer *bx = nullptr;
    wxListCtrl *ranks = nullptr;
    void ClearList()
    {
        this->ranks->ClearAll();
        wxListItem column1, column2;
        column1.SetId(0);
        column1.SetWidth(150);
        column1.SetText(_("PAGE"));
        column2.SetId(1);
        column2.SetWidth(50);
        column2.SetText(_("RANK"));
        this->ranks->InsertColumn(0, column1);
        this->ranks->InsertColumn(1, column2);
    }
    void panel1()
    {
        wxPanel *panel = new wxPanel(this, wxID_ANY);
        wxGridSizer *sizer = new wxGridSizer(0, 2, 5, 6);
        wxStaticText *st = new wxStaticText(panel, wxTEXT_ALIGNMENT_CENTER, "VISITORS", wxDefaultPosition, wxSize(100, 20));
        st->SetForegroundColour(wxColor("#061226"));
        this->visitors = new wxTextCtrl(panel, wxTEXT_ALIGNMENT_CENTER, "", wxDefaultPosition, wxSize(100, 20));
        sizer->Add(st);
        sizer->Add(this->visitors);
        panel->SetSizer(sizer);
        this->bx->Add(panel);
    }
    void panel2()
    {
        wxPanel *panel = new wxPanel(this, wxID_ANY);
        wxGridSizer *sizer = new wxGridSizer(0, 2, 3, 5);
        wxStaticText *st = new wxStaticText(panel, wxTEXT_ALIGNMENT_CENTER, "ITERATIONS", wxDefaultPosition, wxSize(100, 20));
        st->SetForegroundColour(wxColor("#061226"));
        this->iterations = new wxTextCtrl(panel, wxTEXT_ALIGNMENT_CENTER, "", wxDefaultPosition, wxSize(100, 20));
        sizer->Add(st);
        sizer->Add(this->iterations);
        panel->SetSizer(sizer);
        this->bx->Add(panel);
    }
    void panel3()
    {
        wxPanel *panel = new wxPanel(this, wxID_ANY);
        wxGridSizer *sizer = new wxGridSizer(0, 2, 3, 5);
        wxStaticText *st = new wxStaticText(panel, wxTEXT_ALIGNMENT_CENTER, "PAGES", wxDefaultPosition, wxSize(100, 20));
        st - SetForegroundColour(wxColor("#061226"));
        this->pages = new wxTextCtrl(panel, wxTEXT_ALIGNMENT_CENTER, "", wxDefaultPosition, wxSize(100, 20));
        sizer->Add(st);
        sizer->Add(this->pages);
        panel->SetSizer(sizer);
        this->bx->Add(panel);
    }
    void panel4()
    {
        wxGridSizer *sizer = new wxGridSizer(0, 3, 3, 5);
        wxPanel *panel = new wxPanel(this, wxID_ANY);
        wxButton *b1 = new wxButton(panel, wxID_ANY, "SURF");
        wxButton *b2 = new wxButton(panel, wxID_ANY, "RANK");
        wxButton *b3 = new wxButton(panel, wxID_ANY, "CLEAR");
        b1->Bind(wxEVT_BUTTON, &Frame::surfer, this);
        b2->Bind(wxEVT_BUTTON, &Frame::rank, this);
        b3->Bind(wxEVT_BUTTON, &Frame::clear, this);
        sizer->Add(b1);
        sizer->Add(b2);
        sizer->Add(b3);
        panel->SetSizer(sizer);
        this->bx->Add(panel);
    }
    void ListPanel()
    {
        wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
        wxPanel *panel = new wxPanel(this, wxID_ANY);
        this->ranks = new wxListCtrl(panel, wxID_ANY, wxDefaultPosition, wxSize(300, 320), wxLC_REPORT);
        wxListItem column1, column2;
        column1.SetId(0);
        column1.SetWidth(150);
        column1.SetText(_("PAGE"));
        column2.SetId(1);
        column2.SetWidth(150);
        column2.SetText(_("RANK"));
        this->ranks->InsertColumn(0, column1);
        this->ranks->InsertColumn(1, column2);
        sizer->Add(this->ranks);
        panel->SetSizer(sizer);
        this->bx->Add(panel);
    }

public:
    Frame() : wxFrame(nullptr, wxID_ANY, "PAGE RANKS")
    {
        this->SetSize(500,500);
        this->bx = new wxBoxSizer(wxVERTICAL);
        this->bx->AddSpacer(10);
        wxStaticText *stat = new wxStaticText(this, wxTEXT_ALIGNMENT_CENTER, "RANDOM SURFER", wxDefaultPosition, wxSize(100, 20));
        stat->SetForegroundColour(wxColor("#061226"));
        this->bx->Add(stat);
        this->panel1();
        this->panel2();
        this->panel3();
        this->panel4();
        this->ListPanel();
        this->SetSizer(this->bx);
    }
    void surfer(wxCommandEvent &ev);
    void rank(wxCommandEvent &ev);
    void clear(wxCommandEvent &ev);
};

void Frame::surfer(wxCommandEvent &ev)
{
    std::string number_of_visitors = std::string(this->visitors->GetValue());
    std::string number_of_iterations = std::string(this->iterations->GetValue());
    std::string number_of_pages = std::string(this->pages->GetValue());

    if (number_of_pages.empty() || number_of_visitors.empty() || number_of_iterations.empty())
    {
        wxMessageBox("Fill all the blanks");
        return;
    }

    int nv = std::stoi(number_of_visitors);
    int ni = std::stoi(number_of_iterations);
    int np = std::stoi(number_of_pages);
    if (nv == 0 || ni == 0 || np == 0)
    {
        wxMessageBox("Invalid data!Algorithm terimanted");
        return;
    }
    Surfer s(np,np);
    int iter = 1;
    std::string msg = "RANDOM SURFER ALGORITHM\n";
    std::vector<navigate> accs = s.random_surfer(nv, ni);
    msg += "Iteration " + std::to_string(iter) + "\n";
    for (int i = 0, t = accs.size(); i < t; i++)
    {
        if (i % nv == 0 && i != 0)
        {
            msg += "Iteration " + std::to_string(iter) + "\n";
            iter++;
        }
        msg += "Visitor " + std::to_string(accs.at(i).id) + " goes from web " + accs.at(i).from + " to web " + accs.at(i).to + "\n";
    }
    wxMessageBox(msg);
    std::cout<<s<<std::endl;
}

void Frame::rank(wxCommandEvent &ev)
{
    this->ClearList();
    int countelem = 0;
    if (matrix::rank.empty())
    {
        wxMessageBox("Surfer algorithm does not initiated yet!Run the Surfer Algorithm first");
        return;
    }
    std::priority_queue<grank> pr = Surfer::Page_rank();
    while (!pr.empty())
    {
        wxListItem wx;
        wx.SetId(countelem);
        wx.SetText("");
        this->ranks->InsertItem(wx);
        this->ranks->SetItem(countelem, 0, "Web Page " + std::to_string(pr.top().page));
        this->ranks->SetItem(countelem, 1, std::to_string(pr.top().grade));
        pr.pop();
        countelem++;
    }
    std::string message = "Page Rank for::\n";
    message += Surfer::info;
    wxMessageBox(message);
}

void Frame::clear(wxCommandEvent &ev)
{
    this->visitors->SetValue("");
    this->iterations->SetValue("");
    this->pages->SetValue("");
    this->ClearList();
}

class app : public wxApp
{
public:
    bool OnInit() wxOVERRIDE
    {
        Frame *f = new Frame;
        f->Show();
        return true;
    }
};

wxIMPLEMENT_APP(app);