#include <string>

// Class:
#include "Tajada/Code/Intermediate/Address/Immediate/Integer.hh"

// Superclasses:
#include "Tajada/Code/Address.hh"
#include "Tajada/Code/Intermediate/Address/Address.hh"
#include "Tajada/Code/Intermediate/Address/Immediate/Immediate.hh"

#include "Tajada/Code/MIPS/Address/Immediate/Integer.hh"

namespace Tajada {
        namespace Code {
                namespace Intermediate {
                        namespace Address {
                                namespace Immediate {
                                        Integer::Integer(
                                                unsigned int p_value
                                        ):
                                                Tajada::Code::Address(),
                                                Tajada::Code::Intermediate::Address::Address(),
                                                Tajada::Code::Intermediate::Address::Immediate::Immediate(),

                                                value(p_value)
                                        {}



                                        std::string Integer::show() {
                                                return
                                                        std::to_string(this->value)
                                                        + u8"[I]"
                                                ;
                                        }



                                        Tajada::Code::MIPS::Address::Address * Integer::to_mips() {
                                                return new Tajada::Code::MIPS::Address::Immediate::Integer(value);
                                        }
                                }
                        }
                }
        }
}
