
#pragma once

#include "common/types/vector.hpp"

namespace duckdb {

class VectorOperations {
  public:
	//===--------------------------------------------------------------------===//
	// Numeric Operations
	//===--------------------------------------------------------------------===//
	// A + B
	static void Add(Vector &left, Vector &right, Vector &result);
	// A - B
	static void Subtract(Vector &left, Vector &right, Vector &result);
	// A * B
	static void Multiply(Vector &left, Vector &right, Vector &result);
	// A / B
	static void Divide(Vector &left, Vector &right, Vector &result);

	//===--------------------------------------------------------------------===//
	// Boolean Operations
	//===--------------------------------------------------------------------===//
	// A && B
	static void And(Vector &left, Vector &right, Vector &result);
	// A || B
	static void Or(Vector &left, Vector &right, Vector &result);

	//===--------------------------------------------------------------------===//
	// Comparison Operations
	//===--------------------------------------------------------------------===//
	// A == B
	static void Compare(Vector &left, Vector &right, Vector &result);
	// A > B
	static void GreaterThan(Vector &left, Vector &right, Vector &result);
	

	
	static void Copy(Vector& source, void* target);
};
}