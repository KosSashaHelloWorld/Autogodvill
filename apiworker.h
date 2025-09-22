#ifndef APIWORKER_H
#define APIWORKER_H

#include "apistructures.h"
#include "configworker.h"
#include <curl/curl.h>

class HttpClient
{
public:
    HttpClient();
    ~HttpClient();
    std::string get(const std::string& url);
private:
    CURL* curl;
};

class ApiWorker
{
public:
    ApiWorker();
    APIProfile getProfile();
    APIPublicProfile getPublicProfile();
private:
    ConfigWorker* cw;
    QString curlProfile();
    QString curlPublicProfile();
    HttpClient* http;
};

#endif // APIWORKER_H
