#pragma once
#include <string>

class PayStrategy {
public:								
	virtual double pay(std::string name, double money)=0;
};


class NormalStrategy : public PayStrategy {	
public:
	double pay(std::string name, double money){
		return money;
	}
};

class SwiftStrategy : public PayStrategy {	
public:
	double pay(std::string name, double money){
		if(money<=10000) return money-10;
		else if(money<=20000) return money-money/1000;
		else return money-20;
	}
};

class BitcoinStrategy : public PayStrategy {	
public:
	double pay(std::string name, double money){
		return money-(name.length()+8)*0.01;
	}
};
