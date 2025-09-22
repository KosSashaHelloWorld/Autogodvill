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
#include "configworker.h"
#include <QFile>
#include <QDebug>

ConfigWorker::ConfigWorker() {
    qDebug() << "ConfigWorker created";
}



namespace ConfigWorkerVars
{
    const QString godnameTemplateStr = "<your-god's-name>";
    const QString tokenTemplateStr = "<your-profile-token>";
    const QString filename = "./config.txt";
}

void ConfigWorker::createConfigTemplate()
{
    qDebug() << "ConfigWorker: Creating config template...";
    QString configTemplateStr;
    configTemplateStr = QString(
            "godname:%1\ntoken:%2")
            .arg(ConfigWorkerVars::godnameTemplateStr)
            .arg(ConfigWorkerVars::tokenTemplateStr);
    QFile f = QFile(ConfigWorkerVars::filename);
    if (f.open(QFile::OpenModeFlag::NewOnly & QFile::OpenModeFlag::WriteOnly))
    {
        f.write(configTemplateStr.toStdString().c_str());
        f.close();
    }
    else
    {
        qDebug() << "ConfigWorker: FAILED to open file (write)";
    }
}

APIConfig ConfigWorker::getConfig()
{
    qDebug() << "ConfigWorker: Trying to get APIConfig from file...";
    APIConfig conf;
    QString content;

    QFile f = QFile(ConfigWorkerVars::filename);
    if (f.exists())
    {
        qDebug() << "ConfigWorker: File exists";
        if (f.open(QFile::OpenModeFlag::ReadOnly))
        {
            content = f.readAll();
            f.close();
            qDebug() << "ConfigWorker: File opened: \n" << content;

            conf.godname = content.split('\n')[0].split(':')[1];
            conf.token = content.split('\n')[1].split(':')[1];

            qDebug() << "ConfigWorker: Config wroted: Godname=" << conf.godname << ", Token=" << conf.token;

            if (conf.godname == ConfigWorkerVars::godnameTemplateStr | conf.token == ConfigWorkerVars::tokenTemplateStr |
                conf.godname == "" | conf.token == "")
            {
                qDebug() << "ConfigWorker: FAILED: Config file is empty";
                conf.result_code = APIConfigResultCode::EMPTY_VALUES;
            }
            else
            {
                qDebug() << "ConfigWorker: SUCCESS: Config readed";
                conf.result_code = APIConfigResultCode::SUCCESS;
            }

        }
    }
    else
    {
        qDebug() << "ConfigWorker: FAILED: Config file does not exist";
        createConfigTemplate();
        conf.result_code = APIConfigResultCode::FILE_NOTE_FOUND;
    }

    return conf;
}
