#pragma once

#include "diagnostic.h"

#include <string>
#include <vector>

#include "source_span.h"
#include "note.h"

namespace ciette {

    class FullDiagnostic : public Diagnostic {
        std::string kind;
        std::string_view source;
        LabeledSourceSpan span;
        std::vector<Note> notes;

    public:
        FullDiagnostic(std::string kind, std::string_view source, const LabeledSourceSpan& span, const std::vector<Note>& notes) :
            kind(std::move(kind)),
            source(source),
            span(std::move(span)),
            notes(std::move(notes))
        {
        }

    public:
        std::ostream& write(std::ostream& s) const override;
    };

}
