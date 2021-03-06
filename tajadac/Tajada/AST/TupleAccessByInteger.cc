#include <cassert>
#include <string>

// Class:
#include "Tajada/AST/TupleAccessByInteger.hh"

// Superclass:
#include "Tajada/AST/AST.hh"
#include "Tajada/AST/Expression.hh"

#include "Tajada/AST/Literal/Integer.hh"
#include "Tajada/Code/Intermediate/Address/Address.hh"
#include "Tajada/Code/Intermediate/Address/Immediate/Integer.hh"
#include "Tajada/Code/Intermediate/Address/Variable.hh"
#include "Tajada/Type/Tuple.hh"

namespace Tajada {
        namespace AST {
                TupleAccessByInteger::TupleAccessByInteger(
                        Tajada::AST::Expression       * p_source,
                        Tajada::AST::Literal::Integer * p_field
                ):
                        Tajada::AST::AST(),
                        Tajada::AST::Expression(
                                dynamic_cast<Tajada::Type::Tuple &>(*p_source->type)[p_field->value],
                                p_source->is_lvalue
                        ),

                        source(p_source),
                        field (p_field )
                {}

                std::string TupleAccessByInteger::show(unsigned int depth) {
                        return
                                source->show(depth)
                                + u8" → "
                                + field->show(depth)
                        ;
                }



                Tajada::Code::Intermediate::Address::Address * TupleAccessByInteger::genl(
                        Tajada::Code::Block * b
                ) {
                        auto sa = this->source->genl(b);
                        auto fa = this->field ->genr(b);
                        if (auto lvar = dynamic_cast<Tajada::Code::Intermediate::Address::Variable *>(sa)) {
                                auto tt = dynamic_cast<Tajada::Type::Tuple *>(this->source->type);
                                assert(tt);

                                auto ii = dynamic_cast<Tajada::Code::Intermediate::Address::Immediate::Integer *>(fa);
                                assert(ii);

                                lvar->offset += tt->offsets[ii->value];
                                return lvar;
                        } else {
                                assert(false); // TODO: For now, this shouldn’t happen.  Once references are implemented, it might.
                        }
                }



                Tajada::Code::Intermediate::Address::Address * TupleAccessByInteger::genr(
                        Tajada::Code::Block * b
                ) {
                        auto sa = this->source->genr(b);
                        auto fa = this->field ->genr(b);
                        if (auto lvar = dynamic_cast<Tajada::Code::Intermediate::Address::Variable *>(sa)) {
                                auto tt = dynamic_cast<Tajada::Type::Tuple *>(this->source->type);
                                assert(tt);

                                auto ii = dynamic_cast<Tajada::Code::Intermediate::Address::Immediate::Integer *>(fa);
                                assert(ii);

                                lvar->offset += tt->offsets[ii->value];
                                return lvar;
                        } else {
                                assert(false); // TODO: For now, this shouldn’t happen.  Once references are implemented, it might.
                        }
                }
        }
}
