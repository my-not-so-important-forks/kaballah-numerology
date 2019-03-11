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
                    "àèìòù").contains(c)) {
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
        if (QString("bcdfghjklmnpqrstvwxyzç").contains(c)) {
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

quint32 doReduction(quint32 num)
{
    quint32 result = 0;
    QString textNum("%1");
    /*
    do {

    } while ();
    //*/

    // transforma o numero em texto
    // enquanto o numero de digitos for maior que 1 {
    //     para cada digito do texto {
    //         acumulador += valor do digito
    //     }
    // }
    return result;
}
