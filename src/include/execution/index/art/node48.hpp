//===----------------------------------------------------------------------===//
//                         DuckDB
//
// execution/index/art/node48.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once
#include "node.hpp"

namespace duckdb {

class Node48 : public Node {
public:
	uint8_t childIndex[256];
    unique_ptr<Node> child[48];

	Node48(uint8_t maxPrefixLength) : Node(NodeType::N48, maxPrefixLength) {
		memset(childIndex, 48, sizeof(childIndex));
		memset(child, 0, sizeof(child));
	}

	//! Get Node48 Child
	unique_ptr<Node>* getChild(const uint8_t k);

	//! Insert node in Node48
	static void insert(unique_ptr<Node>& node, uint8_t keyByte, unique_ptr<Node>&child);

	//! Delete node From Node48
	static void erase(Node48 *node, Node **nodeRef, uint8_t keyByte);
};
} // namespace duckdb
