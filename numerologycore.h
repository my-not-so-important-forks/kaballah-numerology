#ifndef NUMEROLOGYCORE_H
#define NUMEROLOGYCORE_H

#include <QString>
#include <QMap>

QMap<QString, quint8> createNumberCodeHash();

QString filterVowels(const QString &input);

QString filterConsonants(const QString &input);

quint32 doSumOfLetters(const QString &input);

quint32 doReduction(const quint32 num);

#endif // NUMEROLOGYCORE_H
