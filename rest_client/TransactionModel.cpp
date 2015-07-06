#include "TransactionModel.hpp"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QByteArray>

#include "model/entity/TransactionDto.hpp"

QString TransactionModel::s_resourceName = "http://localhost:51116/taction";

TransactionModel::TransactionModel(QObject *parent) : QObject(parent)
{
    m_PerformManager = new QNetworkAccessManager(this);
    m_getListManager = new QNetworkAccessManager(this);

    connect(m_PerformManager, &QNetworkAccessManager::finished, this, &TransactionModel::parseTransactionPerform);
    connect(m_getListManager, &QNetworkAccessManager::finished, this, &TransactionModel::parseTransactionListResponse);
    connect(this, &TransactionModel::refreshTransactionList, this, &TransactionModel::getAllOrderedByAmount);
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
    QUrl url(s_resourceName);
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    m_PerformManager->put(request, QJsonDocument(aTransaction->toJsonObject()).toJson());
}

void TransactionModel::getAllFilteredByIban(const QString &iban)
{
    QUrl url(s_resourceName + "/" + iban);
    QNetworkRequest request;
    request.setUrl(url);
    m_getListManager->get(request);
}

void TransactionModel::getAllOrderedByAmount()
{
    QUrl url(s_resourceName);
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    m_getListManager->get(request);
    qDebug () << "get all trx";
}

void TransactionModel::parseTransactionPerform(QNetworkReply *reply)
{
    qDebug () << "perform response:" << reply->readAll();
    emit refreshTransactionList();
}

void TransactionModel::parseTransactionListResponse(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    qDebug () << "getListResponse:" << data;
    TransactionList result;
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    qDebug () << error.errorString();
    for (const auto & transacitionJson : doc.array())
    {
        TransactionDto * transaction = new TransactionDto(this);
        transaction->fromJsonObject(transacitionJson.toObject());
        result << transaction;
    }
    qDebug () << result;
    setTransactions(QVariant::fromValue(result));
}
