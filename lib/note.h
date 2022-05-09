#pragma once

#include <string>
#include <ostream>

namespace ciette {

    enum class NoteKind {
        None,
        Note,
        Hint
    };
    
    struct Note {
        NoteKind kind;
        std::string note;

        friend std::ostream& operator<<(std::ostream& s, const Note& note) {
            switch (note.kind) {
                case NoteKind::None:
                    break;
                case NoteKind::Note:
                    s << "Note: ";
                    break;
                case NoteKind::Hint:
                    s << "Hint: ";
                    break;

                default:
                    assert(!"Invalid NoteKind");
            }

            s << note.note << std::endl;

            return s;
        }
    };
    
}
