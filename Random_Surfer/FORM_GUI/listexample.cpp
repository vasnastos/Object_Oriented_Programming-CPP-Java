// Example uses fictive class "Item" and fictive getters to access them. Adapt for your needs
#include "wx/wx.h"
#include <wx/listctrl.h>
class MyFrame : public wxFrame
{
    wxListCtrl* m_item_list;

public:
    MyFrame() : wxFrame(NULL, wxID_ANY,  wxT("Hello wxWidgets"), wxPoint(50,50), wxSize(800,600))
    {
        wxPanel* mainPane = new wxPanel(this);
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        
        m_item_list = new wxListCtrl(mainPane, wxTEXT_ALIGNMENT_CENTER, wxPoint(300,300),wxSize(750,200),wxLC_VIRTUAL|wxLC_REPORT);
        // Add first column       
        wxListItem col0;
        col0.SetId(0);
        col0.SetText( _("Foo") );
        col0.SetWidth(200);
        m_item_list->InsertColumn(0, col0);
        
        // Add second column
        wxListItem col1;
        col1.SetId(1);
        col1.SetText( _("Name") );
        col1.SetWidth(200);
        m_item_list->InsertColumn(1, col1);
        
        // Add third column     
        wxListItem col2;
        col2.SetId(2);
        col2.SetWidth(200);
        col2.SetText( _("Comments") );
        m_item_list->InsertColumn(2, col2);
        sizer->Add(m_item_list);
        mainPane->SetSizer(sizer);
        m_item_list->InsertItem(0,"COLUMN1");
        m_item_list->InsertItem(1,"COLUMN2");
        m_item_list->InsertItem(2,"COLUMN3");
        m_item_list->SetItem(0,0,"COLUMN1");
        m_item_list->SetItem(0,1,"COLUMN2");
        m_item_list->SetItem(0,2,"COLUMN3");
        m_item_list->SetItem(1,0,"COLUMN1");
        m_item_list->SetItem(1,1,"COLUMN2");
        m_item_list->SetItem(1,2,"COLUMN3");
        m_item_list->SetItem(2,0,"COLUMN1");
        m_item_list->SetItem(2,1,"COLUMN2");
        m_item_list->SetItem(2,2,"COLUMN3");
    }
};
class MyApp: public wxApp
{
    wxFrame* m_frame;
public:
    
    bool OnInit()
    {
        m_frame = new MyFrame();
        m_frame->Show();
        return true;
    } 
    
};

IMPLEMENT_APP(MyApp)