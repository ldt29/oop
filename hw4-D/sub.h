#pragma once

#include "operation.h"
class Sub:public OperationNodeTwo{

public:
    Sub(string name, Node *x1, Node *x2):OperationNodeTwo(name,x1,x2){};
    void UpdateValue();
};