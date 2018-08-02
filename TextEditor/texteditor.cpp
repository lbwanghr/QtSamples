#include "texteditor.h"

TextEditor::TextEditor(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags){
	ui.setupUi(this);
	connect(ui.btnOpen,SIGNAL(clicked()),this,SLOT(OnBtnOpen()));
	connect(ui.btnSave,SIGNAL(clicked()),this,SLOT(OnBtnSave()));
}

TextEditor::~TextEditor(){

}

void TextEditor::OnBtnOpen(){
	//ѡ��Ҫ�򿪵��ļ�
	QString filepath=QFileDialog::getOpenFileName(
		this,	//������
		GBK::ToUnicode("ѡ���ļ�")	//����caption
		);
	if(filepath.length()>0){
		qDebug()<<filepath;
		string gbk_name=GBK::FromUnicode(filepath);
		//���ļ�����ȡ����
		FILE* fp=fopen(gbk_name.c_str(),"rb");
		//�ļ��Ĵ�С
		fseek(fp,0,SEEK_END);
		int filesize=ftell(fp);
		//��ȡ����
		fseek(fp,0,SEEK_SET);	//�ļ�ָ��ص����
		char* buf=new char[filesize+1];
		int n=fread(buf,1,filesize,fp);
		if(n>0){
			buf[n]=0;
			ui.textContent->setPlainText(GBK::ToUnicode(buf));
		}
		fclose(fp);
	}
}

void TextEditor::OnBtnSave(){

}