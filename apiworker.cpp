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

#include "apiworker.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>

ApiWorker::ApiWorker()
{
    qDebug() << "Creating ApiWorker...";
    cw = new ConfigWorker();
    http = new HttpClient();
    qDebug() << "Creating ApiWorker - SUCCESS";
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t totalSize = size * nmemb;
    std::string* response = static_cast<std::string*>(userp);
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

HttpClient::HttpClient()
{
    qDebug() << "Creating HttpClient...";
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    qDebug() << "Creating HttpClient - SUCCESS";
}

HttpClient::~HttpClient()
{
    qDebug() << "Destroying HttpClient...";
    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    qDebug() << "Destroying HttpClient - SUCCESS";
}

std::string HttpClient::get(const std::string& url) {
    qDebug() << "HttpClient: Trying to get api responce from " << url;
    if (!curl) {
        qDebug() << "HttpClient: FAILED on initialize CURL";
        return "Error: Failed to initialize CURL";
    }

    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        qDebug() << "HttpClient: FAILED on performing";
        return "Error: " + std::string(curl_easy_strerror(res));
    }

    qDebug() << "HttpClient: SUCCESS";
    return response;
}

namespace APIWorkerVars
{
    const QString apiUrlPrefix = "https://godville.net/gods/api/";
}

QString ApiWorker::curlProfile()
{
    qDebug() << "ApiWorker: Trying to curl api...";
    APIConfig c = cw->getConfig();
    QString content;

    if (c.result_code == APIConfigResultCode::SUCCESS)
    {
        qDebug() << "ApiWorker: SUCCESS";
        QString url;
        url.append(APIWorkerVars::apiUrlPrefix)
            .append(c.godname)
            .append("/")
            .append(c.token);
        content = QString::fromStdString(http->get(url.toStdString()));
        return content;
    }
    else
    {
        qDebug() << "ApiWorker: FAILED to get content";
    }

    return "";
}

QString ApiWorker::curlPublicProfile()
{
    qDebug() << "ApiWorker: FATAL curlPublicProfile() NOT IMPLEMENTED";
    return "";
}

APIProfile ApiWorker::getProfile()
{
    qDebug() << "ApiWorker: Trying to get APIProfile...";
    APIProfile prof;

    QString resp = curlProfile();
    if (resp.isEmpty())
    {
        qDebug() << "ApiWorker: FAILED to get APIProfile";
        return prof;
    }
    else
    {
        qDebug() << "ApiWorker: SUCCESS";
    }

    qDebug() << "ApiWorker: Trying to parse content...";
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(resp.toUtf8(), &err);

    if (err.error != QJsonParseError::NoError)
    {
        qDebug() << "ApiWorker: FAILED to parse content";
        return prof;
    }
    else
    {
        qDebug() << "ApiWorker: SUCCESS";
    }

    if (doc.isEmpty())
    {
        qDebug() << "ApiWorker: FATAL: json document is empty";
        return prof;
    }

    qDebug() << "ApiWorker: Trying to get json object";
    QJsonObject obj = doc.object();
    if (obj.empty())
    {
        qDebug() << "ApiWorker: FAILED: json object is empty";
    }
    else
    {
        qDebug() << "ApiWorker: SUCCESS";
    }

    qDebug() << "ApiWorker: Trying to parse json object to APIProfile...";
    prof.name =                     obj["name"].toString();
    prof.godname =                  obj["godname"].toString();
    prof.gender =                   obj["gender"].toString();
    prof.level =                    obj["level"].toInt();
    prof.max_health =               obj["max_health"].toInt();
    prof.inventory_max_num =        obj["inventory_max_num"].toInt();
    prof.motto =                    obj["motto"].toString();
    prof.clan =                     obj["clan"].toString();
    prof.clan_position =            obj["clan_position"].toString();
    prof.alignment =                obj["alignment"].toString();
    prof.bricks_cnt =               obj["bricks_cnt"].toInt();
    prof.pet.pet_name =             obj["pet_name"].toString();
    prof.pet.pet_class =            obj["pet_class"].toString();
    prof.pet.pet_level =            obj["pet_level"].toInt();
    prof.ark_completed_at =         obj["ark_completed_at"].toString();
    prof.arena_won =                obj["arena_won"].toInt();
    prof.arena_lost =               obj["arena_lost"].toInt();
    prof.health =                   obj["health"].toInt();
    prof.quest_progress =           obj["quest_progress"].toInt();
    prof.exp_progress =             obj["exp_progress"].toInt();
    prof.godpower =                 obj["godpower"].toInt();
    prof.gold_approx =              obj["gold_approx"].toString();
    prof.diary_last =               obj["diary_last"].toString();
    prof.eye_last =                 obj["eye_last"].toString();
    prof.town_name =                obj["town_name"].toString();
    prof.distance =                 obj["distance"].toInt();
    prof.arena_fight =              obj["arena_fight"].toBool();
    prof.inventory_num =            obj["inventory_num"].toInt();
    prof.quest =                    obj["quest"].toString();
    //prof.activatables =             obj["activatables"].toArray();
    prof.pairs_at =                 obj["pairs_at"].toString();

    qDebug() << "ApiWorker: SUCCESS: APIProfile has been written";

    return prof;
}

APIPublicProfile ApiWorker::getPublicProfile()
{
    qDebug() << "ApiWorker: FATAL getPublicProfile() NOT IMPLEMENTED";
    APIPublicProfile prof;
    return prof;
}
