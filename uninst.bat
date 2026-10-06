@echo off
title 卸载Windows定时关机程序
echo 确定要卸载Windows定时关机程序(JWinsd)吗？
echo 按任意键卸载，不想卸载请关闭此窗口
pause
echo 正在删除文件
rd /S /Q "%ProgramFiles%\jwinsd"
rd /S /Q "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Windows定时关机程序-JWinsd"
choice /C YN /M 是否要保留已创建的关闭任务？
if ERRORLEVEL 2 (
	rd /S /Q "%APPDATA%\jwinss"
	schtasks /Delete /TN jwinss /F
	schtasks /Delete /TN jwinsl /F
	schtasks /Delete /TN jwinsr /F
)
echo 正在解除注册
REG DELETE "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\JWinsd" /f
echo 已完成
pause