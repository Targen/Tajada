#ifndef TAJADA_AST_RETURN_HH
#define TAJADA_AST_RETURN_HH

#include <string>

// Superclasses:
#include "Tajada/AST/Statement.hh"

#include "Tajada/AST/Expression.hh"

namespace Tajada {
        namespace AST {
                class Return : public virtual Tajada::AST::Statement {
                        public:
                                Tajada::AST::Expression * expression;

                                Return(
                                        Tajada::AST::Expression * expression
                                );

                                virtual std::string show(unsigned int depth = 0);
                };
        }
}

#endif
