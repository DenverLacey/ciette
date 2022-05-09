#pragma once

#include "diagnostic.h"
#include <memory>
#include <iterator>

namespace ciette {

    struct ChainNode {
        std::unique_ptr<Diagnostic> diagnostic;
        std::unique_ptr<ChainNode> next;
    };

    class ChainIterator {
        ChainNode* it;
    
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = Diagnostic;
        using pointer = Diagnostic*;
        using reference = Diagnostic&;

    public:
        ChainIterator(ChainNode* node) : it(node) {}

    public:
        reference operator*() const;
        pointer operator->();
        ChainIterator& operator++();
        ChainIterator operator++(int);
        bool operator==(const ChainIterator& other);
        bool operator!=(const ChainIterator& other);
    };

    class Chain : public Diagnostic {
        std::unique_ptr<ChainNode> _first;
        ChainNode* _last;

    public:
        using iterator = ChainIterator;
        iterator begin() const;
        iterator end() const;
    
    public:
        Chain& append(Diagnostic* diagnostic);

    public:
        std::ostream& write(std::ostream& s) const override;
    };

}
