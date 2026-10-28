#include "DataConverter.h"

#include <sstream>
#include <cctype>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <bitset>


// HEX-Eingabe in Byte umwandeln
bool convertHexInput(const std::string& input, uint8_t& result)
{
    // 1. Prüfen, ob die Eingabe leer ist
    if (input.empty())
    {
        return false;
    }

    // 2. HEX-Eingabe vorbereiten
    std::string hexValue = input;

    // Optionales 0x oder 0X entfernen
    if (hexValue.size() > 2 &&
        hexValue[0] == '0' &&
        (hexValue[1] == 'x' || hexValue[1] == 'X'))
    {
        hexValue = hexValue.substr(2);
    }

    // Prüfen, ob nach dem Entfernen noch Zeichen vorhanden sind
    if (hexValue.empty())
    {
        return false;
    }

    // 3. Gültige HEX-Zeichen prüfen
    for (char c : hexValue)
    {
        if (!std::isxdigit(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }

    // 4. HEX-Zeichenfolge in eine Zahl umwandeln
    try
    {
        std::size_t processedChars = 0;

        unsigned long value = std::stoul(hexValue, &processedChars, 16);

        // Prüfen, ob alles verarbeitet wurde
        if (processedChars != hexValue.length())
        {
            return false;
        }

        // Prüfen, ob der Wert maximal FF beträgt
        if (value > 0xFF)
        {
            return false;
        }

        // Ergebnis speichern
        result = static_cast<uint8_t>(value);

        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
}

// BIN-Eingabe in Byte umwandeln
bool convertBinInput(const std::string& input, uint8_t& result)
{
    // 1. Genau 8 Zeichen erforderlich
    if (input.length() != 8)
    {
        return false;
    }

    // 2. Prüfen, ob nur 0 und 1 enthalten sind
    for (char c : input)
    {
        if (c != '0' && c != '1')
        {
            return false;
        }
    }

    // 3. Binärzahl in Dezimalzahl umwandeln
    unsigned long value = std::stoul(input, nullptr, 2);

    // 4. Ergebnis speichern
    result = static_cast<uint8_t>(value);

    return true;
}

// CHAR-Eingabe in Byte umwandeln
bool convertCharInput(const std::string& input, uint8_t& result)
{
    if (input.length() != 1)
    {
        return false;
    }

    result = static_cast<uint8_t>(
        static_cast<unsigned char>(input[0])
    );

    return true;
}

// Byte in HEX umwandeln
std::string convertToHex(uint8_t value)
{
    std::stringstream stream;

    stream << std::uppercase
           << std::hex
           << std::setw(2)
           << std::setfill('0')
           << static_cast<int>(value);

    return "0x" + stream.str();
}

// Byte in BIN umwandeln
std::string convertToBin(uint8_t value)
{
    std::bitset<8> bits(value);

    return bits.to_string();
}

// Byte in CHAR umwandeln
char convertToChar(uint8_t value)
{
    unsigned char character = value;

    if (std::isprint(character))
    {
        return static_cast<char>(character);
    }

    return '.';
}

