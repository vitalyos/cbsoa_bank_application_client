#ifndef TRANSACTIONMODEL_HPP
#define TRANSACTIONMODEL_HPP

#include <QObject>

class TransactionModel : public QObject
{
    Q_OBJECT
public:
    explicit TransactionModel(QObject *parent = 0);

signals:

public slots:
};

#endif // TRANSACTIONMODEL_HPP
