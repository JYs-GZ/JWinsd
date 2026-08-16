@echo off
title Windows定时关机程序（JWinsd）安装
echo 要安装Windows定时关机程序（JWinsd）吗？按任意键安装，直接关闭窗口以退出。
pause
echo 正在复制文件...
md "%ProgramFiles%\jwinsd" 2>nul
copy "JWSFile\changesstask.vbs" "%ProgramFiles%\jwinsd\"
copy "JWSFile\changesrtask.vbs" "%ProgramFiles%\jwinsd\"
copy "JWSFile\changesltask.vbs" "%ProgramFiles%\jwinsd\"
copy "JWSFile\sds.vbs" "%ProgramFiles%\jwinsd\"
copy "JWSFile\sdl.vbs" "%ProgramFiles%\jwinsd\"
copy "JWSFile\sdr.vbs" "%ProgramFiles%\jwinsd\"
copy "JWSFile\sdl.bat" "%ProgramFiles%\jwinsd\"
copy "JWSFile\uninst.bat" "%ProgramFiles%\jwinsd\"
copy "JWSFile\uninstst.bat" "%ProgramFiles%\jwinsd\"
if "%PROCESSOR_ARCHITECTURE%"=="AMD64" (
	copy "JWSFile\main64.exe" "%ProgramFiles%\jwinsd\"
	md "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Windows定时关机程序-JWinsd" 2>nul
	copy "Windows定时关机程序主控制台.lnk" "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Windows定时关机程序-JWinsd\"
	del /F /Q "Windows 定时关机程序主控制台.lnk"
) else (
	copy "JWSFile\main32.exe" "%ProgramFiles%\jwinsd\"
	md "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Windows定时关机程序-JWinsd" 2>nul
	copy "Windows 定时关机程序主控制台.lnk" "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Windows定时关机程序-JWinsd\"
	del /F /Q "Windows定时关机程序主控制台.lnk"
)
echo 正在导入注册表...
reg import "JWSFile\JWinsd.reg"
echo 正在创建基本任务...
schtasks /create /TN jwinss /xml "JWSFile\jwinss.xml" /F
schtasks /create /TN jwinsr /xml "JWSFile\jwinsr.xml" /F
schtasks /create /TN jwinsl /xml "JWSFile\jwinsl.xml" /F
echo 正在删除临时文件...
rd /S /Q JWSFile
echo 如果没有报错，已完成
echo 以后想打开主控制台，请使用刚才解压出来的快捷方式或开始菜单
pause