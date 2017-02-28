#pragma once

#include "entityx/Entity.h"

enum class NodeType
{
	WT_Small,
};

struct Node : public entityx::Component<Node>
{
	Node(NodeType type = NodeType::WT_Small);

	NodeType m_type;
};

