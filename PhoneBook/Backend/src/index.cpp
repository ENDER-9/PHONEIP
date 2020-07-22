#include "client.h"
#include "person.h"
#include <napi.h>
#include <string>

Client client (3000);

Napi::String sendAddPersonServerJs (const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env ();

    std::string firstName = (std::string)info[0].ToString ();
    std::string lastName = (std::string)info[1].ToString ();
    std::string birthday = (std::string)info[2].ToString ();
    std::string phoneNumber = (std::string)info[3].ToString ();
    std::string street = (std::string)info[4].ToString ();
    std::string city = (std::string)info[5].ToString ();
    std::string postcode = (std::string)info[6].ToString ();
    int postcodeInt = stoi (postcode);
    Person person (firstName, lastName, birthday, phoneNumber, street, city, postcodeInt);
    std::string result = client.sendAddPersonServer (person);

    return Napi::String::New (env, result);
}

Napi::Object Init (Napi::Env env, Napi::Object exports) {
    exports.Set (Napi::String::New (env, "sendAddPersonServerJs"), Napi::Function::New (env, sendAddPersonServerJs));

    return exports;
}

NODE_API_MODULE (clientModule, Init)