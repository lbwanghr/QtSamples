# QtSamples
`在这里放一些常见的Qt功能实现，现在开发的环境是Qt4.8.3+VS2010+VisualAssistant`
- 文本编辑器
	- 打开与保存文件
	- Qt下正确显示中文字符
- 模式与非模式对话框
	- 以父窗口成员变量形式实现非模式对话框 `dlg->show()`
	- 仅在使用时才实例化对象实现模式对话框 `dlg.exec()`
	- 定义对话框类的public成员变量以在父窗口获取对话框中的信息
- 计时器
	- 非模态计时器窗口，使用QTime类对象currentTime与toString函数