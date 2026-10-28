#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "FileManager.h"
#include "UserInterface.h"
#include <vector>
#include <cstdint>

class Controller
{
private:
    FileManager manager;
    UserInterface ui;

    bool fileLoaded;
    bool running;

    std::string currentFilePath;
    std::size_t currentPage = 0;

    void showPagedFile();

public:
    Controller();

    void run(int argc, char* argv[]);


};

#endif