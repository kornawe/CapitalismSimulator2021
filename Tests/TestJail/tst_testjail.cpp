#include "tst_testjail.h"
#include "Location/Jail.h"
#include "Banking/Bank.h"
#include "Player/IPlayer.h"
#include "Banking/IAmount.h"
#include "Banking/IAccount.h"

///
/// \brief TestJail::init
/// Setup a new Component Under Test reference before each test case.
/// Instantiate any friend objects necessary.
void TestJail::init() {
    bank = new Bank(0);
    CuT = new Jail(bank);

    startingWealth = 1234567890;
    player = new IPlayer("test", startingWealth);
}

///
/// \brief TestJail::cleanup
/// Always cleanup the Component under Test reference, as well as any
/// friend object references.
void TestJail::cleanup() {
    delete CuT;
    delete bank;
    delete player;
}

///
/// \brief TestJail::shouldReturnTrueWhenPlayerMustPay
/// Verify the return value of LandOn() when a payment is required.
void TestJail::LandOn_shouldReturnTrueWhenPlayerMustPay() {
    // Setup the required payment before the player lands on the Location.
    CuT->SetRequiredPayment(player, 50);
    bool expected = true;

    // Act
    bool actual = CuT->LandOn(player);

    // Assert
    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::shouldReturnFalseWithoutSetPay
/// Verify the return value of LandOn() when payment is not setup.
void TestJail::LandOn_shouldReturnFalseWithoutSetPay() {
    bool expected = false;

    bool actual = CuT->LandOn(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::LandOn_shouldReturnFalseWithFreePassage
/// Verify the return value of LandOn() when payment is free.
void TestJail::LandOn_shouldReturnFalseWithFreePassage() {
    // Setup the required payment to be free
    CuT->SetRequiredPayment(player, 0);
    bool expected = false;

    bool actual = CuT->LandOn(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::LandOn_verifyCanHandleNullptrInput
/// Verify that this method can handle bad input without crashing.
/// We also want to make sure that this method does not specify that an
/// undefined player has a fee to pay when Landing On this Location.
void TestJail::LandOn_verifyCanHandleNullptrInput() {
    bool expected = false;

    bool actual = CuT->LandOn(nullptr);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::RequestExit_shouldReturnFalseWhenPlayerMustPay
/// Verify the return value of RequestExit() when payment is required.
void TestJail::RequestExit_shouldReturnFalseWhenPlayerMustPay() {
    // Setup the required payment
    CuT->SetRequiredPayment(player, 50);
    // make sure the player is on the Location
    CuT->LandOn(player);
    bool expected = false;

    bool actual = CuT->RequestExit(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::RequestExit_shouldReturnTrueWithoutSetPay
/// Verify the return value of RequestExit() when payment is not setup.
void TestJail::RequestExit_shouldReturnTrueWithoutSetPay() {
    bool expected = true;

    bool actual = CuT->RequestExit(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::RequestExit_shouldReturnTrueWithFreePassage
/// Verify the return value of RequestExit() when payment is free.
void TestJail::RequestExit_shouldReturnTrueWithFreePassage() {
    // Setup the required payment to be free
    CuT->SetRequiredPayment(player, 0);
    bool expected = true;

    bool actual = CuT->RequestExit(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::RequestExit_shouldReturnTrueAfterPaymentReceived
/// Verify the return value of RequestExit() after a Player has paid their dues.
void TestJail::RequestExit_shouldReturnTrueAfterPaymentReceived() {
    // Setup the required payment
    CuT->SetRequiredPayment(player, 50);
    bool expected = true;
    CuT->Pay(player, CuT->GetInvoice(player));

    bool actual = CuT->RequestExit(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::RequestExit_verifyCanHandleNullptrInput
/// Verify that this method can handle bad input without crashing.
/// We also want to make sure we get an expected return value. The Jail
/// should not deny an exit request to an undefined player.
void TestJail::RequestExit_verifyCanHandleNullptrInput() {
    bool expected = true;

    bool actual = CuT->RequestExit(nullptr);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::Pay_bankAccountShouldReceivePayment
/// Verify that Payment works as intended.
void TestJail::Pay_bankAccountShouldReceivePayment() {
    IAccount *bankAccount = bank->Account();
    int cash = 50;
    IAmount *amount = new IAmount(cash, nullptr, nullptr);

    // Pay will delete this amount
    CuT->Pay(player, amount);

    int expectedPlayerCash = startingWealth - cash;
    int actualPlayerCash = player->Account()->AvailableWealth();

    int expectedBankCash = cash;
    int actualBankCash = bankAccount->AvailableWealth();

    QCOMPARE(expectedPlayerCash, actualPlayerCash);
    QCOMPARE(expectedBankCash, actualBankCash);
}

///
/// \brief TestJail::Pay_shouldZeroInvoiceAmount
/// Verify that paying the amount due affects the player's balance for this
/// Location.
void TestJail::Pay_shouldZeroInvoiceAmount() {
    int startingCost = 50;
    CuT->SetRequiredPayment(player, startingCost);
    IAmount *initialInvoice = CuT->GetInvoice(player);
    int expected = 0;

    // Pay will delete this invoice
    CuT->Pay(player, initialInvoice);

    IAmount *paidInvoice = CuT->GetInvoice(player);
    int actual = paidInvoice->GetCashAmount();

    delete paidInvoice;
    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::Pay_verifyCanHandleNullptrPlayerInput
/// Verify that this method can handle bad input without crashing.
void TestJail::Pay_verifyCanHandleNullptrPlayerInput() {
    IAmount *amount = new IAmount(0, nullptr, nullptr);
    CuT->Pay(nullptr, amount);
    // If we get here, we pass automatically.
    QVERIFY(true);
}

///
/// \brief TestJail::Pay_verifyCanHandleNullptrAmountInput
/// Verify that this method can handle bad input without crashing.
void TestJail::Pay_verifyCanHandleNullptrAmountInput() {
    CuT->Pay(player, nullptr);
    // If we get here, we pass automatically.
    QVERIFY(true);
}

///
/// \brief TestJail::Pay_negativeAmountShouldNotPayPlayer
/// Verify that a player making a payment with a negative amount doesn't credit
/// their Account.
void TestJail::Pay_negativeAmountShouldNotPayPlayer() {
    player = new IPlayer("test", 0);
    int payment = -100;
    IAmount *amount = new IAmount(payment, nullptr, nullptr);
    int expected = 0;

    CuT->Pay(player, amount);

    int actual = player->Account()->AvailableWealth();

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::Invoice_shouldContainRequiredPayment
/// Verify the Invoice amount based on required payment.
void TestJail::Invoice_shouldContainRequiredPayment() {
    // Setup the required payment
    int expected = 1234567890;
    CuT->SetRequiredPayment(player, expected);

    IAmount *invoice = CuT->GetInvoice(player);

    int actual = invoice->GetCashAmount();

    delete invoice;
    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::Invoice_shouldShowRemainderWhenNotFullyPaid
/// Verify that a player's owed amount updates when they don't pay their full
/// amount due.
void TestJail::Invoice_shouldShowRemainderWhenNotFullyPaid() {
    int initialCost = 100;
    int initialPayment = 20;
    int expected = initialCost - initialPayment;
    CuT->SetRequiredPayment(player, initialCost);
    IAmount *amount = new IAmount(initialPayment, nullptr, nullptr);
    // Pay will delete this amount
    CuT->Pay(player, amount);

    IAmount *invoice = CuT->GetInvoice(player);

    int actual = invoice->GetCashAmount();

    delete invoice;
    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::Invoice_shouldShowNoPaymentDueWithoutSetup
/// Verify that when a payment is not setup, a player's invoice shows no money
/// due.
void TestJail::Invoice_shouldShowNoPaymentDueWithoutSetup() {
    int expected = 0;

    IAmount *invoice = CuT->GetInvoice(player);

    int actual = invoice->GetCashAmount();

    delete invoice;
    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::Invoice_verifyCanHandleNullptrInput
/// Verify that this method can handle bad input without crashing.
/// We also want to verify that the Invoice shows no money owed for a non
/// defined player.
void TestJail::Invoice_verifyCanHandleNullptrInput() {
    int expected = 0;
    IAmount *invoice = CuT->GetInvoice(nullptr);

    int actual = invoice->GetCashAmount();

    delete invoice;
    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::Owner_shouldNotChangeWhenSet
/// Verify that the owner of the Jail cannot change.
void TestJail::Owner_shouldNotChangeWhenSet() {
    // Hold onto the bank's account reference to check later
    IAccount *bankAccount = bank->Account();
    int expected = 50;
    CuT->SetRequiredPayment(player, expected);

    // Act
    CuT->SetOwner(player->Account());

    CuT->Pay(player, CuT->GetInvoice(player));

    // Assert
    // If the "owner" was changed, the player should be paying themselves.
    // If the bank's account has the expected cash, the owner was never changed.
    int actual = bankAccount->AvailableWealth();

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::Owner_verifyCanHandleNullptrInput
/// Verify that this method can handle bad input without crashing.
void TestJail::Owner_verifyCanHandleNullptrInput() {
    CuT->SetOwner(nullptr);
    // If we get here, we pass automatically.
    QVERIFY(true);
}

///
/// \brief TestJail::SetRequiredPayment_shouldStoreBalanceForThatPlayer
/// Verify that the correct ledger entry is created, and invoices can be
/// created from this set payment requirement.
void TestJail::SetRequiredPayment_shouldStoreBalanceForThatPlayer() {
    int expected = 1234567890;

    // Act
    CuT->SetRequiredPayment(player, expected);

    int actual = CuT->GetInvoice(player)->GetCashAmount();

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::SetRequiredPayment_verifyCanHandleNullptrInput
/// Verify that this method can handle bad input without crashing.
void TestJail::SetRequiredPayment_verifyCanHandleNullptrInput() {
    CuT->SetRequiredPayment(nullptr, 0);
    // If we get here, we pass automatically.
    QVERIFY(true);
}

QTEST_APPLESS_MAIN(TestJail)
