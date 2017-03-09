#include "internal/InputHandler.h"

int main() {
    InputHandler* app;
    app = new InputHandler(true);
    //main program loop
    while(app->GetStatus() == -1) {
        app->Run();
    }
    //Get error code
    int return_state = app->GetStatus();
    //clean assets
    app->Clean();
    delete app;
    //end program
    return return_state;
}
