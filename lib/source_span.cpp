#include "source_span.h"

namespace ciette {

    SourceSnippet SourceSpan::snippet(std::string_view source) const {
        size_t start = 0;
        size_t lineno = 1;
        size_t line_len = 0;
        size_t column = 0;

        size_t i;
        for (i = 0; i < this->_start; i++) {
            column++;
            line_len++;

            if (source[i] == '\n') {
                start = i + 1;
                lineno++;
                column = 0;
                line_len = 0;
            }
        }

        while (source[i] != '\n' && i < source.size()) {
            line_len++;
            i++;
        }

        return SourceSnippet {
            source.substr(start, line_len),
            lineno,
            column, 
            this->_length
        };
    }

}
