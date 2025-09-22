#ifndef CONFIGWORKER_H
#define CONFIGWORKER_H

#include <QString>

enum APIConfigResultCode
{
    SUCCESS,
    FILE_NOTE_FOUND,
    FILE_PARSE_ERROR,
    EMPTY_VALUES
};

struct APIConfig
{
    APIConfigResultCode result_code;
    QString godname;
    QString token;
};

class ConfigWorker
{
public:
    ConfigWorker();
    APIConfig getConfig();
private:
    void createConfigTemplate();
};

#endif // CONFIGWORKER_H
