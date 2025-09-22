/*
 * This file is part of Your Project Name.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
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
