#include "TransactionDto.hpp"

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
}
QString TransactionDto::dateTime() const
{
    return m_dateTime;
}

void TransactionDto::setDateTime(const QString &dateTime)
{
    m_dateTime = dateTime;
}
QString TransactionDto::location() const
{
    return m_location;
}

void TransactionDto::setLocation(const QString &location)
{
    m_location = location;
}
qint32 TransactionDto::amount() const
{
    return m_amount;
}

void TransactionDto::setAmount(const qint32 &amount)
{
    m_amount = amount;
}
QString TransactionDto::sourceAccount() const
{
    return m_sourceAccount;
}

void TransactionDto::setSourceAccount(const QString &sourceAccount)
{
    m_sourceAccount = sourceAccount;
}
quint32 TransactionDto::currencyValue() const
{
    return m_currencyValue;
}

void TransactionDto::setCurrencyValue(const quint32 &currencyValue)
{
    m_currencyValue = currencyValue;
}
QString TransactionDto::destAccount() const
{
    return m_destAccount;
}

void TransactionDto::setDestAccount(const QString &destAccount)
{
    m_destAccount = destAccount;
}
QString TransactionDto::error() const
{
    return m_error;
}

void TransactionDto::setError(const QString &error)
{
    m_error = error;
}









