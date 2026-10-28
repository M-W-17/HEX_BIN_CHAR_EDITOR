//
// Created by maikw on 26.10.2026.
//

#ifndef HEX_BIN_CHAR_EDITOR_DATACONVERTER_H
#define HEX_BIN_CHAR_EDITOR_DATACONVERTER_H

#include <cstdint>
#include <string>

bool convertHexInput(const std::string& input, uint8_t& result);
bool convertBinInput(const std::string& input, uint8_t& result);
bool convertCharInput(const std::string& input, uint8_t& result);

std::string convertToHex(uint8_t value);
std::string convertToBin(uint8_t value);
char convertToChar(uint8_t value);

#endif //HEX_BIN_CHAR_EDITOR_DATACONVERTER_H