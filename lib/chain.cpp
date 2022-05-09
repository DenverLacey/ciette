#include "chain.h"

namespace ciette {

    /// == Chain ==
    Chain& Chain::append(Diagnostic* diagnostic) {
        auto unique = std::unique_ptr<ChainNode>{ 
            new ChainNode { 
                std::unique_ptr<Diagnostic>{ diagnostic }, 
                std::unique_ptr<ChainNode>{ nullptr } 
            } 
        };

        if (this->_last) {
            this->_last->next = std::move(unique);
            this->_last = this->_last->next.get();
        } else {
            assert(this->_first.get() == nullptr);
            this->_first = std::move(unique);
            this->_last = this->_first.get();
        }

        return *this;
    }
    
    std::ostream& Chain::write(std::ostream& s) const {
        for (const auto& diagnostic : *this) {
            diagnostic.write(s);
            s << std::endl;
        }

        return s;
    }

    Chain::iterator Chain::begin() const {
        return { this->_first.get() };
    }

    Chain::iterator Chain::end() const {
        return { this->_last->next.get() };
    }

    /// == ChainIterator ==

    ChainIterator::reference ChainIterator::operator*() const {
        return *this->it->diagnostic.get();
    }

    ChainIterator::pointer ChainIterator::operator->() {
        return this->it->diagnostic.get();
    }

    ChainIterator& ChainIterator::operator++() {
        this->it = this->it->next.get();
        return *this;
    }

    ChainIterator ChainIterator::operator++(int) {
        auto temp = *this;
        ++(*this);
        return temp;
    }

    bool ChainIterator::operator==(const ChainIterator& other) {
        return this->it == other.it;
    }

    bool ChainIterator::operator!=(const ChainIterator& other) {
        return !(*this == other);
    }

}
