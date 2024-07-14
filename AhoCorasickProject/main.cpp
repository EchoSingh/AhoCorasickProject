#include <wx/wx.h>
#include "Visualization.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    VisualizationFrame* frame = new VisualizationFrame("Aho-Corasick Visualization", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
