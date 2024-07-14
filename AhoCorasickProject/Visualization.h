#pragma once
#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <wx/wx.h>
#include "AhoCorasick.h"

class VisualizationFrame : public wxFrame {
public:
    VisualizationFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    void OnOpen(wxCommandEvent& event);
    void OnRun(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);

    wxDECLARE_EVENT_TABLE();

    AhoCorasick* ahoCorasick;
    std::vector<std::string> patterns;
    std::string text;
    std::vector<std::pair<int, int>> results;
};

enum {
    ID_Open = 1,
    ID_Run = 2
};

#endif // VISUALIZATION_H
