#pragma once

#include "diagnostic.h"

#include <string>

namespace ciette {

    class TextDiagnostic : public Diagnostic {
        std::string message;

    public:
        TextDiagnostic(std::string message) : message(std::move(message)) {}
        std::ostream& write(std::ostream& s) const override;
    };

}
