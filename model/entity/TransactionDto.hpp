#ifndef TRANSACTIONDTO_HPP
#define TRANSACTIONDTO_HPP

#include <QObject>

class TransactionDto : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString dateTime READ dateTime WRITE setDateTime NOTIFY dateTimeChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY locationChanged)
    Q_PROPERTY(qint32 amount READ amount WRITE setAmount NOTIFY amountChanged)
    Q_PROPERTY(QString sourceAccount READ sourceAccount WRITE setSourceAccount NOTIFY sourceAccountChanged)
    Q_PROPERTY(int currencyValue READ currencyValue WRITE setCurrencyValue NOTIFY currencyValueChanged)
    Q_PROPERTY(QString destAccount READ destAccount WRITE setDestAccount NOTIFY destAccountChanged)
    Q_PROPERTY(QString error READ error WRITE setError NOTIFY errorChanged)
public:
    explicit TransactionDto(QObject *parent = 0);
    int id() const;
    void setId(int id);

    QString dateTime() const;
    void setDateTime(const QString &dateTime);

    QString location() const;
    void setLocation(const QString &location);

    qint32 amount() const;
    void setAmount(const qint32 &amount);

    QString sourceAccount() const;
    void setSourceAccount(const QString &sourceAccount);

    quint32 currencyValue() const;
    void setCurrencyValue(const quint32 &currencyValue);

    QString destAccount() const;
    void setDestAccount(const QString &destAccount);

    QString error() const;
    void setError(const QString &error);

private:
    int m_id;
    QString m_dateTime;
    QString m_location;
    qint32 m_amount;
    QString m_sourceAccount;
    quint32 m_currencyValue;
    QString m_destAccount;
    QString m_error;
signals:
    void idChanged ();
    void dateTimeChanged ();
    void locationChanged ();
    void amountChanged ();
    void sourceAccountChanged ();
    void currencyValueChanged ();
    void destAccountChanged ();
    void errorChanged ();
};

#endif // TRANSACTIONDTO_HPP
