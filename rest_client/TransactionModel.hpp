#ifndef TRANSACTIONMODEL_HPP
#define TRANSACTIONMODEL_HPP

#include <QObject>
#include <QString>
#include <QList>
#include <QVariant>

class QNetworkAccessManager;
class QNetworkReply;
class TransactionDto;

using TransactionList = QList<QObject*>;

class TransactionModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant transactions READ transactions WRITE setTransactions NOTIFY transactionsChanged)
public:
    explicit TransactionModel(QObject *parent = 0);
    ~TransactionModel ();
    QVariant transactions() const;
    void setTransactions(const QVariant &transactions);

private:
    QVariant m_transactions;
    QNetworkAccessManager * m_PerformManager;
    QNetworkAccessManager * m_getListManager;
    static QString s_resourceName;
signals:
    void transactionsChanged ();
    void refreshTransactionList ();
public slots:
    void performTransaction (TransactionDto * aTransaction);
    void getAllOrderedByAmount ();
    void getAllFilteredByIban (const QString & iban);
private slots:
    void parseTransactionPerform (QNetworkReply * reply);
    void parseTransactionListResponse (QNetworkReply * reply);
};

#endif // TRANSACTIONMODEL_HPP
