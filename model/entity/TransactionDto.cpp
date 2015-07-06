#include "TransactionDto.hpp"

QString TransactionDto::s_idField = "Id";
QString TransactionDto::s_dateTimeField = "DateTime";
QString TransactionDto::s_locationField = "InitFromLocation";
QString TransactionDto::s_amountField = "Amount";
QString TransactionDto::s_sourceAccountField = "Account";
QString TransactionDto::s_currencyValueField = "CurrencyValue";
QString TransactionDto::s_destAccountField = "DestAccount";
QString TransactionDto::s_destExternalAccountField = "DestExternalAccount";
QString TransactionDto::s_errorField = "Error";

TransactionDto::TransactionDto(QObject *parent) : QObject(parent)
{

}
int TransactionDto::id() const
{
    return m_id;
}

void TransactionDto::setId(int id)
{
    m_id = id;
    emit idChanged();
}

QString TransactionDto::dateTime() const
{
    return m_dateTime;
}

void TransactionDto::setDateTime(const QString &dateTime)
{
    m_dateTime = dateTime;
    emit dateTimeChanged();
}

QString TransactionDto::location() const
{
    return m_location;
}

void TransactionDto::setLocation(const QString &location)
{
    m_location = location;
    emit locationChanged();
}

qint32 TransactionDto::amount() const
{
    return m_amount;
}

void TransactionDto::setAmount(const qint32 &amount)
{
    m_amount = amount;
    emit amountChanged();
}

QString TransactionDto::sourceAccount() const
{
    return m_sourceAccount;
}

void TransactionDto::setSourceAccount(const QString &sourceAccount)
{
    m_sourceAccount = sourceAccount;
    emit sourceAccountChanged();
}

quint32 TransactionDto::currencyValue() const
{
    return m_currencyValue;
}

void TransactionDto::setCurrencyValue(const quint32 &currencyValue)
{
    m_currencyValue = currencyValue;
    emit currencyValueChanged();
}
QString TransactionDto::destAccount() const
{
    return m_destAccount;
}

void TransactionDto::setDestAccount(const QString &destAccount)
{
    m_destAccount = destAccount;
    emit destAccountChanged();
}

QString TransactionDto::error() const
{
    return m_error;
}

void TransactionDto::setError(const QString &error)
{
    m_error = error;
    emit errorChanged();
}

void TransactionDto::fromJsonObject(const QJsonObject &source)
{
    m_id = source[s_idField].toInt();
    m_dateTime = source[s_dateTimeField].toString();
    m_location = source[s_locationField].toString();
    m_amount = source[s_amountField].toInt();
    m_sourceAccount = source[s_sourceAccountField].toString();
    m_currencyValue = source[s_currencyValueField].toInt();
    m_destAccount = source[s_destAccountField].toString();
    m_destExternalAccount = source[s_destExternalAccountField].toString();
    m_error = source[s_errorField].toString();
}

QJsonObject TransactionDto::toJsonObject() const
{
    QJsonObject destination;
    destination.insert(s_idField, m_id);
    destination.insert(s_dateTimeField, m_dateTime);
    destination.insert(s_locationField, m_location);
    destination.insert(s_amountField, m_amount);
    destination.insert(s_sourceAccountField, m_sourceAccount);
    destination.insert(s_currencyValueField, m_currencyValue);
    destination.insert(s_destAccountField, m_destAccount);
    destination.insert(s_destExternalAccountField, m_destExternalAccount);
    destination.insert(s_errorField, m_error);
    return destination;
}
QString TransactionDto::destExternalAccount() const
{
    return m_destExternalAccount;
}

void TransactionDto::setDestExternalAccount(const QString &destExternalAccount)
{
    m_destExternalAccount = destExternalAccount;
    emit destExternalAccountChanged();
}
