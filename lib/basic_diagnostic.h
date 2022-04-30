#pragma once

#include "diagnostic.h"

#include <string>

namespace ciette {

    class BasicDiagnostic : public Diagnostic {
        std::string message;

    public:
        BasicDiagnostic(std::string message) : message(std::move(message)) {}
        std::ostream& write(std::ostream& s) const override;
    };

}
