#include "SubDialog.h"

SubDialog::SubDialog(QObject *parent)
	: QObject(parent){
	emit sendSig();
}

SubDialog::~SubDialog()
{

}
