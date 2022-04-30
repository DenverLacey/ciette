#include <stddef.h>
#include <string>

namespace ciette {

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
    };

    class LabeledSourceSpan : public SourceSpan {
        std::string _label;

    public:
        LabeledSourceSpan(std::string label, size_t start, size_t length) :
            SourceSpan(start, length),
            _label(std::move(label))
        {
        }

        LabeledSourceSpan(std::string label, SourceSpan span) :
            SourceSpan(span.start(), span.length()),
            _label(std::move(label))
        {
        }

        LabeledSourceSpan(const LabeledSourceSpan& other) = default;
        LabeledSourceSpan(LabeledSourceSpan&& other) = default;
    
    public:
        inline const std::string& label() const {
            return this->_label;
        }

        inline const SourceSpan& span() const {
            return *reinterpret_cast<const SourceSpan*>(this);
        }
    };

}
