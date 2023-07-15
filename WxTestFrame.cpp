# include "WxTestFrame.hpp"

#include <iostream>

#include <wx/menu.h>

# include "WxTestDialog.hpp"

enum {
  ID_MODAL = 100,
  ID_MODALLESS
};

BEGIN_EVENT_TABLE(WxTestFrame, wxFrame)
  EVT_WINDOW_CREATE(WxTestFrame::OnCreate)
  EVT_SHOW(WxTestFrame::OnShow)
  EVT_CLOSE(WxTestFrame::OnClose)
  EVT_WINDOW_DESTROY(WxTestFrame::OnDestroy)

  EVT_MENU(wxID_EXIT, WxTestFrame::OnExit)

  EVT_MENU(ID_MODAL, WxTestFrame::OnModal)
  EVT_MENU(ID_MODALLESS, WxTestFrame::OnModalless)
END_EVENT_TABLE()

WxTestFrame::WxTestFrame()
        : wxFrame(NULL, wxID_ANY, "WxTest Frame")
{
  wxMenuBar *menuBar = new wxMenuBar;

  wxMenu *menuFile = new wxMenu;
  menuFile->Append(wxID_EXIT);
  menuBar->Append(menuFile, "&File");

  wxMenu *menuDialogs = new wxMenu;
  menuDialogs->Append(ID_MODAL, "Modal Dialog");
  menuDialogs->Append(ID_MODALLESS, "Modalless Dialog");
  menuBar->Append(menuDialogs, "&Dialogs");

  SetMenuBar(menuBar);
}

void WxTestFrame::OnCreate(wxWindowCreateEvent&) {
  std::cout << "onCreate" << std::endl;
}

void WxTestFrame::OnShow(wxShowEvent& e)
{
  std::cout << "onShow: " << e.IsShown() << std::endl;
}

void WxTestFrame::OnClose(wxCloseEvent&)
{
  std::cout << "onClose" << std::endl;
  Destroy();
}

void WxTestFrame::OnDestroy(wxWindowDestroyEvent&)
{
  std::cout << "onDestroy" << std::endl;
}

void WxTestFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void WxTestFrame::OnModal(wxCommandEvent& event)
{
  WxTestDialog dlg(this, "Modal Dialog");

  int rc = dlg.ShowModalAdvanced();

  std::cout << "ShowModal returned " << rc << std::endl;
}

void WxTestFrame::OnModalless(wxCommandEvent& event)
{
  WxTestDialog *dlg = new WxTestDialog(this, "Modal Dialog");

  dlg->ShowAdvanced();
}

