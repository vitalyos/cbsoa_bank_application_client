#ifndef TRANSACTIONCONTROLLER_HPP
#define TRANSACTIONCONTROLLER_HPP

#include <QObject>
#include <QString>

#include "model/entity/TransactionDto.hpp"

class TransactionController : public QObject
{
    Q_OBJECT
public:
    explicit TransactionController(QObject *parent = 0);

signals:
    void requireGetAllOrderedByAmont ();
    void requireGetAllFilteredByIban (const QString & iban);
    void requirePerformTransaction (TransactionDto * aTransaction);
public slots:
    void getAllOrderedbyAmount ();
    void getAllFilteredByIban (const QString & iban);
    void performTransaction (TransactionDto * aTransaction);
};

#endif // TRANSACTIONCONTROLLER_HPP
