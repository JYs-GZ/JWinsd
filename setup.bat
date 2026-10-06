@echo off
setlocal enabledelayedexpansion
cd /d "%~dp0"
for /L %%i IN (0,0,1) DO (
	title Windows定时关机程序（JWinsd）安装脚本
	choice /C AHIE /M "要安装Windows定时关机程序（JWinsd）吗？安装请按I，获取帮助请按H，看关于请按A，退出请按E"
	if ERRORLEVEL 4 (
		exit
	) else if ERRORLEVEL 3 (
		title Windows定时关机程序（JWinsd）安装脚本-安装
		echo 正在复制文件...
		md "%ProgramFiles%\jwinsd\helppho\" 2>nul
		copy "JWSFile\changetask.exe" "%ProgramFiles%\jwinsd\" /Y
		copy "JWSFile\helpmain.html" "%ProgramFiles%\jwinsd\" /Y
		copy "JWSFile\sds.vbs" "%ProgramFiles%\jwinsd\" /Y
		copy "JWSFile\sdl.vbs" "%ProgramFiles%\jwinsd\" /Y
		copy "JWSFile\sdr.vbs" "%ProgramFiles%\jwinsd\" /Y
		copy "JWSFile\sdl.bat" "%ProgramFiles%\jwinsd\" /Y
		copy "JWSFile\uninst.bat" "%ProgramFiles%\jwinsd\" /Y
		copy "JWSFile\uninstst.bat" "%ProgramFiles%\jwinsd\" /Y
		if "%PROCESSOR_ARCHITECTURE%"=="AMD64" (
			copy "JWSFile\main64v1.0.1.exe" "%ProgramFiles%\jwinsd\" /Y
			md "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Windows定时关机程序-JWinsd" 2>nul
			copy "Windows定时关机程序主控制台.lnk" "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Windows定时关机程序-JWinsd\" /Y
			del /F /Q "Windows 定时关机程序主控制台.lnk"
		) else (
			copy "JWSFile\main32v1.0.1.exe" "%ProgramFiles%\jwinsd\" /Y
			md "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Windows定时关机程序-JWinsd" 2>nul
			copy "Windows 定时关机程序主控制台.lnk" "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Windows定时关机程序-JWinsd\" /Y
			del /F /Q "Windows定时关机程序主控制台.lnk"
		)
		echo 正在导入注册表...
		reg import "JWSFile\JWinsd.reg"
		echo 正在检查和创建基本任务...
		set te=0
		( schtasks /query /TN jwinss >nul 2>&1 || schtasks /query /TN jwinsr >nul 2>&1 || schtasks /query /TN jwinsl >nul 2>&1 ) && set "te=1"  ::旧任务存在，te为1
		if "!te!"=="1" (
			choice /C NY /M 似乎已存在JWinsd的关机任务，是否要保留它们？
			if errorlevel 1 if not errorlevel 2 (
				set te=0
			)
		)
		if "!te!"=="0" (  ::旧不存在或不保留
			schtasks /create /TN jwinss /xml "JWSFile\jwinss.xml" /F
			schtasks /create /TN jwinsr /xml "JWSFile\jwinsr.xml" /F
			schtasks /create /TN jwinsl /xml "JWSFile\jwinsl.xml" /F
			md "%APPDATA%\jwinsd\backup\" 2>nul
			copy "JWSFile\jwinss.xml" "%APPDATA%\jwinsd\backup\" /Y
			copy "JWSFile\jwinsr.xml" "%APPDATA%\jwinsd\backup\" /Y
			copy "JWSFile\jwinsl.xml" "%APPDATA%\jwinsd\backup\" /Y
		)
		echo 正在删除临时文件...
		rd /S /Q JWSFile
		echo 如果没有报错，已完成
		echo 以后想打开主控制台，请使用刚才解压出来的快捷方式或开始菜单
	) else if ERRORLEVEL 2 (
		start "" ".\JWSFile\helpmain.html"
	) else if ERRORLEVEL 1 (
		title Windows定时关机程序（JWinsd）安装脚本-关于
		echo ;
		echo Windows定时关机程序（JWinsd）
		echo 版本  V1.0.1    JYs
		echo 这是一款可以设置定时关闭、重启Windows或注销（俗称退出登录）的软件，使用了C++，vbs，html，cmd，autoit等多种语言，适用于学校等有固定关机时间的场景。可在Windows Vista至Windows11上运行。作者能力尚不足，软件可能还有一些问题及不便之处。所有源代码都已开源在https://github.com/JTs-GZ/Jwinsd上，欢迎所有使用者提出宝贵反馈、建议和指导。
		echo ;
	)
)