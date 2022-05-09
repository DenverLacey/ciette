#pragma once

#include <string>

namespace ciette {

    enum class NoteKind {
        Note,
        Hint
    };
    
    struct Note {
        NoteKind kind;
        std::string note;
    };
    
}
