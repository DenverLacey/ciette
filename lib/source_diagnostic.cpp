#include "source_diagnostic.h"

#include <math.h>
#include <iomanip>

namespace ciette {

    std::ostream& SourceDiagnostic::write(std::ostream& s) const {
        auto snippet = this->span.snippet(this->source.source);
        int width = log10(snippet.lineno + 1) + 1;

        s << "--- " << this->kind << " --- " << this->source.file_name << " ------" << std::endl;

        s << std::setw(width) << ' ' << " | " << std::setw(0) << std::endl;
        s << snippet.lineno << " | " << snippet.line << std::endl;
        s << std::setw(width) << ' ' << " | " << std::setw(snippet.column) << ' ' << std::setw(snippet.length + 1) << std::setfill('^') << ' ' << std::setw(0) << std::setfill(' ') << std::endl;

        if (!this->span.text().empty()) {
            s << std::setw(width) << ' ' << " | " << std::setw(snippet.column) << ' ' << this->span.text() << std::setw(0) << std::endl;
        }

        if (!this->notes.empty()) {
            s << std::endl;

            for (const Note& note : this->notes) {
                s << note << std::endl;
            }
        }

        return s;
    }

}
