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
#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Autogodvill_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // QTranslator qtTranslator;
    // QString qtTranslationsPath = QLibraryInfo::path(QLibraryInfo::TranslationsPath);
    // qtTranslator.load("qt_" + QLocale::system().name(), qtTranslationsPath);
    // app.installTranslator(&qtTranslator);
    // if (translator.load(QLocale::system(), "your_project", "_", ":/translations"))
    // {
    //     a.installTranslator(&translator);
    // }

    qDebug() << "main: Creating widget...";
    Widget w;
    qDebug() << "main: Widget created";
    w.show();
    return a.exec();
}
