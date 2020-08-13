#include "client.h"
#include "person.h"
#include <iostream>
#include <napi.h>
#include <string>

Client client (4000);
// Wrapping my C++ Methods to Js
Napi::String sendAddPersonServerJs (const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env ();
    // fetching the given variables from Js
    std::string firstName = (std::string)info[0].ToString ();
    std::string lastName = (std::string)info[1].ToString ();
    std::string birthday = (std::string)info[2].ToString ();
    std::string phoneNumber = (std::string)info[3].ToString ();
    std::string landlineNumber = (std::string)info[4].ToString ();
    std::string street = (std::string)info[5].ToString ();
    std::string city = (std::string)info[6].ToString ();
    int postcodeInt = (int)info[7].ToNumber ();
    // calling the C++ method
    Person person (firstName, lastName, birthday, phoneNumber, landlineNumber, street, city, postcodeInt);
    std::string result = client.sendAddPersonServer (person);

    return Napi::String::New (env, result);
}


Napi::String sendDeletePersonServerJs (const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env ();

    std::string firstName = (std::string)info[0].ToString ();
    std::string lastName = (std::string)info[1].ToString ();

    std::string result = client.sendDeletePersonServer (firstName, lastName);
    return Napi::String::New (env, result);
}

Napi::String sendModifyPersonServerJs (const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env ();
    // fetching the given variables from Js
    std::string firstName = (std::string)info[0].ToString ();
    std::string lastName = (std::string)info[1].ToString ();
    std::string birthday = (std::string)info[2].ToString ();
    std::string phoneNumber = (std::string)info[3].ToString ();
    std::string landlineNumber = (std::string)info[4].ToString ();
    std::string street = (std::string)info[5].ToString ();
    std::string city = (std::string)info[6].ToString ();
    int postcodeInt = (int)info[7].ToNumber ();
    // calling the C++ method
    Person person (firstName, lastName, birthday, phoneNumber, landlineNumber, street, city, postcodeInt);
    std::string result = client.sendModifyPersonServer (person);

    return Napi::String::New (env, result);
}

Napi::Object sendGetPersonInformationServerJs (const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env ();

    std::string firstName = (std::string)info[0].ToString ();
    std::string lastName = (std::string)info[1].ToString ();

    Person person = client.sendGetPersonInformationServer (firstName, lastName);
    Napi::Object result = Napi::Object::New (env);
    result.Set ("FirstName", Napi::String::New (env, person.getFirstName ()));
    result.Set ("LastName", Napi::String::New (env, person.getLastName ()));
    result.Set ("Birthday", Napi::String::New (env, person.getBirthday ()));
    result.Set ("PhoneNumber", Napi::String::New (env, person.getPhoneNumber ()));
    result.Set ("LandlineNumber", Napi::String::New (env, person.getLandlineNumber ()));
    result.Set ("Street", Napi::String::New (env, person.getStreet ()));
    result.Set ("City", Napi::String::New (env, person.getCity ()));
    result.Set ("Postcode", Napi::Number::New (env, person.getPostcode ()));

    return Napi::Object (env, result);
}

Napi::Object Init (Napi::Env env, Napi::Object exports) {
    exports.Set (Napi::String::New (env, "sendAddPersonServerJs"), Napi::Function::New (env, sendAddPersonServerJs));
    exports.Set (Napi::String::New (env, "sendDeletePersonServerJs"), Napi::Function::New (env, sendDeletePersonServerJs));
    exports.Set (Napi::String::New (env, "sendModifyPersonServerJs"), Napi::Function::New (env, sendModifyPersonServerJs));
    exports.Set (Napi::String::New (env, "sendGetPersonInformationServerJs"), Napi::Function::New (env, sendGetPersonInformationServerJs));

    return exports;
}

NODE_API_MODULE (clientModule, Init)