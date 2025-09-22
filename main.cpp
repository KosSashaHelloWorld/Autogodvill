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
