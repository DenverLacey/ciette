#pragma once

#include <ostream>
#include <string_view>

namespace ciette {

    class Diagnostic {
    public:
        virtual ~Diagnostic() {}

        virtual std::ostream& write(std::ostream& s) const = 0;

        friend std::ostream& operator<<(std::ostream& s, const Diagnostic& diagnostic) {
            return diagnostic.write(s);
        }
    };

}
