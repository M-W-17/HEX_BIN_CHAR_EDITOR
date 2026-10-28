#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <cctype>

FileManager::FileManager()
{
    std::cout << "FileManager initialisiert." << std::endl;
}

bool FileManager::loadFile(const std::string& filePath)
{
    // Datei in Binärmodus öffnen
    std::ifstream file(filePath, std::ios::binary);

    // Prüfen, ob die Datei geöffnet wurde
    if (!file.is_open())
    {
     std::cerr << "Fehler: Datei konnte nicht geoeffnet werden." << std::endl;

     return false;
    }

    //Alten Datenbestand löschen
    data.clear();

    // Einzelne Bytes einlesen
    char byte;

    while (file.get(byte))
    {
        data.push_back(static_cast<uint8_t>(static_cast<unsigned char>(byte)));
    }

    // Datei schließen
    file.close();

    std::cout << "Datei erfolgreich geladen." << std::endl;

    return true;
}

bool FileManager::saveFile(const std::string& filePath) const
{
    // Datei im Binärmodus zum Schreiben öffnen
    std::ofstream file(filePath, std::ios::binary | std::ios::trunc);

    //Prüfen, ob die Datei geöffnet werden konnte
    if (!file.is_open())
    {
        std::cout << "Fehler: Datei konnte nicht gespeichert werden.\n";
        return false;
    }

    // Bytes in die Datei schreiben
    if (!data.empty())
    {
        file.write(reinterpret_cast<const char*>(data.data()),static_cast<std::streamsize>(data.size()));
    }

    // Schreibpuffer leeren
    file.flush();

    // Prüfen, ob das Schreiben erfolgreich war
    if (!file)
    {
        std::cout << "Fehler beim Schreiben der Datei.\n";
        return false;
    }

    // Datei schließen
    file.close();

    // Prüfen, ob das Schließen erfolgreich war
    if (!file)
    {
        std::cout << "Fehler beim Schließen der Datei.\n";
        return false;
    }

    return true;

}

bool FileManager::editByte(std::size_t offset, uint8_t newValue)
{
    std::cout << "\n--- BYTE-BEARBEITUNG ---\n";
    std::cout << "Offset: " << offset << "\n";
    std::cout << "Neuer Wert: "
              << std::hex << static_cast<int>(newValue)
              << std::dec << "\n";

    std::cout << "Dateigroesse im Speicher: "
              << data.size() << " Bytes\n";

    if (offset >= data.size())
    {
        std::cerr << "Fehler: Offset ausserhalb der Datei.\n";
        return false;
    }

    std::cout << "Alter Wert: "
              << std::hex << static_cast<int>(data[offset])
              << std::dec << "\n";

    data[offset] = newValue;

    std::cout << "Neuer Wert im Speicher: "
              << std::hex << static_cast<int>(data[offset])
              << std::dec << "\n";

    return true;
}

std::size_t FileManager::getFileSize() const
{
    return data.size();
}

const std::vector<uint8_t>& FileManager::getData() const
{
    return data;
}

