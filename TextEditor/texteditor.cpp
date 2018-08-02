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
	//选择要打开的文件
	QString filepath=QFileDialog::getOpenFileName(
		this,	//父窗口
		GBK::ToUnicode("选择文件")	//标题caption
		);
	if(filepath.length()>0){
		qDebug()<<filepath;
		string gbk_name=GBK::FromUnicode(filepath);
		//打开文件，读取内容
		FILE* fp=fopen(gbk_name.c_str(),"rb");
		//文件的大小
		fseek(fp,0,SEEK_END);
		int filesize=ftell(fp);
		//读取内容
		fseek(fp,0,SEEK_SET);	//文件指针回到起点
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