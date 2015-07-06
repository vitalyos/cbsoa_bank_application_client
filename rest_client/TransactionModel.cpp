#include "TransactionModel.hpp"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

QString TransactionModel::s_resourceName = "http://localhost:51116/bank/api/transactions";

TransactionModel::TransactionModel(QObject *parent) : QObject(parent)
{
    m_PerformManager = new QNetworkAccessManager(this);
    m_getListManager = new QNetworkAccessManager(this);

    connect(m_PerformManager, &QNetworkAccessManager::finished,
            this, &TransactionModel::parseTransactionPerform);
    connect(m_getListManager, &QNetworkAccessManager::finished,
            this, &TransactionModel::parseTransactionListResponse);
    connect(this, &TransactionModel::refreshTransactionList,
            this, &TransactionModel::getAllOrderedByAmount);
}

TransactionModel::~TransactionModel()
{
    delete m_PerformManager;
    delete m_getListManager;
}

QVariant TransactionModel::transactions() const
{
    return m_transactions;
}

void TransactionModel::setTransactions(const QVariant &transactions)
{
    m_transactions = transactions;
    emit transactionsChanged();
}

void TransactionModel::performTransaction(TransactionDto *aTransaction)
{

}

void TransactionModel::getAllFilteredByIban(const QString &iban)
{

}

void TransactionModel::getAllOrderedByAmount()
{

}

void TransactionModel::parseTransactionPerform(QNetworkReply *reply)
{

}

void TransactionModel::parseTransactionListResponse(QNetworkReply *reply)
{

}
