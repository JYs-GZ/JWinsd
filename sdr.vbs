set ws=createobject("wscript.shell")
ws.run "shutdown /r /t 120"
WScript.sleep 1500
ws.AppActivate "即将注销你的登录"
ws.AppActivate "即将注销你的登录"
ws.sendkeys "{ENTER}"
dim c
c=msgbox("Windows将在2分钟后重启"& vbCrLf &"不想重启请按“取消”",1+32,"Windows定时关机程序")
If c=2 Then
ws.run "shutdown /a"
c=msgbox("如果有系统提示，则重启已取消"& vbCrLf &"如果没有请按Windows键加R键，输入“shutdown /a”并回车",0+64,"Windows定时关机程序")
End If