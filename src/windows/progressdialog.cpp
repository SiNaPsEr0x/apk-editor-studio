#include "windows/progressdialog.h"
#include "widgets/elidedlabel.h"
#include "base/utils.h"
#include <QBoxLayout>
#include <QProgressBar>

ProgressDialog::ProgressDialog(QWidget *parent) : QDialog(parent)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    primaryLabel = new QLabel(this);
    secondaryLabel = new ElidedLabel(this);

    progressBar = new QProgressBar(this);
    progressBar->setMinimum(0);
    progressBar->setMaximum(0);
    progressBar->setValue(0);
    progressBar->setTextVisible(false);

    auto layout = new QVBoxLayout(this);
    layout->addWidget(primaryLabel);
    layout->addWidget(progressBar);
    layout->addWidget(secondaryLabel);

    adjustSize();
    resize(Utils::scale(400, 0));
}

void ProgressDialog::setProgressMinimum(int minimum)
{
    progressBar->setMinimum(0);
}

void ProgressDialog::setProgressMaximum(int maximum)
{
    progressBar->setMaximum(0);
}

void ProgressDialog::setProgressValue(int value)
{
    progressBar->setValue(0);
}

void ProgressDialog::setPrimaryText(const QString &text)
{
    primaryLabel->setText(text);
}

void ProgressDialog::setSecondaryText(const QString &text)
{
    secondaryLabel->setText(text);
}