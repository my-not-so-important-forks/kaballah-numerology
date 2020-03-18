#include "numerologycore.h"
#include <QDebug>

QMap<QString, quint8> createNumberCodeHash()
{
    QMap<QString, quint8> map;
    map.insert("a", 1);
    map.insert("i", 1);
    map.insert("q", 1);
    map.insert("j", 1);
    map.insert("y", 1);

    map.insert("b", 2);
    map.insert("k", 2);
    map.insert("r", 2);

    map.insert("c", 3);
    map.insert("g", 3);
    map.insert("l", 3);
    map.insert("s", 3);

    map.insert("d", 4);
    map.insert("m", 4);
    map.insert("t", 4);

    map.insert("e", 5);
    map.insert("h", 5);
    map.insert("n", 5);

    map.insert("u", 6);
    map.insert("v", 6);
    map.insert("w", 6);
    map.insert("x", 6);
    map.insert("ç", 6);

    map.insert("o", 7);
    map.insert("z", 7);

    map.insert("f", 8);
    map.insert("p", 8);

    map.insert("ã", 1+3);
    map.insert("ẽ", 5+3);
    map.insert("ĩ", 1+3);
    map.insert("õ", 7+3);
    map.insert("ũ", 6+3);
    map.insert("ñ", 5+3);

    map.insert("á", 1+2);
    map.insert("é", 5+2);
    map.insert("í", 1+2);
    map.insert("ó", 7+2);
    map.insert("ú", 6+2);

    map.insert("â", 1+7);
    map.insert("ê", 5+7);
    map.insert("î", 1+7);
    map.insert("ô", 7+7);
    map.insert("û", 6+7);

    map.insert("à", 1*2);
    map.insert("è", 5*2);
    map.insert("ì", 1*2);
    map.insert("ò", 7*2);
    map.insert("ù", 6*2);

    map.insert("ä", 1*2);
    map.insert("ë", 5*2);
    map.insert("ï", 1*2);
    map.insert("ö", 7*2);
    map.insert("ü", 6*2);

    // símbolo cabalístico (bolinha em cima)
    map.insert("å", 1+7);
    map.insert("ů", 6+7);

    return map;
}

QString filterVowels(const QString &input)
{
    QString lowerInput = input.toLower();
    QString result;
    for (QChar c: lowerInput) {
        if (QString("aeiou"
                    "áéíóú"
                    "äëïöü"
                    "âêîôû"
                    "ãẽĩõũ"
                    "àèìòù"
                    "åů").contains(c)) {
            result.append(c);
        }
    }
    return result;
}

QString filterConsonants(const QString &input)
{
    QString lowerInput = input.toLower();
    QString result;
    for (QChar c: lowerInput) {
        if (QString("bcdfghjklmnpqrstvwxyzçñ").contains(c)) {
            result.append(c);
        }
    }
    return result;
}

quint32 doSumOfLetters(const QString &input)
{
    static QMap<QString, quint8> map = createNumberCodeHash();
    qDebug() << "map size = " << map.size();

    quint32 accum = 0;
    QString lowerInput = input.toLower();

    for (QChar c: lowerInput) {
        qDebug() << "map[" << c << "] = " << map.value(c);
        if (map.contains(c)) {
            accum += map.value(c);
        } else {
            qDebug() << "letra faltando = " << c;
            //throw std::runtime_error("letra faltanto no mapa");
        }
    }
    return accum;
}

quint32 doReduction(const quint32 num)
{
    quint32 accum = num;
    //            numero de digitos        > 1
    while (QString("%1").arg(accum).size() > 1) {
        QString textNum = QString("%1").arg(accum); // transforma o numero em texto
        accum = 0;
        for (QChar digit: textNum) {
            accum += QString(digit).toInt();
        }
    }

    return accum;
}
