#pragma once
#include <string>
#include "OccupationStrategy.h"
#include "PayStrategy.h"

class Calculator {
public:				
    OccupationStrategy* occupationStrategy;
    PayStrategy* payStrategy;
    Calculator(OccupationStrategy* m_occupationStrategy, PayStrategy* m_payStrategy){
        occupationStrategy=m_occupationStrategy;
        payStrategy=m_payStrategy;
    }
    double getSalary(double base, double bonus, double level){
		return occupationStrategy->getSalary(base, bonus, level);
	}
    double pay(std::string name, double money){
        return payStrategy->pay(name,money);
    }
};