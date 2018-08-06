#include "texteditor.h"

TextEditor::TextEditor(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags){
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
		delete [] buf;	//释放内存
		fclose(fp);	//关闭文件
	}
}

void TextEditor::OnBtnSave(){
	QString filepath=QFileDialog::getSaveFileName(
		this,	//父窗口
		GBK::ToUnicode("保存")	//标题caption
		);
	if(filepath.length()>0){
		QString text=ui.textContent->toPlainText();
		string gbk_text=GBK::FromUnicode(text);
		string gbk_filename=GBK::FromUnicode(filepath);

		//打开文件
		FILE* fp = fopen(gbk_filename.c_str(),"wb");
		fwrite(gbk_text.c_str(),1,gbk_text.length(),fp);
		fclose(fp);
	}
}