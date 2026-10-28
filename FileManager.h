//
// Created by maikw on 22.10.2026.
//

#ifndef HEX_BIN_CHAR_EDITOR_FILEMANAGER_H
#define HEX_BIN_CHAR_EDITOR_FILEMANAGER_H

#include <vector>
#include <cstdint>
#include <string>
#include <cstddef>

class FileManager
{
    private:

        std::vector<uint8_t> data;

    public:

        FileManager();

        bool loadFile(const std::string& filePath);
        bool saveFile(const std::string& filePath) const;
        bool editByte(std::size_t offset, uint8_t newValue);

        std::size_t getFileSize() const;
        const std::vector<uint8_t>& getData() const;



};

#endif //HEX_BIN_CHAR_EDITOR_FILEMANAGER_H