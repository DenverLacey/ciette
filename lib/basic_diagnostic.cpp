#include "basic_diagnostic.h"

namespace ciette {

    std::ostream& BasicDiagnostic::write(std::ostream& s) const {
        return s << this->message;
    }

}
