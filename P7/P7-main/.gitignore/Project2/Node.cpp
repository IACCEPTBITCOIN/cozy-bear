#include "Node.h"

Node::Node() : data(), next(nullptr), prev(nullptr) {} 

Node::Node(const Store &d) : data(d), next(nullptr), prev(nullptr) {}