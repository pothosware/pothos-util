// Copyright (c) 2014-2014 Josh Blum
// SPDX-License-Identifier: BSL-1.0

#pragma once
#include <Pothos/Object.hpp>
#include <string>
#include <vector>
#include <memory>

/*!
 * The evaluation environment can evaluate and inspect expressions.
 * Expressions are considered to be valid C++ expressions involving
 * bools, integers, strings, floats, stl classes...
 */
class EvalEnvironment
{
public:
    static std::shared_ptr<EvalEnvironment> make(void)
    {
        return std::shared_ptr<EvalEnvironment>(new EvalEnvironment());
    }

    EvalEnvironment(void);

    /*!
     * Try to evaluate an expression in this environment.
     * \param expression a string expression
     * \throws Pothos::Exception with the evaluation error message
     * \return a proxy object representing the evaluated expression
     */
    Pothos::Object eval(const std::string &);

    /*!
     * Register a constant that will be used in other expressions.
     * For an expression like 2*x, then "x" would be a constant.
     */
    void registerConstant(const std::string &key, const std::string &expression)
    {
        throw Pothos::Exception("registerConstant not yet supported", key +":"+ expression);
    }

    //! Split an expression given the tokenizer -- deals with quotes, nesting, escapes
    static std::vector<std::string> splitExpr(const std::string &expr, const char tokenizer);

private:
    struct Impl; std::shared_ptr<Impl> _impl;
    Pothos::Object evalNoCache(const std::string &);
};
