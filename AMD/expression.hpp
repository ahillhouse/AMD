/// @file expression.hpp
/// Contains AMD::Parser

#ifndef AMD_EXPRESSION_HPP
#define AMD_EXPRESSION_HPP

#define BOOST_SPIRIT_DEBUG

#include <string>
#include <stdexcept>

#include <boost/spirit/include/support_utree.hpp>
#include <boost/spirit/include/qi.hpp>

#include <AMD/matrixgrammar.hpp>

namespace AMD {


// Define the expression type to be utree for now.
// FIXME: This has to change to an actual tree with nodes
typedef boost::spirit::utree Expression;
///< typedef for the expression tree that is parsed by Parser


Expression generateExpression(const std::string& exprString);
///< The main method of the file that takes in a string and tries to parse it.
/// CHETAN TODO. ADD MORE DOCUMENTATION.

} // namespace AMD

#endif // AMD_EXPRESSION_HPP