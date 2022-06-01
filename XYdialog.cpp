#include "XYdialog.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

XYdialog::XYdialog(QWidget* parent = nullptr)
{
	QGridLayout* gridLayout = new QGridLayout;

	QLabel* X = new QLabel("X", this);
	QLabel* Y = new QLabel("Y", this);

	xEdit = new QLineEdit(this);
	yEdit = new QLineEdit(this);

	gridLayout->addWidget(X, 0, 0);
	gridLayout->addWidget(xEdit, 0, 1);
	gridLayout->addWidget(Y, 1, 0);
	gridLayout->addWidget(yEdit, 1, 1);

	QPushButton* okButton = new QPushButton("Ok");
	QPushButton* cancelButton = new QPushButton("Cancel");

	connect(okButton, SIGNAL(clicked()), SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(reject()));

	gridLayout->addWidget(okButton, 3, 0);
	gridLayout->addWidget(cancelButton, 3, 1);

	setLayout(gridLayout);
}

int XYdialog::getX()
{
	int x = xEdit->text().toDouble();
	return x;
}

int XYdialog::getY()
{
	int y = yEdit->text().toDouble();
	return y;
}

