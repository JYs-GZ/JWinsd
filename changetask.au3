_Example()
Exit
Func _Example()
	Run("mmc.exe taskschd.msc")
	If $CmdLine[2]=="f" Then ;fast
		Sleep(2000)
	Else
		Sleep(11000)
	EndIf
	WinWaitActive("任务计划程序")
	Send("!a")
	Sleep(500)
	Send("m")
	Sleep(2000)
	Send("!n")
	If $CmdLine[1]=="s" Then
		ClipPut("%APPDATA%\jwinsd\backup\jwinss.xml")
		Send("^v{ENTER}")
	ElseIf $CmdLine[1]=="r" Then
		ClipPut("%APPDATA%\jwinsd\backup\jwinsr.xml")
		Send("^v{ENTER}")
	Else
		ClipPut("%APPDATA%\jwinsd\backup\jwinsl.xml")
		Send("^v{ENTER}")
	EndIf
	Sleep(3500)
	Send("{TAB 9}{RIGHT}")
EndFunc
