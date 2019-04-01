//===----------------------------------------------------------------------===//
//                         DuckDB
//
// planner/expression/bound_columnref_expression.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "common/types/hash.hpp"
#include "planner/expression.hpp"

namespace duckdb {

struct ColumnBinding {
	uint32_t table_index;
	uint32_t column_index;

	ColumnBinding() : table_index((uint32_t)-1), column_index((uint32_t)-1) {
	}
	ColumnBinding(uint32_t table, uint32_t column) : table_index(table), column_index(column) {
	}

	bool operator==(const ColumnBinding &rhs) const {
		return table_index == rhs.table_index && column_index == rhs.column_index;
	}
};

struct ColumnBindingHashFunction {
	size_t operator()(const ColumnBinding &a) const {
		return CombineHash(Hash<uint32_t>(a.table_index), Hash<uint32_t>(a.column_index));
	}
};

struct ColumnBindingEquality {
	bool operator()(const ColumnBinding &a, const ColumnBinding &b) const {
		return a == b;
	}
};

template <typename T>
using column_binding_map_t = unordered_map<ColumnBinding, T, ColumnBindingHashFunction, ColumnBindingEquality>;

//! A BoundColumnRef expression represents a ColumnRef expression that was bound to an actual table and column index. It
//! is not yet executable, however. The ColumnBindingResolver transforms the BoundColumnRefExpressions into
//! BoundExpressions, which refer to indexes into the physical chunks that pass through the executor.
class BoundColumnRefExpression : public Expression {
public:
	BoundColumnRefExpression(TypeId type, ColumnBinding binding, uint32_t depth = 0);
	BoundColumnRefExpression(string alias, TypeId type, ColumnBinding binding,
	                         uint32_t depth = 0);

	//! Column index set by the binder, used to generate the final BoundExpression
	ColumnBinding binding;
	//! The subquery depth (i.e. depth 0 = current query, depth 1 = parent query, depth 2 = parent of parent, etc...).
	//! This is only non-zero for correlated expressions inside subqueries.
	uint32_t depth;

public:
	bool IsScalar() const override {
		return false;
	}

	string ToString() const override;

	bool Equals(const BaseExpression *other) const override;
	uint64_t Hash() const override;

	unique_ptr<Expression> Copy() override;
};
} // namespace duckdb
