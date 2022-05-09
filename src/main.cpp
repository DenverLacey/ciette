#include <iostream>

#include "text_diagnostic.h"
#include "source_diagnostic.h"
#include "chain.h"
#include "source_span.h"

int main() {
    const char *source = "a\nb\nc\n0\n1\n2\n3\nwhy\nhello\nthere\nthis is sme source.";
    auto full = new ciette::SourceDiagnostic { 
        "Spelling Mistake!", 
        { "source.txt", source },
        { "This is spelled incorrectly.", 38, 3 }, 
        // { "", 38, 3 },
        { 
            { ciette::NoteKind::Hint, "Maybe you meant 'some'." } 
        }
    };

    auto basic = new ciette::TextDiagnostic{ "Warning: This is a text diagnostic!" };

    auto chain = ciette::Chain{};
    chain
        .append(full)
        .append(basic);
    
    std::cout << chain;

    return 0;
}
