// Class:
#include "Tajada/Code/Intermediate/Instruction/Print.hh"

// Superclasses:
#include "Tajada/Code/Instruction.hh"
#include "Tajada/Code/Intermediate/Instruction/Instruction.hh"

#include "Tajada/Code/Intermediate/Address/Address.hh"
#include "Tajada/Code/MIPS/Address/Immediate/Integer.hh"
#include "Tajada/Code/MIPS/Address/Register.hh"
#include "Tajada/Code/MIPS/Instruction/Comment.hh"
#include "Tajada/Code/MIPS/Instruction/li.hh"
#include "Tajada/Code/MIPS/Instruction/syscall.hh"

namespace Tajada {
        namespace Code {
                namespace Intermediate {
                        namespace Instruction {
                                Print::Print(
                                        Tajada::Code::Intermediate::Address::Address * p_src
                                ):
                                        Tajada::Code::Instruction(),
                                        Tajada::Code::Intermediate::Instruction::Instruction(),

                                        src(p_src)
                                {}



                                std::string Print::show() {
                                        return
                                                u8"print "
                                                + this->src->show()
                                        ;
                                }



                                std::vector<Tajada::Code::MIPS::Instruction::Instruction *> Print::to_mips() {
                                        auto msrc = this->src->to_mips();

                                        return
                                                { new Tajada::Code::MIPS::Instruction::Comment(this->show())

                                                , TAJADA_LOAD_TO_REGISTER_MIPS(msrc, a0, Integer)

                                                , new Tajada::Code::MIPS::Instruction::li(
                                                        new Tajada::Code::MIPS::Address::Immediate::Integer(1),
                                                        new Tajada::Code::MIPS::Address::Register(Tajada::Code::MIPS::Address::Register::R::v0)
                                                )

                                                , new Tajada::Code::MIPS::Instruction::syscall()

                                                }
                                        ;
                                }
                        }
                }
        }
}
