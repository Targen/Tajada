// Class:
#include "Tajada/Code/MIPS/Instruction/sw.hh"

// Superclasses:
#include "Tajada/Code/Instruction.hh"
#include "Tajada/Code/MIPS/Instruction/Instruction.hh"

#include "Tajada/Code/MIPS/Address/Address.hh"
#include "Tajada/Code/MIPS/Address/Register.hh"

namespace Tajada {
        namespace Code {
                namespace MIPS {
                        namespace Instruction {
                                sw::sw(
                                        Tajada::Code::MIPS::Address::Register * p_src,
                                        Tajada::Code::MIPS::Address::Address  * p_dst
                                ):
                                        Tajada::Code::Instruction(),
                                        Tajada::Code::MIPS::Instruction::Instruction(),

                                        src(p_src),
                                        dst(p_dst)
                                {}



                                std::string sw::show() {
                                        auto rdst = dynamic_cast<Tajada::Code::MIPS::Address::Register *>(this->dst);
                                        return
                                                "sw "
                                                + this->src->show()
                                                + ", "
                                                + (
                                                        (rdst && rdst->offset) || !rdst
                                                        ? this->dst->show()
                                                        : "(" + this->dst->show() + ")"
                                                )
                                        ;
                                }
                        }
                }
        }
}
