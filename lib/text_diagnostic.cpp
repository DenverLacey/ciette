#include "text_diagnostic.h"

namespace ciette {

    std::ostream& TextDiagnostic::write(std::ostream& s) const {
        return s << this->message;
    }

}
