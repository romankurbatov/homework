#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "matrix.h"

class MatrixTest : public QObject
{
    Q_OBJECT
public:
    explicit MatrixTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void test_data()
    {
        QTest::addColumn<int>("numberOfRows");
        QTest::addColumn<int>("numberOfColumns");

        QTest::newRow("Matrix 1x1") << 1 << 1;
        QTest::newRow("Matrix 2x3") << 2 << 3;
        QTest::newRow("Matrix 3x2") << 3 << 2;
        QTest::newRow("Matrix 5x4") << 5 << 4;
        QTest::newRow("Matrix 6x7") << 6 << 7;
    }

    void test()
    {
        QFETCH(int, numberOfRows);
        QFETCH(int, numberOfColumns);

        Matrix matrix(numberOfRows, numberOfColumns);
        matrix.fillRandom();
        matrix.sortColumns();

        QVERIFY(matrix.getNumberOfRows() == numberOfRows);
        QVERIFY(matrix.getNumberOfColumns() == numberOfColumns);
        for (int column = 0; column < numberOfColumns - 1; ++column)
            QVERIFY(matrix.getElement(0, column) <= matrix.getElement(0, column + 1));
    }
};
