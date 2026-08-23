#include<windows.h>
#include<stdio.h>
void changetask(char b){
	printf(" 如果您输入正确，我们会为您打开任务属性，您可以更改时间并对任务进行其它设置。在此期间，请您不要使用鼠标及键盘。设置完毕后，请按右下角“确定”\n");
	system("pause");
	system("md \"%TEMP%\\jwinsd\\\" 2>nul");
	if(b=='S'||b=='s'){
		system("copy /Y \"C:\\Windows\\System32\\Tasks\\jwinss\" \"%TEMP%\\jwinsd\\jwinss.xml\"");//复制原任务xml文件，以便后续创建 
		system("schtasks /delete /TN \"jwinss\" /F");//删除原有任务 
		system("start changesstask.vbs");//进入另一程序完成接下来的操作 
		printf("请稍候...在\"新建任务\"窗口出现前，请不要用鼠标及键盘，不要理会下一行，直到\"新建任务\"窗口出现\n");
		system("pause");
	}else if(b=='R'||b=='r'){
		system("copy /Y \"C:\\Windows\\System32\\Tasks\\jwinsr\" \"%TEMP%\\jwinsd\\jwinsr.xml\"");
		system("schtasks /delete /TN \"jwinsr\" /F");
		system("start changesrtask.vbs");
		printf("请稍候...在\"新建任务\"窗口出现前，请不要用鼠标及键盘，不要理会下一行，直到\"新建任务\"窗口出现\n");
		system("pause");
	}else if(b=='L'||b=='l'){
		system("copy /Y \"C:\\Windows\\System32\\Tasks\\jwinsl\" \"%TEMP%\\jwinsd\\jwinsl.xml\"");
		system("schtasks /delete /TN \"jwinsl\" /F");
		system("start changesltask.vbs");
		printf("请稍候...在\"新建任务\"窗口出现前，请不要用鼠标及键盘，不要理会下一行，直到\"新建任务\"窗口出现\n");
		system("pause");
	}else printf("错误：无效选项\n");
} 
int main(){
	printf("欢迎使用Windows定时关机程序\n");
	char a; //主界面选项 
	while(1){
		SetConsoleTitleA("Windows定时关机程序主控制台-主界面");
		printf("您可以键入以控制\n");
		printf("c -增减、更改计划\nr -删除某些功能以节省磁盘空间\n");
		printf("u -卸载此程序\na -关于\ne-退出\n");
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
			printf(" 所有存在过的文件的功能及编号：(现在存在的文件请以下为准)\n");
			printf("  a=changesstask.vbs:更改定时关机计划\n  b=changesrtask.vbs:更改定时重启计划\n  c=changesltask.vbs:更改定时注销计划\n");
			printf("  main.exe:          主控制台，您不应该删除它\n");
			printf("  d=sdl.bat,sdl.vbs: 执行注销的程序\n  e=sds.vbs:         执行关机的程序\n  f=sdr.vbs:         执行重启的程序\n");
			printf("  uninst.bat,uninstst.bat:卸载程序，您最好不要删除它\n");
			printf(" 这是目前程序所有的运行文件（不包括定时任务文件）：\n");
			system("dir");
			char b;
			while(1){
				printf("输入一个编号以删除它；输入z回主界面(d会同时删除两个文件，d,e,f会同时删除对应任务)\n");
				scanf(" %c",&(b));
				if(b=='a')system("del /F changesstask.vbs");
				else if(b=='b')system("del /F changesrtask.vbs");
				else if(b=='c')system("del /F changesltask.vbs");
				else if(b=='d'){
					system("schtasks /Delete /TN jwinsl /F");
					system("del /F sdl.bat sdl.vbs");
				}
				else if(b=='e'){
					system("schtasks /Delete /TN jwinss /F");
					system("del /F sds.vbs");
				}
				else if(b=='f'){
					system("schtasks /Delete /TN jwinsr /F");
					system("del /F sdr.vbs");
				}else if(b=='z')break;
				else printf("错误：无效选项");
			}
		}else if(a=='u'||a=='U'){
			system("start \"\" \"uninstst.bat\"");
			return 0;
		}else if(a=='a'||a=='A'){
			SetConsoleTitleA("Windows定时关机程序主控制台-关于");
			printf("\n关于：\n Windows定时关机程序(JWinsd)\n 版本  V1.0.0(x64)    JYs\n");
			printf("这是一款可以设置定时关闭、重启Windows或注销(俗称退出登录)账户的软件，使用了C++，vbs，cmd等多种语言，适用于学校等有固定关机时间的场景。可在64位的Windows Vista至Windows11上运行。作者能力尚不足，软件可能还有一些问题及不便之处。所有源代码都已开源在https://gitb/....上，欢迎所有使用者提出宝贵反馈、建议和指导。\n");
			printf("                         JYs\n                      2026.8.3\n\n");
		}else if(a=='e'||a=='E'){return 0;
		}else printf("错误：无效选项\n");
	}
}
