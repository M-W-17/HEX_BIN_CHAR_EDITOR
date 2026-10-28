

#ifndef HEX_BIN_CHAR_EDITOR_USERINTERFACE_H
#define HEX_BIN_CHAR_EDITOR_USERINTERFACE_H
#include <vector>
#include <cstdint>
#include <cstddef>

class UserInterface
{
    public:
        int showMainMenue();
        int showEditMenue();



    void showBytes(const std::vector<uint8_t>& data, std::size_t page);

    char getPageNavigationInput();

    std::size_t getTotalPages(const std::vector<uint8_t>& data) const;
};

#endif //HEX_BIN_CHAR_EDITOR_USERINTERFACE_H