#pragma once
#include "User.h"
#include "EncryptStrategy.h"
#include "VerificationStrategy.h"

class UserProxy: public User{
public:
    RealUser* ruser;
    EncryptStrategy* encStr;
    VerificationStrategy* verStr;
    UserProxy(RealUser* _ruser, EncryptStrategy* _encStr, VerificationStrategy* _verStr){
        ruser=_ruser;
        encStr=_encStr;
        verStr=_verStr;
    }
    void sendMessage(std::string mes){
        ruser->sendMessage(encStr->encode(mes));
        
        std::cout<< verStr->verify(mes)<<std::endl;
    }
};