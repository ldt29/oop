#include "node.h"

Node::~Node(){};

void PlaceholderNode::set_val(float val)
{
    this->value_=val;
}

void PlaceholderNode::calc(){
    return;
}

