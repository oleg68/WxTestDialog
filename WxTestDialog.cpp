#include "WxTestDialog.hpp"

#include <wx/bookctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/treectrl.h>

class TestTreeCtrl : public wxTreeCtrl {
public:
  TestTreeCtrl(wxWindow *parent)
  : wxTreeCtrl(
    parent,
    wxID_ANY,
    wxDefaultPosition,
    wxSize(100, 100),
    wxTR_HAS_BUTTONS | wxTR_SINGLE) {}

  virtual wxSize DoGetBestSize() const override {
    return GetMinSize();
  }
};


WxTestDialog::Page1::Page1(wxWindow *parent) : wxPanel(parent, wxID_ANY)
{
  wxSizer *topSizer = new wxBoxSizer(wxVERTICAL);

  m_Tmp = new TestTreeCtrl(this);
  topSizer->Add(m_Tmp, 1, wxEXPAND | wxALL, 5);
  topSizer->Add(
    new wxStaticText(this, wxID_ANY, "Tree:"),
    0, wxEXPAND | wxALL, 5);

  m_AudioOutput = new TestTreeCtrl(this);
  topSizer->Add(m_AudioOutput, 1, wxEXPAND | wxALL, 5);

  SetSizerAndFit(topSizer);

}

bool WxTestDialog::Page1::TransferDataToWindow()
{
  wxTreeItemId tmpRootNode = m_Tmp->AddRoot("Tmp Root");

  m_Tmp->AppendItem(tmpRootNode, "1");
  m_Tmp->AppendItem(tmpRootNode, "2");
  m_Tmp->Expand(tmpRootNode);

  wxTreeItemId rootNode = m_AudioOutput->AddRoot("Audio Output");

  for (int i = 1; i < 15; i++)
    m_AudioOutput->AppendItem(rootNode, wxString::Format("Child%i", i));
  m_AudioOutput->Expand(rootNode);
  return true;
}

WxTestDialog::Page2::Page2(wxWindow *parent) : wxPanel(parent, wxID_ANY)
{
  
}

WxTestDialog::WxTestDialog(wxWindow *parent, const wxString &title)
  : GOTabbedDialog(parent, "Test", "Test", wxDIALOG_NO_PARENT)
{
  wxBookCtrlBase *const notebook = GetBook();

  m_page1 = new Page1(notebook);
  AddTab(m_page1, "Page1", "Page1");
  m_page2 = new Page2(notebook);
  AddTab(m_page2, "Page2", "Page2");

  LayoutDialog();
}

WxTestDialog::~WxTestDialog() {}
