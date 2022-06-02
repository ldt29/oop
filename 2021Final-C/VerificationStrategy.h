#pragma once
# include <string>

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
};

class PrefixStrategy:public VerificationStrategy{
public:
	std::string verify(std::string mes){
		std::string ans;
		ans+=mes[0];
		ans+=mes[1];
		ans+=mes[2];
		return ans;
	}
};
class IntervalStrategy:public VerificationStrategy{
public:
	std::string verify(std::string mes){
		std::string ans;
		for(int i=0;i<mes.size();i++){
			if(i%2==0)
				ans+=mes[i];
		}
		return ans;	
	}
};
