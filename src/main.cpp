#include <iostream>

#include "basic_diagnostic.h"
#include "source_span.h"

int main() {
    auto basic = ciette::BasicDiagnostic{ "Hello, ciette!" };
    std::cout << basic << std::endl;

    auto span = ciette::SourceSpan{ 0, 1 };
    auto labeled = ciette::LabeledSourceSpan{ "label", span };
    return 0;
}
