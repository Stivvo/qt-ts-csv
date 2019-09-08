#pragma once

#include <QObject>

class Converter : public QObject
{
    Q_OBJECT

  public:
    Q_INVOKABLE QString convert() const;

    Q_INVOKABLE QString setSource(const QString &source);
    Q_INVOKABLE QString setDest(const QString &dest);

    void setSource(const std::string &source);
    void setDest(const std::string &dest);

  private:
    std::string source = "";
    std::string dest   = "";
    QString setPath(const QString &path, std::string &thispath);
};
