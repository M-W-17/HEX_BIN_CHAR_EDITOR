#include "UserInterface.h"
#include "DataConverter.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

// Konstanten für die Seitenberechnung
const std::size_t BYTES_PER_LINE = 16;
const std::size_t LINES_PER_PAGE = 16;
const std::size_t BYTES_PER_PAGE = BYTES_PER_LINE * LINES_PER_PAGE;

// Seitenankalkulator
std::size_t calculateTotalPages(std::size_t totalBytes)
{
    return (totalBytes + BYTES_PER_PAGE - 1) / BYTES_PER_PAGE;
}

// Wertausgabe des Kalkulators
std::size_t UserInterface::getTotalPages(const std::vector<uint8_t>& data) const
{
    return calculateTotalPages(data.size());
}

//Hauptmenü
int UserInterface::showMainMenue()
{
    //Hauptmenü Darstellung
    int choice;

    std::cout << "=======================================" << std::endl;
    std::cout << "         HEX/BIN/CHAR_EDITOR"            << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << std::endl;

    //Darstellung der Auswahl
    std::cout << "[1] Datei laden\n";
    std::cout << "[2] Datei bearbeiten\n";
    std::cout << "[3] Datei anzeigen\n";
    std::cout << "[4] Datei speichern\n";
    std::cout << "[0] Programm beenden\n";

    //Eingabe der Auswahl
    std::cout << "\n Ihre Auswahl: ";
    if (!(std::cin >> choice))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << "Ungueltige Eingabe. Bitte eine Zahl eingeben.\n";

        return -1;
    }


    //Prüfung der Eingabe
    if (choice < 0 || choice > 4)
    {
        std::cerr << "Falsche Eingabe.";
    }
    return choice;
}

//Auswahlmenü Byte-Bearbeitung
int UserInterface::showEditMenue()
{
    int choice;

    std::cout << "\n======================================\n";
    std::cout << "            BYTE-BEARBEITUNG";
    std::cout << "\n======================================\n";

    std::cout << "[1] HEX bearbeiten\n";
    std::cout << "[2] BIN bearbeiten\n";
    std::cout << "[3] CHAR bearbeiten\n";
    std::cout << "[4] Byte anzeigen\n";
    std::cout << "[0] Zurueck\n";

    std::cout << "\nIhre Auswahl: ";
    if (!(std::cin >> choice))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << "Ungueltige Eingabe. Bitte eine Zahl eingeben.\n";
        return -1;
    }

    // Prüfung der Eingabe
    if (choice < 0 || choice > 4) {

        std::cerr << "Falsche Eingabe.";
    }

    return choice;
}

//Tabellendarstellung
void UserInterface::showBytes(const std::vector<uint8_t>& data, std::size_t page)
{
    // Anzeigen einer leeren Datei
    if (data.empty())
    {
        std::cout << "\nDie Datei ist leer. Keine Daten zum Anzeigen vorhanden.\n";
        return;
    }

    // Seitenanzahl ermitteln und Ausgeben
    std::size_t totalPages = calculateTotalPages(data.size());

    std::cout << "\nDateigroesse: " << data.size() << " Bytes\n";
    std::cout << "Gesamtseiten: " << totalPages << '\n';
    std::cout << "Aktuelle Seite: " << page + 1 << " von " << totalPages << "\n";


    std::size_t startIndex = page * BYTES_PER_PAGE;
    std::size_t endIndex = std::min(
        startIndex + BYTES_PER_PAGE,
        data.size()
    );

    // Tabellendarstellung
    std::cout << "\nOFFSET\tHEX\tBIN           CHAR\n";
    std::cout << "------------------------------------------\n";

    for (std::size_t i = startIndex; i < endIndex; ++i)
    {
        uint8_t value = data[i];

        std::cout << i << "\t"
                  << convertToHex(value) << "\t"
                  << convertToBin(value) << "   "
                  << convertToChar(value) << '\n';
    }
}

// Navigationspunkte (Nächste Seite/ Seite zurrück/ zum Menü zurück
char UserInterface::getPageNavigationInput()
{

    char choice;

    std::cout << "\n[N] Naechste Seite";
    std::cout << "\n[P] Vorherige Seite";
    std::cout << "\n[Q] Zurueck zum Menue";
    std::cout << "\nAuswahl: ";

    std::cin >> choice;

    return static_cast<char>(std::toupper(
        static_cast<unsigned char>(choice)
    ));
}