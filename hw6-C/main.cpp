#include <iostream>
#include <regex>
#include <string>

using namespace std;

void check(string user) {
    regex get_username(R"("username" *: *"([a-zA-Z]\w{3,14})["])");
    string username;
    regex get_password(R"("password" *: *"([a-zA-Z0-9]{8,20})["])");
    regex get_password1(R"("password" *: *"([0-9]{8,20})["])");
    regex get_password2(R"("password" *: *"([a-zA-Z]{8,20})["])");
    string password;
    regex get_email(R"("email" *: *"(\w+@[\w.]+)["])");
    string email;
    smatch sm[3];
    int wrongnum = 3;
    bool match[3] = {false};
    if (regex_search(user, sm[0], get_username)) {
        match[0] = true;
        username = sm[0][1];
        wrongnum--;
    }

    if (regex_search(user, sm[1], get_password)&& !regex_search(user, get_password1)&&!regex_search(user, get_password2)) {
        match[1] = true;
        password = sm[1][1];
        wrongnum--;
    }
    if (regex_search(user, sm[2], get_email)) {
        match[2] = true;
        email = sm[2][1];
        wrongnum--;
    }

    if (!wrongnum) {
        regex replace_email(R"([^@.])");
        regex replace_password(R"(.)");
        string username_ = username.substr(3);
        cout<< "Successfully registered." << endl;
        
        cout << "username: " << username.substr(0, 3) << regex_replace(username_, replace_email, "*") << endl;
        cout << "password: "<< regex_replace(password,replace_password,"*") << endl;
        cout << "email: " << regex_replace(email, replace_email, "*")<< endl;
    }
    else {
        cout << "Illegal ";
     
        if (!match[0]) {
            cout << "username";
                wrongnum--;
            if (wrongnum)
                cout << ",";
        }

        if (!match[1]) {
            cout << "password";
            wrongnum--;
            if (wrongnum)
                cout << ",";
        }

        if (!match[2]) {
            cout << "email";
        }
    }

}

int main() {
    string user;
    getline(cin, user);
    check(user);

    return 0;
}
