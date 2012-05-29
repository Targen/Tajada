#include <string>

// Class:
#include "Tajada/Code/Intermediate/Address/Immediate/Float.hh"

// Superclasses:
#include "Tajada/Code/Address.hh"
#include "Tajada/Code/Intermediate/Address/Address.hh"
#include "Tajada/Code/Intermediate/Address/Immediate/Immediate.hh"

namespace Tajada {
        namespace Code {
                namespace Intermediate {
                        namespace Address {
                                namespace Immediate {
                                        Float::Float(
                                                float p_value
                                        ):
                                                Tajada::Code::Address(),
                                                Tajada::Code::Intermediate::Address::Address(),
                                                Tajada::Code::Intermediate::Address::Immediate::Immediate(),

                                                value(p_value)
                                        {}



                                        std::string Float::show() {
                                                return std::to_string(this->value);
                                        }
                                }
                        }
                }
        }
}
