#include "parser/expression/parameter_expression.hpp"
#include "planner/expression/bound_parameter_expression.hpp"
#include "planner/expression_binder.hpp"
#include "planner/binder.hpp"

using namespace duckdb;
using namespace std;

BindResult ExpressionBinder::BindExpression(ParameterExpression &expr, uint32_t depth) {
	if (!binder.parameters) {
		throw BinderException("Parameter expressions are only allowed in PREPARE statements!");
	}
	auto bound_parameter = make_unique<BoundParameterExpression>(expr.parameter_nr);
	binder.parameters->push_back(bound_parameter.get());
	return BindResult(move(bound_parameter), bound_parameter->sql_type);
}
