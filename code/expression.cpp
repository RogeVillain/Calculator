#include "expression.h"



Expression::Expression(std::string const& val)
{
    buildConstant(val);
    genre = expression;
}


std::string Expression::getChain() const
{
    return expr;
}

void Expression::buildConstant(const std::string& val)
{
    expr = val;
}
