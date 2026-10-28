#include "Controller.h"
#include "DataConverter.h"

#include <iostream>
#include <string>
#include <limits>

//Programmstart
Controller::Controller()
    : fileLoaded(false), running(true)
{
}

void Controller::run(int argc, char* argv[]) {

    // Prüfen, ob beim Programmstart ein Dateipfad übergeben wurde
    if (argc > 1)
    {
        currentFilePath = argv[1];

        if (manager.loadFile(currentFilePath))
        {
            fileLoaded = true;
            currentPage = 0;

            std::cout << "Datei erfolgreich geladen: "
                      << currentFilePath << "\n";

            showPagedFile();
        }
        else
        {
            std::cout << "Datei konnte nicht geladen werden: "
                      << currentFilePath << "\n";
        }
    }

    while (running)
    {
        int choice = ui.showMainMenue();

        switch (choice) // Menüauswahl Hauptmenü
        {

            case 1: // Laden einer Datei
            {
                std::string filePath;

                std::cout << "Dateipfad eingeben: ";

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n');

                std::getline(std::cin, filePath);

                // Überprüfung der Datei
                if (manager.loadFile(filePath))
                {
                    currentFilePath = filePath;
                    fileLoaded = true;

                    currentPage = 0;
                    showPagedFile();
                }
                else //Fehlerausgabe bei nicht geladener Datei
                {
                    std::cout << "Datei konnte nicht geladen werden.\n";
                }

                break;
            }

            case 2: // Datei bearbeiten
            {
                if (!fileLoaded) //Prüfung ob eine Datei im Speicher vorhanden ist.
                {
                    std::cout << "Bitte zuerst eine Datei laden.\n";
                    break;
                }

                bool editing = true;

                while (editing)
                {

                    int editChoice = ui.showEditMenue(); //Funktion Menü Auswahl

                    switch (editChoice) // Menü Auswahl Byte-Bearbeitung
                    {
                        case 1: //HEX Eingabe
                        {
                            long long inputOffset;
                            std::string hexInput;

                            std::cout << "Offset eingeben: ";

                            if (!(std::cin >> inputOffset))
                            {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');

                                std::cout << "Ungueltiger Offset. Bitte eine Zahl eingeben.\n";
                                break;
                            }

                            if (inputOffset < 0)
                            {
                                std::cout << "Offset darf nicht negativ sein.\n";
                                break;
                            }

                            std::size_t offset = static_cast<std::size_t>(inputOffset);

                            std::cout << "Neuen HEX-Wert eingeben: ";
                            std::cin >> hexInput;

                            uint8_t newValue;

                            if (convertHexInput(hexInput, newValue))
                            {
                                if (manager.editByte(offset, newValue))
                                {
                                    std::cout << "Byte erfolgreich geaendert.\n";
                                    showPagedFile();
                                }
                                else
                                {
                                    std::cout << "Ungueltiges Offset.\n";
                                }
                            }
                            else
                            {
                                std::cout << "Ungueltiger HEX-Wert.\n";
                            }

                            break;
                        }

                        case 2: //BIN Eingabe
                        {
                            long long inputOffset;
                            std::string binInput;

                            std::cout << "Offset eingeben: ";

                            if (!(std::cin >> inputOffset))
                            {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');

                                std::cout << "Ungueltiger Offset. Bitte eine Zahl eingeben.\n";
                                break;
                            }

                            if (inputOffset < 0)
                            {
                                std::cout << "Offset darf nicht negativ sein.\n";
                                break;
                            }

                            std::size_t offset = static_cast<std::size_t>(inputOffset);

                            std::cout << "Neuen BIN-Wert eingeben: ";
                            std::cin >> binInput;

                            uint8_t newValue;

                            if (convertBinInput(binInput, newValue))
                            {
                                if (manager.editByte(offset, newValue))
                                {
                                    std::cout << "Byte erfolgreich geaendert.\n";
                                    showPagedFile();
                                }
                                else
                                {
                                    std::cout << "Ungueltiges Offset.\n";
                                }
                            }
                            else
                            {
                                std::cout << "Ungueltiger BIN-Wert.\n";
                            }

                            break;
                        }

                        case 3: //CHAR Eingabe
                        {
                            long long inputOffset;
                            std::string charInput;

                            std::cout << "Offset eingeben: ";

                            if (!(std::cin >> inputOffset))

                            {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');

                                std::cout << "Ungueltiger Offset. Bitte eine Zahl eingeben.\n";
                                break;
                            }

                            if (inputOffset < 0)
                            {
                                std::cout << "Offset darf nicht negativ sein.\n";
                                break;
                            }

                            std::size_t offset = static_cast<std::size_t>(inputOffset);

                            std::cout << "Neues Zeichen eingeben: ";

                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                            std::getline(std::cin, charInput);

                            uint8_t newValue;

                            if (convertCharInput(charInput, newValue))
                            {
                                if (manager.editByte(offset, newValue))
                                {
                                    std::cout << "Byte erfolgreich geaendert.\n";
                                    showPagedFile();
                                }
                                else
                                {
                                    std::cout << "Ungueltiges Offset.\n";
                                }
                            }
                            else
                            {
                                std::cout << "Ungueltige CHAR-Eingabe. Bitte ein Zeichen eingeben.\n";
                            }

                            break;
                        }

                        case 4:
                            showPagedFile();
                            break;

                        case 0:
                            std::cout << "Zurueck zum Hauptmenue.\n";
                            editing = false;
                            break;

                        default:
                            std::cout << "Ungueltige Auswahl.\n";
                            break;
                    }

                }
            }
                break;

            case 3: // Datei Anzeigen
            {
                if (fileLoaded)
                {
                    showPagedFile();
                }
                else
                {
                    std::cout << "Bitte zuerst eine Datei laden.\n";
                }

                break;
            }

            case 4:
            {
                if (!fileLoaded)
                {
                    std::cout << "Bitte zuerst eine Datei laden.\n";
                    break;
                }

                if (manager.saveFile(currentFilePath))
                {
                    std::cout << "Datei erfolgreich gespeichert.\n";
                    showPagedFile();
                }
                else
                {
                    std::cout << "Fehler beim Speichern der Datei.\n";
                }

                break;
            }

            case 0: //Auswahlpunkt Programmende
            {
                std::cout << "Programm wird beendet.\n";
                running = false;
                break;
            }

            default: // Prüfung auf Ungültige Eingabe
            {
                std::cout << "Ungueltige Auswahl.\n";
                break;
            }
        }
    }
}

//Navigationsfunktion
void Controller::showPagedFile()
{
    if (manager.getData().empty())
    {
        ui.showBytes(manager.getData(), currentPage);
        return;
    }

    bool browsing = true;

    while (browsing)
    {
        ui.showBytes(manager.getData(), currentPage);

        char navigation = ui.getPageNavigationInput();

        std::size_t totalPages = ui.getTotalPages(manager.getData());

        if (navigation == 'N')
        {
            if (currentPage + 1 < totalPages)
            {
                ++currentPage;
            }
            else
            {
                std::cout << "Du bist bereits auf der letzten Seite.\n";
            }
        }
        else if (navigation == 'P')
        {
            if (currentPage > 0)
            {
                --currentPage;
            }
            else
            {
                std::cout << "Du bist bereits auf der ersten Seite.\n";
            }
        }
        else if (navigation == 'Q')
        {
            browsing = false;
        }
        else
        {
            std::cout << "Ungueltige Eingabe.\n";
        }
    }
}