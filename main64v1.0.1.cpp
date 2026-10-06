#include<windows.h>
#include<stdio.h>
void changetask(char b){
	char c='n'; //打开mmc后只等2秒 
	printf(" 如果您输入正确，我们会为您打开任务属性，您可以更改时间并对任务进行其它设置。在此期间，请您不要使用鼠标及键盘。设置完毕后，请务必点右下角“确定”\n");
	system("pause");
	while(1){
		if(b=='S'||b=='s'){
			system("copy /Y \"C:\\Windows\\System32\\Tasks\\jwinss\" \"%APPDATA%\\jwinsd\\backup\\jwinss.xml\" >nul 2>&1");//复制原任务xml文件，以便后续创建 
			system("schtasks /delete /TN \"jwinss\" /F >nul 2>&1");//删除原有任务 
			if(c=='n')system("start changetask.exe s f");//进入另一程序完成接下来的操作 
			else system("start changetask.exe s s");
			printf("请稍候...在\"新建任务\"窗口出现前，请不要用鼠标及键盘，不要理会下一行，直到\"新建任务\"窗口出现\n");
			system("pause");
			FILE *fp=fopen("C:\\Windows\\System32\\Tasks\\jwinss","r");
			if(fp == NULL){
				printf("任务似乎不存在，请重新设置。您的“任务计划程序”打开是否很慢?是请输入y,不是请输入n。稍后我们会重新为您打开它\n");
				scanf(" %c",&c);
				continue;
			}else{
				fclose(fp);
				system("copy /Y \"C:\\Windows\\System32\\Tasks\\jwinss\" \"%APPDATA%\\jwinsd\\backup\\jwinss.xml\" >nul 2>&1");
				return;
			}
		}else if(b=='R'||b=='r'){
			system("copy /Y \"C:\\Windows\\System32\\Tasks\\jwinsr\" \"%APPDATA%\\jwinsd\\backup\\jwinsr.xml\" >nul 2>&1");
			system("schtasks /delete /TN \"jwinsr\" /F >nul 2>&1");
			if(c=='n')system("start changetask.exe r f");
			else system("start changetask.exe r s");
			printf("请稍候...在\"新建任务\"窗口出现前，请不要用鼠标及键盘，不要理会下一行，直到\"新建任务\"窗口出现\n");
			system("pause");
			FILE* fp=fopen("C:\\Windows\\System32\\Tasks\\jwinsr","r");
			if(fp == NULL){
				printf("任务似乎不存在，请重新设置。您的“任务计划程序”打开是否很慢?是请输入y,不是请输入n。稍后我们会重新为您打开它\n");
				scanf(" %c",&c);
				continue;
			}else{
				fclose(fp);
				system("copy /Y \"C:\\Windows\\System32\\Tasks\\jwinsr\" \"%APPDATA%\\jwinsd\\backup\\jwinsr.xml\" >nul 2>&1");
				return;
			}
		}else if(b=='L'||b=='l'){
			system("copy /Y \"C:\\Windows\\System32\\Tasks\\jwinsl\" \"%APPDATA%\\jwinsd\\backup\\jwinsl.xml\" >nul 2>&1");
			system("schtasks /delete /TN \"jwinsl\" /F >nul 2>&1");
			if(c=='n')system("start changetask.exe l f");
			else system("start changetask.exe l s");
			printf("请稍候...在\"新建任务\"窗口出现前，请不要用鼠标及键盘，不要理会下一行，直到\"新建任务\"窗口出现\n");
			system("pause");
			FILE* fp=fopen("C:\\Windows\\System32\\Tasks\\jwinsl","r");
			if(fp == NULL){
				printf("任务似乎不存在，请重新设置。您的“任务计划程序”打开是否很慢?是请输入y,不是请输入n。稍后我们会重新为您打开它\n");
				scanf(" %c",&c);
				continue;
			}else{
				fclose(fp);
				system("copy /Y \"C:\\Windows\\System32\\Tasks\\jwinsl\" \"%APPDATA%\\jwinsd\\backup\\jwinsl.xml\" >nul 2>&1");
				return;
			}
		}else{
			printf("错误：无效选项\n");
			return;
		}
	}
} 
int main(){
	printf("欢迎使用Windows定时关机程序\n");
	char a; //主界面选项 
	while(1){
		SetConsoleTitleA("Windows定时关机程序主控制台-主界面");
		printf("您可以键入以控制\n");
		printf("c -增减、更改、查看计划\nr -删除某些功能以节省磁盘空间\n");
		printf("u -卸载此程序\nh -查看帮助文件\nb -清屏\na -关于\ne-退出\n");
		scanf(" %c",&(a)); //"%c"前的空格用于跳过换行输入，没有它，输入会有问题 
		if(a=='c'||a=='C'){
			SetConsoleTitleA("Windows定时关机程序主控制台-更改计划");
			printf(" 您可以键入以控制\n");
			printf(" S -关机任务   R -重启任务   L -注销任务\n E -回主界面\n");
			char b;
			scanf(" %c",&(b)); //二级界面选项 
			if(b!='E'&&b!='e')changetask(b);
		}else if(a=='r'||a=='R'){
			SetConsoleTitleA("Windows定时关机程序主控制台-删除文件");
			printf(" 所有存在过的文件的功能及编号：(现在存在的文件请以dir为准)\n");
			printf("  changetask.exe:    更改定时关闭计划\n");
			printf("  a=helpmain.html,helppho:帮助文件\n"); 
			printf("  main64v1.0.1.exe:  主控制台，您不应该删除它\n");
			printf("  d=sdl.bat,sdl.vbs: 执行注销的程序\n  e=sds.vbs:         执行关机的程序\n  f=sdr.vbs:         执行重启的程序\n");
			printf("  uninst.bat,uninstst.bat:卸载程序，您最好不要删除它们\n");
			printf(" 这是目前程序所有的运行文件（不包括定时任务文件）：\n");
			system("dir");
			char b;
			while(1){
				printf("输入一个编号以删除它；输入z回主界面(d,g会同时删除两个文件，d,e,f会同时删除对应任务)\n");
				scanf(" %c",&(b));
				if(b=='a')system("del /F helpmain.html && rd /S /Q \".\\helppho\"");
				else if(b=='d'){
					system("schtasks /Delete /TN jwinsl /F");
					system("del /F sdl.bat sdl.vbs && del /F %APPDATA%\\jwinsd\\backup\\jwinsl.xml");
				}
				else if(b=='e'){
					system("schtasks /Delete /TN jwinss /F");
					system("del /F sds.vbs && del /F %APPDATA%\\jwinsd\\backup\\jwinss.xml");
				}
				else if(b=='f'){
					system("schtasks /Delete /TN jwinsr /F");
					system("del /F sdr.vbs && del /F %APPDATA%\\jwinsd\\backup\\jwinsr.xml");
				}else if(b=='z')break;
				else printf("错误：无效选项\n");
			}
		}else if(a=='u'||a=='U'){
			system("start \"\" \"uninstst.bat\"");
			return 0;
		}else if(a=='h'||a=='H')system("start \"\" \"helpmain.html\"");
		else if(a=='a'||a=='A'){
			SetConsoleTitleA("Windows定时关机程序主控制台-关于");
			printf("\n关于：\n Windows定时关机程序(JWinsd)\n 版本  V1.0.1(x64)    JYs\n");
			printf("这是一款可以设置定时关闭、重启Windows或注销(俗称退出登录)的软件，使用了C++，vbs，html，cmd，autoit等多种语言，适用于学校等有固定关机时间的场景。可在64位的Windows Vista至Windows11上运行。作者能力尚不足，软件可能还有一些问题及不便之处。所有源代码都已开源在https://github.com/JTs-GZ/Jwinsd上，欢迎所有使用者提出宝贵反馈、建议和指导。\n");
			printf("                            JYs\n                        2026.10.3\n\n");
		}else if(a=='e'||a=='E'){return 0;
		}else if(a=='b'||a=='B')system("CLS");
		else printf("错误：无效选项\n");
	}
}
