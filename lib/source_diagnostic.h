#pragma once

#include "diagnostic.h"

#include <string>
#include <vector>

#include "source_span.h"
#include "note.h"

namespace ciette {

    class SourceDiagnostic : public Diagnostic {
        std::string kind;
        OpenedSource source;
        SourceSpanWithText span;
        std::vector<Note> notes;

    public:
        SourceDiagnostic(std::string kind, OpenedSource source, const SourceSpanWithText& span, const std::vector<Note>& notes) :
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
