#ifndef TAJADA_CODE_INTERMEDIATE_INSTRUCTION_MODULO_HH
#define TAJADA_CODE_INTERMEDIATE_INSTRUCTION_MODULO_HH

#include <string>

// Superclasses:
#include "Tajada/Code/Intermediate/Instruction/Instruction.hh"

#include "Tajada/Code/Intermediate/Address/Address.hh"

namespace Tajada {
        namespace Code {
                namespace Intermediate {
                        namespace Instruction {
                                class Modulo:
                                        public virtual Tajada::Code::Intermediate::Instruction::Instruction
                                {
                                        public:
                                                Tajada::Code::Intermediate::Address::Address * dst ;
                                                Tajada::Code::Intermediate::Address::Address * lsrc;
                                                Tajada::Code::Intermediate::Address::Address * rsrc;

                                                Modulo(
                                                        Tajada::Code::Intermediate::Address::Address * p_dst ,
                                                        Tajada::Code::Intermediate::Address::Address * p_lsrc,
                                                        Tajada::Code::Intermediate::Address::Address * p_rsrc
                                                );

                                                virtual std::string show();
                                };
                        }
                }
        }
}

#endif
