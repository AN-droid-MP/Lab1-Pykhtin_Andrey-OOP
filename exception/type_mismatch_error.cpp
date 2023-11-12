#include <exception>
#include <string>


class type_mismatch_error : public std::exception {
private:
    std::string errorMessage;

public:
    explicit type_mismatch_error(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};