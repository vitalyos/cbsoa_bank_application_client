#ifndef TRANSACTIONCONTROLLER_HPP
#define TRANSACTIONCONTROLLER_HPP

#include <QObject>

class TransactionController : public QObject
{
    Q_OBJECT
public:
    explicit TransactionController(QObject *parent = 0);

signals:

public slots:
};

#endif // TRANSACTIONCONTROLLER_HPP
