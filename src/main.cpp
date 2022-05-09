#include <iostream>

#include "basic_diagnostic.h"
#include "full_diagnostic.h"
#include "source_span.h"

int main() {
    const char *source = "hello\nthis is sme source.";
    auto full = ciette::FullDiagnostic{ 
        "Spelling Mistake!", 
        source, 
        { "This is spelled incorrectly", 14, 3 }, 
        { 
            { ciette::NoteKind::Hint, "Maybe you meant 'some'." } 
        }
    };

    std::cout << full;

    return 0;
}
