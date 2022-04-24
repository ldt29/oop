#pragma once

#include "operation.h"
class Add:public OperationNodeTwo{

public:
    Add(string name, Node *x1, Node *x2):OperationNodeTwo(name,x1,x2){};
    void UpdateValue();
};