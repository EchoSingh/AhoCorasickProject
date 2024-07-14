#include "Visualization.h"
#include <fstream>
#include <sstream>

wxBEGIN_EVENT_TABLE(VisualizationFrame, wxFrame)
EVT_MENU(ID_Open, VisualizationFrame::OnOpen)
EVT_MENU(ID_Run, VisualizationFrame::OnRun)
EVT_PAINT(VisualizationFrame::OnPaint)
wxEND_EVENT_TABLE()

VisualizationFrame::VisualizationFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Open, "&Open Patterns...\tCtrl-O");
    menuFile->Append(ID_Run, "&Run Algorithm...\tCtrl-R");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to Aho-Corasick Visualization!");
}

void VisualizationFrame::OnOpen(wxCommandEvent& event) {
    wxFileDialog openFileDialog(this, _("Open Patterns file"), "", "",
        "Text files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    std::ifstream file(openFileDialog.GetPath().ToStdString());
    if (!file.is_open()) {
        wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return;
    }

    patterns.clear();
    std::string line;
    while (std::getline(file, line)) {
        patterns.push_back(line);
    }

    file.close();
    ahoCorasick = new AhoCorasick(patterns);
    ahoCorasick->build();
    SetStatusText("Patterns loaded and Aho-Corasick automaton built.");
}

void VisualizationFrame::OnRun(wxCommandEvent& event) {
    if (!ahoCorasick) {
        wxLogError("No patterns loaded.");
        return;
    }

    wxTextEntryDialog textDialog(this, "Enter the text to search:", "Run Aho-Corasick");
    if (textDialog.ShowModal() == wxID_CANCEL)
        return;

    text = textDialog.GetValue().ToStdString();
    results = ahoCorasick->search(text);

    Refresh();
}

void VisualizationFrame::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    if (!results.empty()) {
        dc.DrawText("Pattern found at positions:", 10, 10);
        int y = 30;
        for (const auto& result : results) {
            dc.DrawText(wxString::Format("Position: %d, Pattern Index: %d", result.first, result.second), 10, y);
            y += 20;
        }
    }
}
