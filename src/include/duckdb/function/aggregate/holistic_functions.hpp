//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/function/aggregate/holistic_functions.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/function/aggregate_function.hpp"
#include "duckdb/function/function_set.hpp"

namespace duckdb {

struct QuantileFun {
	static void RegisterFunction(BuiltinFunctions &set);
};

struct ApproximateQuantileFun {
	static void RegisterFunction(BuiltinFunctions &set);
};

struct ReservoirQuantileFun {
	static void RegisterFunction(BuiltinFunctions &set);
};

} // namespace duckdb
