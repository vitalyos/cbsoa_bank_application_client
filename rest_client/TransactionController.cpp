#include "TransactionController.hpp"

TransactionController::TransactionController(QObject *parent) : QObject(parent)
{

}

void TransactionController::getAllOrderedbyAmount()
{
    emit requireGetAllOrderedByAmont();
}

void TransactionController::getAllFilteredByIban(const QString &iban)
{
    emit requireGetAllFilteredByIban(iban);
}

void TransactionController::performTransaction(TransactionDto *aTransaction)
{
    emit performTransaction(aTransaction);
}
