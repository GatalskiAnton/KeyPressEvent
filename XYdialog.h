#pragma once
#include <QWidget>
#include <QDialog>
#include <QLineEdit>

class XYdialog : public QDialog
{
public:
	XYdialog(QWidget* parent );
	int getX();
	int getY();
private:
	QLineEdit* xEdit;
	QLineEdit* yEdit;

};

