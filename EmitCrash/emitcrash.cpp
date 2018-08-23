#include "emitcrash.h"

EmitCrash::EmitCrash(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	m_SubDialog=new SubDialog(this);
	m_BtnDialog=new BtnDialog(this);
	connect(m_BtnDialog,SIGNAL(sendSig()),this,SLOT(testSlot()));
}

EmitCrash::~EmitCrash()
{

}
void EmitCrash::testSlot(){

}