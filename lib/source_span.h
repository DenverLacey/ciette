#pragma once

#include <stddef.h>
#include <string>
#include <string_view>

namespace ciette {

    struct OpenedSource {
        const char *file_name;
        std::string_view source;
    };

    struct SourceSnippet {
        std::string_view line;
        size_t lineno;
        size_t column, length;
    };

    class SourceSpan {
        size_t _start;
        size_t _length;

    public:
        SourceSpan(size_t start, size_t length) : _start(start), _length(length) {}
    
    public:
        inline size_t start() const {
            return this->_start;
        }

        inline size_t length() const {
            return this->_length;
        }

        inline bool is_empty() const {
            return this->_length == 0;
        }

        SourceSnippet snippet(std::string_view source) const;
    };

    class SourceSpanWithText : public SourceSpan {
        std::string _text;

    public:
        SourceSpanWithText(std::string label, size_t start, size_t length) :
            SourceSpan(start, length),
            _text(std::move(label))
        {
        }

        SourceSpanWithText(std::string label, SourceSpan span) :
            SourceSpan(span.start(), span.length()),
            _text(std::move(label))
        {
        }

        SourceSpanWithText(const SourceSpanWithText& other) = default;
        SourceSpanWithText(SourceSpanWithText&& other) = default;
    
    public:
        inline const std::string& text() const {
            return this->_text;
        }

        inline const SourceSpan& span() const {
            return *reinterpret_cast<const SourceSpan*>(this);
        }
    };

}
